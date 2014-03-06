#ifndef SCENE_H
#define SCENE_H

#include "Vect.hpp"
#include "ImgWriter.hpp"
#include "Surface.hpp"
#include "Light.hpp"
#include "Camera.hpp"
#include <vector>

class Scene{
    public:
        Scene();

        void addSurface(Surface* s);
        void addLight(Light* l);
        void addCamera(Camera* c);

        void render(string filepath);

        Color trace(Ray r);
    protected:
        Camera* cam;
        ImgWriter* film;
        vector<Surface*> objects;
        vector<Light*> lights;
};

#endif
