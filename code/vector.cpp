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

Vector vector(){
    Vector vec = {};
    return vec;
}

Vector vector(float x, float y, float z){
    Vector vec = {};
    vec.x = x;
    vec.y = y;
    vec.z = z;

    return vec;
}

inline Vector add(Vector vec1, Vector vec2){
    Vector vec = vector();
    vec.x = vec1.x + vec2.x;
    vec.y = vec1.y + vec2.y;
    vec.z = vec1.z + vec2.z;

    return vec;
}

inline Vector subtract(Vector vec1, Vector vec2){
    Vector vec = vector();
    vec.x = vec1.x - vec2.x;
    vec.y = vec1.y - vec2.y;
    vec.z = vec1.z - vec2.z;

    return vec;
}

inline Vector divide(Vector vec1, Vector vec2){
    Vector vec = vector();
    vec.x = vec1.x / vec2.x;
    vec.y = vec1.y / vec2.y;
    vec.z = vec1.z / vec2.z;

    return vec;
}

inline Vector multiply(Vector vec1, Vector vec2){
    Vector vec = vector();
    vec.x = vec1.x * vec2.x;
    vec.y = vec1.y * vec2.y;
    vec.z = vec1.z * vec2.z;

    return vec;
}

inline Vector divide(Vector vec1, float t){
    Vector vec = vector();
    vec.x = vec1.x / t;
    vec.y = vec1.y / t;
    vec.z = vec1.z / t;

    return vec;
}

inline Vector multiply(Vector vec1, float t){
    Vector vec = vector();
    vec.x = vec1.x * t;
    vec.y = vec1.y * t;
    vec.z = vec1.z * t;

    return vec;
}

inline float squared_length(Vector vec){
    return vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;
}

inline float length(Vector vec){
    return sqrt(squared_length(vec));
}

inline Vector makeUnitVector(Vector source){
    float vecLength = length(source);

    Vector vec = {};
    vec.x = source.x / vecLength;
    vec.y = source.y / vecLength;
    vec.z = source.z / vecLength;

    return vec;
}

inline float dot(Vector vec1, Vector vec2){
    return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
}

inline Vector cross(Vector vec1, Vector vec2){
    
    float x = vec1.y * vec2.z - vec1.z * vec2.y;
    float y = -(vec1.x * vec2.z - vec1.z * vec2.x);
    float z = vec1.x * vec2.y - vec1.y * vec2.x;
    Vector vec = vector(x, y, z);

    return vec;
}

#endif