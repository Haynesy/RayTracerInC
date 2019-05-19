#ifndef VECTOR
#define VECTOR

#include "math.h"

struct Vector {
    union {
        float elements[3];
        struct {
            float x;
            float y;
            float z;
        };
    };
};

Vector* vector(){
    Vector* vec = {};
    return vec;
}

Vector* vector(float x, float y, float z){
    Vector* vec = {};
    vec->x = x;
    vec->y = y;
    vec->z = z;

    return vec;
}

Vector* add(Vector* vec1, Vector* vec2){
    Vector* vec = {};
    vec->x = vec1->x + vec2->x;
    vec->y = vec1->y + vec2->y;
    vec->z = vec1->z + vec2->z;

    return vec;
}

Vector* subtract(Vector* vec1, Vector* vec2){
    Vector* vec = {};
    vec->x = vec1->x - vec2->x;
    vec->y = vec1->y - vec2->y;
    vec->z = vec1->z - vec2->z;

    return vec;
}

Vector* divide(Vector* vec1, Vector* vec2){
    Vector* vec = {};
    vec->x = vec1->x / vec2->x;
    vec->y = vec1->y / vec2->y;
    vec->z = vec1->z / vec2->z;

    return vec;
}

Vector* multiply(Vector* vec1, Vector* vec2){
    Vector* vec = {};
    vec->x = vec1->x * vec2->x;
    vec->y = vec1->y * vec2->y;
    vec->z = vec1->z * vec2->z;

    return vec;
}

Vector* divide(Vector* vec1, float t){
    Vector* vec = {};
    vec->x = vec1->x / t;
    vec->y = vec1->y / t;
    vec->z = vec1->z / t;

    return vec;
}

Vector* multiply(Vector* vec1, float t){
    Vector* vec = {};
    vec->x = vec1->x * t;
    vec->y = vec1->y * t;
    vec->z = vec1->z * t;

    return vec;
}

float squared_length(Vector* vec){
    return vec->x * vec->x + vec->y * vec->y + vec->z * vec->z;
}

float length(Vector* vec){
    return sqrt(squared_length(vec));
}

Vector* make_unit_vector(Vector* source){
    float vecLength = length(source);

    Vector* vec = {};
    vec->x = source->x / vecLength;
    vec->y = source->y / vecLength;
    vec->z = source->z / vecLength;

    return vec;
}

#endif