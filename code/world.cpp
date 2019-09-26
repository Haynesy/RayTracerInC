#ifndef WORLD_CPP
#define WORLD_CPP

#include <assert.h>
#include "ray.cpp"
#include "hit_record.cpp"
#include "sphere.cpp"

struct World {
    Sphere* list; // TODO: Find out how to do generics in C
    int listSize;
};

HitResult hit(World* world, Ray* ray, float tMin, float tMax){
    HitResult finalResult = {};
    assert(finalResult.isHit == false);
    
    float closestSoFar = tMax;
    for(int i = 0; i < world->listSize; i++){
        HitResult result = hit(&world->list[i], ray, tMin, closestSoFar);
        if(result.isHit){    
            finalResult.isHit = true;
            closestSoFar = result.record.t;
            finalResult.record = result.record;
        }
    }
    return finalResult;
}

#endif