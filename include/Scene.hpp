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
        friend ostream& operator<<(ostream& lhs, Scene& s);
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
        vector<Surface*> surfaces;
        vector<Light*> lights;
        Color ambientColor;
        Color backgroundColor;
        static const scalar SHADOW_BIAS = 1e-5;
        int maxReflectionDepth;
};


ostream& operator<<(ostream& lhs, Scene& s);

#endif
