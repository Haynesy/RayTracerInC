#ifndef IMAGE_PPM
#define IMAGE_PPM


#include <iostream>
#include "vector.cpp"
#include "ray.cpp"

using namespace std;

struct Render {
    Vector lowerLeftCorner;
    Vector horizontal;
    Vector vertical;
    Vector origin;
};

Vector WHITE = vector(1.0f, 1.0f, 1.0f);
Vector RED = vector(1.0f, 0.0f, 0.0f);
Vector LIGHT_BLUE = vector(0.5f, 0.7f, 1.0f);
Render render = {};
    
void writePpmHeader(int width, int height){
    cout << "P3\n" << width << " " << height << "\n255\n";    
}

void writePpmPixel(Vector vec){
    int red = int(255.99 * vec.x);
    int green = int(255.99 * vec.y);
    int blue = int(255.99 * vec.z);
    cout << red << " " << green << " " << blue << "\n";
}

float hitSphere(Vector center, float radius, Ray ray){
    Vector originCenter = subtract(ray.origin, center);
    float a = dot(ray.direction, ray.direction);
    float b = 2.0f * dot(originCenter, ray.direction);
    float c = dot(originCenter, originCenter) - radius * radius;
    float discriminant = b * b - 4 * a * c;
    if(discriminant < 0){
        return -1.0f;
    } else {
        return (-b - sqrtf(discriminant)) / (2.0f * a); 
    }
}

inline Vector color(Ray ray){
    float t = hitSphere(vector(0.0f, 0.0f, -1.0f), 0.5, ray);
    if(t > 0.0)
    {
        Vector normal = makeUnitVector(subtract(pointAtParameter(ray, t), vector(0.0f, 0.0f, -1.0f)));
        return multiply(vector(normal.x + 1, normal.y + 1, normal.z + 1), 0.5f);
    }
    Vector unitDirection = makeUnitVector(ray.direction);
    t = 0.5f * (unitDirection.y + 1.0f);
    Vector backgroundWhite = multiply(WHITE, 1.0f - t);
    Vector backgrountBlue = multiply(LIGHT_BLUE, t);
    return add(backgroundWhite, backgrountBlue);
}

inline Vector rayPosition(float u, float v){
    Vector horizontal = multiply(render.horizontal, u);
    Vector vertical = multiply(render.vertical, v);
    Vector position = add(horizontal, vertical);
    Vector normalizedPosition = add(render.lowerLeftCorner, position);
    return normalizedPosition;
}

void writePpmFile(int width, int height){

    writePpmHeader(width, height);

    render.lowerLeftCorner = vector(-2.0f, -1.0f, -1.0f);
    render.horizontal = vector(4.0f, 0.0f, 0.0f);
    render.vertical = vector(0.0f, 2.0f, 0.0f);
    render.origin = vector(0.0f, 0.0f, 0.0f);

    //Render render = {};
    for(int y = height - 1; y >= 0; y--){
        for(int x = 0; x < width; x++){
            
            float u = float(x) / float(width);
            float v = float(y) / float(height);

            Vector uvPosition = rayPosition(u, v);
            
            Ray rayPosition = ray(render.origin, uvPosition);
            Vector clr = color(rayPosition);
            
            writePpmPixel(clr);
        }
    }
}

#endif