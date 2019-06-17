#ifndef HITABLE_LIST_CPP
#define HITABLE_LIST_CPP

#include "ray.cpp"
#include "hit_record.cpp"
#include "sphere.cpp"

struct HitableList {
    Sphere** list; // TODO: Find out how to do generics in C
    int size;
};

bool hit(HitableList objectList, Ray ray, float tMin, float tMax, HitRecord hitRecord){
    HitRecord temp = {};
    bool hitAnything = false;
    double closestSoFar = tMax;
    for(int i = 0; i < objectList.size; i++){
        if(hit(*objectList.list[i], ray, tMin, closestSoFar, temp)){
            hitAnything = true;
            closestSoFar = temp.t;
            hitRecord = temp;
        }
    }
    return hitAnything;
}

#endif