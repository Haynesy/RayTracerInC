#ifndef SPHERE_CPP
#define SPHERE_CPP

#include "ray.cpp"
#include "vector.cpp"
#include "hit_record.cpp"

struct Sphere {
    Vector center;
    float radius;
};

Sphere sphere(Vector center, float radius){
    Sphere s = {};
    s.center = center;
    s.radius = radius;
    return s;
}

bool hit(Sphere sphere, Ray ray, float tMin, float tMax, HitRecord& hitRecord){
    Vector originCenter = subtract(ray.origin, sphere.center);
    float a = dot(ray.direction, ray.direction);
    float b = 2.0f * dot(originCenter, ray.direction);
    float c = dot(originCenter, originCenter) - sphere.radius * sphere.radius;
    float discriminant = b * b - 4 * a * c;
    if(discriminant < 0){
        float temp = (-b - sqrtf(b*b-a*c)) / a;
        if(temp < tMax && temp > tMin){
            hitRecord.t = temp;
            hitRecord.p = pointAtParameter(ray, hitRecord.t);
            hitRecord.normal = divide(subtract(hitRecord.p, sphere.center), sphere.radius);
            return true;
        }
        temp = (-b + sqrtf(b*b-a*c)) / a;
        if(temp < tMax && temp > tMin){
            hitRecord.t = temp;
            hitRecord.p = pointAtParameter(ray, hitRecord.t);
            hitRecord.normal = divide(subtract(hitRecord.p, sphere.center), sphere.radius);
            return true;
        }
    } 
    return false;
}

#endif