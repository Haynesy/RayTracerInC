#ifndef IMAGE_PPM
#define IMAGE_PPM

#include <limits>
#include <assert.h>
#include "render.cpp"
#include "vector.cpp"
#include "ray.cpp"
#include "world.cpp"

using namespace std;

Vector WHITE = createVector(1.0f, 1.0f, 1.0f);
Vector LIGHT_BLUE = createVector(0.5f, 0.7f, 1.0f);

float FLOAT_MAX = numeric_limits<float>::max();

inline Vector background(Ray* ray){
    Vector unitDirection = makeUnitVector(&ray->direction);
    float t = 0.5f * (unitDirection.y + 1.0f);
    Vector whiteMix = multiply(&WHITE, 1.0f - t);
    Vector blueMix = multiply(&LIGHT_BLUE, t);
    return add(&whiteMix, &blueMix);
}

inline Vector rayPosition(Render *render, float u, float v){
    Vector horizontal = multiply(&render->horizontal, u);
    Vector vertical = multiply(&render->vertical, v);
    Vector position = add(&horizontal, &vertical);
    Vector normalizedPosition = add(&render->lowerLeftCorner, &position);
    return normalizedPosition;
}

inline Pixel color(Ray* ray, World* world){
    HitResult result = hit(world, ray, 0.0, FLOAT_MAX);
    if(result.isHit){
        
        Vector normal = result.record.normal;
        print(normal);
        Vector colorNormal = createVector(normal.x + 1, normal.y + 1, normal.z + 1);
        Vector reducedColorNormal = multiply(&colorNormal, 0.5f);
        assert(reducedColorNormal.x <= 1.0f && reducedColorNormal.x >= 0.0f);
        assert(reducedColorNormal.y <= 1.0f && reducedColorNormal.y >= 0.0f);
        assert(reducedColorNormal.z <= 1.0f && reducedColorNormal.z >= 0.0f);
        return createPixel(&reducedColorNormal);
    } else {
        Vector bg = background(ray);
        return createPixel(&bg);
    }
}

void run(Render *render){

    Sphere smallSphere = createSphere(createVector(0.0f, 0.0f, -1.0f), 0.5f);
    Sphere largeSphere = createSphere(createVector(0.0f, -100.5f, -1.0f), 100.0f);

    World world = {};
	Sphere spheres[2] = {};

    spheres[0] = smallSphere;
    spheres[1] = largeSphere;
    world.list = spheres;
    world.listSize = 2;

    for (long y = render->height - 1; y >= 0; y--) {
        for (long x = 0; x < render->width; x++) {

            float u = float(x) / float(render->width);
            float v = float(y) / float(render->height);

            Vector uvPosition = rayPosition(render, u, v);

            Ray ray = createRay(&render->origin, &uvPosition);
            Pixel pixel = color(&ray, &world);
             
            addPixel(render, x, y, &pixel);
        }
    }
}

#endif