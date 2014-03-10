#include "Scene.hpp"
#include <float.h>
#include <math.h>

Scene::Scene(Color ambientColor, Color backgroundColor, int maxReflectionDepth){
    this->cam=NULL;
    this->ambientColor=ambientColor;
    this->backgroundColor=backgroundColor;
    this->maxReflectionDepth=maxReflectionDepth;
}

void Scene::addSurface(Surface* s){
    this->objects.push_back(s);
}

void Scene::addLight(Light* l){
    this->lights.push_back(l);
}

void Scene::addCamera(Camera* c){
    this->cam=c;
    this->film = new ImgWriter(this->cam->getImgWidth(),this->cam->getImgHeight());
}

void Scene::render(string filepath){
    if (this->cam==NULL){
        cout << "Render attempted without initializing with camera." << endl;
        exit(-1);
    }

    int size = this->cam->getImgHeight()*this->cam->getImgWidth();
    int inc = size/100;

    cout << "0";
    for (int i = 0; i < 96; i++){
        cout << "=";
    }
    cout << "100%" << endl;
    

    for (int j = 0; j < this->cam->getImgHeight(); j++){
        for (int i = 0; i < this->cam->getImgWidth(); i++){
            //TODO: Anti aliasing code will go here if we get to it
            //In this, we will simply throw more rays in some sort 
            //of loop, then average the colors.
            Ray r = this->cam->getRay(i,j);
            this->film->setPixel(i,j,trace(r,this->maxReflectionDepth));

            //Progress Bar
            if ((j*this->cam->getImgWidth()+i)%inc==0){
                cout << "." << flush;
            }
        }
    }
    this->film->write(filepath);
}

Color Scene::trace(Ray ray, int depth){
    Surface* surf = this->getEarliestIntersection(ray);
    if (surf){
        Vect pos = surf->getIntersection(ray);
        Vect e = normalized(ray.getPos() - pos);
        Vect n = surf->getNormal(ray);
        Vect refl = 2*(e*n)*n-e;
        Color reflection = depth==0?Color(0,0,0):trace(Ray(pos,refl),depth-1)*surf->getCr();
        Color out = this->ambientColor + reflection;
        for (vector<Light*>::iterator light = lights.begin(); light != lights.end(); light++){
            Vect l = (*light)->getLightVector(pos);
            Ray lightRay(pos,l);
            Surface* shad = this->getEarliestIntersection(lightRay);
            if (!(shad && shad->getDistAlongRay(lightRay) <= (*light)->getDist(pos))){
                Vect r= 2*(l*n)*n-l;
                Color diffuse = surf->getCd()*(*light)->getCl()*max(0.0,n*l);
                Color specular = surf->getCs()*(*light)->getCl()*pow(max(0.0,e*r),surf->getP());
                out += diffuse + specular;
            }
        }
        return out;
    }else{
        return this->backgroundColor;
    }
}

Surface* Scene::getEarliestIntersection(Ray r){
    scalar minVal = DBL_MAX;
    Surface* out = NULL;
    for (vector<Surface*>::iterator i = objects.begin(); i != objects.end(); i++){
        scalar dist = (*i)->getDistAlongRay(r);
        if (dist!=-1 && dist < minVal && dist > SHADOW_BIAS){
            minVal=dist;
            out = (*i);
        }
    }
    return out;
}
