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

    for (int j = 0; j < this->cam->getImgHeight(); j++){
        for (int i = 0; i < this->cam->getImgWidth(); i++){
            //TODO: Anti aliasing code will go here if we get to it
            //In this, we will simply throw more rays in some sort 
            //of loop, then average the colors.
            Ray r = this->cam->getRay(i,j);
            this->film->setPixel(i,j,trace(r,this->maxReflectionDepth));
        }
    }
    this->film->write(filepath);
}

Color Scene::trace(Ray ray, int depth){
    Surface* surf = this->getEarliestIntersection(ray);
    if (surf){
        Color out = this->ambientColor;
        for (vector<Light*>::iterator light = lights.begin(); light != lights.end(); light++){
            Vect pos = surf->getIntersection(ray);
            Vect l = (*light)->getLightVector(pos);
            if (!getEarliestIntersection(Ray(pos,l))){
                Vect n = surf->getNormal(ray);
                Vect r= 2*(l*n)*n-l;
                Vect e = normalized(ray.getPos() - pos);
                Color diffuse = surf->getCd()*(*light)->getCl()*max(0.0,n*l);
                Color specular = surf->getCs()*(*light)->getCl()*pow(max(0.0,e*r),surf->getP());
                Color reflection = depth==0?Color(0,0,0):trace(Ray(pos,r),depth-1)*surf->getCr();
                out += diffuse + specular + reflection;
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
