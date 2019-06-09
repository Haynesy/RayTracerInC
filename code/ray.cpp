#ifndef RAY_CPP
#define RAY_CPP

#include "vector.cpp"

/*
    Ray is defined as p(t) = A + t * B
    A = Ray origin
    B = Ray direction
 */

struct Ray {
    Vector origin;
    Vector direction;
};

Ray ray(Vector origin, Vector direction){
    Ray ray = {};
    ray.origin = origin;
    ray.direction = direction;
    return ray;
}

inline Vector pointAtParameter(Ray ray, float t){
    Vector position = multiply(ray.direction, t);
    return add(ray.origin, position);
}

#endif