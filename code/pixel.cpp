#ifndef PIXEL_CPP
#define PIXEL_CPP

#include <assert.h>
#include "vector.cpp"

struct Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

Pixel createPixel(Vector *vector){
    Pixel pixel = {};
    static double maxVal = 255.99;

    assert(vector->x <= 1.0f && vector->x >= 0.0f);
    assert(vector->y <= 1.0f && vector->y >= 0.0f);
    assert(vector->z <= 1.0f && vector->z >= 0.0f);

    pixel.red =  char(maxVal * vector->x);
    pixel.green = char(maxVal * vector->y);
    pixel.blue = char(maxVal * vector->z);

    return pixel;
}

#endif