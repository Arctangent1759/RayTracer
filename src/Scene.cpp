#include "Scene.hpp"

Scene::Scene(Vect eye, Vect ul, Vect ur, Vect ll, Vect lr, int imgWidth, int imgHeight){
    this->init(eye, ul, ur, ll, lr, imgWidth, imgHeight);
}

void Scene::init(Vect eye, Vect ul, Vect ur, Vect ll, Vect lr, int imgWidth, int imgHeight){
    this->eye=eye;
    this->ul=ul;
    this->ur=ur;
    this->ll=ll;
    this->lr=lr;
    this->imgWidth=imgWidth;
    this->imgHeight=imgHeight;
} 

void Scene::render(string filepath){
}
