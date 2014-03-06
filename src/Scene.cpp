#include "Scene.hpp"

Scene::Scene(){this->cam=NULL;}

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
            Ray r = this->cam->getRay(i,j);
            this->film->setPixel(i,j,trace(r));
        }
    }
    this->film->write(filepath);
}

Color Scene::trace(Ray r){
    for (vector<Surface*>::iterator i = objects.begin(); i != objects.end(); i++){
        if ((*i)->isIntersected(r)){
            return (*i)->getColor(r,this);
        }
    }
    return Color(0.0,0.0,0.0);
}
