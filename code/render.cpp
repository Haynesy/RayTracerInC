#ifndef RENDER_CPP
#define RENDER_CPP

#include <iostream>
#include "vector.cpp"
#include "pixel.cpp"

struct Render {
    Vector lowerLeftCorner;
    Vector horizontal;
    Vector vertical;
    Vector origin;
    Pixel *pixels;
    long width;
    long height;
};

Render* createRender(unsigned int width, unsigned int height){
    Render *render = (Render *) malloc(sizeof(Render));
    render->pixels = (Pixel *) malloc(sizeof(Pixel) * width * height);
    
    render->lowerLeftCorner = createVector(-2.0f, -1.0f, -1.0f);
    render->horizontal = createVector(4.0f, 0.0f, 0.0f);
    render->vertical = createVector(0.0f, 2.0f, 0.0f);
    render->origin = createVector(0.0f, 0.0f, 0.0f);
    render->width = width;
    render->height = height;

    return render;
}

void deleteRender(Render *render){
    free(render->pixels);
    free(render);
}

inline void addPixel(Render *render, unsigned int x, unsigned int y, Pixel* pixel){
    long index = (y * render->height) + x;
    render->pixels[index].red = pixel->red;
    render->pixels[index].green = pixel->green;
    render->pixels[index].blue = pixel->blue;
}

#endif