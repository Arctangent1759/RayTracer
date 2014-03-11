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
        Scene(Color ambientColor, Color backgroundColor, int maxReflectionDepth);

        void addSurface(Surface* s);
        void addLight(Light* l);
        void addCamera(Camera* c);

        void render(string filepath);
    protected:
        Color trace(Ray r, int depth);
        Surface* getEarliestIntersection(Ray r);
        Camera* cam;
        ImgWriter* film;
        vector<Surface*> objects;
        vector<Light*> lights;
        Color ambientColor;
        Color backgroundColor;
        static const scalar SHADOW_BIAS = 0.01;
        int maxReflectionDepth;
};

#endif
