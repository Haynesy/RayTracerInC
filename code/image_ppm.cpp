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
Vector LIGHT_BLUE = vector(0.5f, 0.7f, 1.0f);
Render render = {};
    
void writePpmHeader(int width, int height){
    cout << "P3\n" << width << " " << height << "\n255\n";    
}

void writePpmPixel(int red, int green, int blue){
    cout << red << " " << green << " " << blue << "\n";
}

inline int asRed(Vector vec){
    return int(255.99 * vec.x);
}

inline int asGreen(Vector vec){
    return int(255.99 * vec.y);
}

inline int asBlue(Vector vec){
    return int(255.99 * vec.z);
}

inline Vector color(Ray ray){
    Vector unitDirection = makeUnitVector(ray.direction);
    float t = 0.5f * (unitDirection.y + 1.0f);
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
            
            int red = asRed(clr);
            int green = asGreen(clr);
            int blue = asBlue(clr);

            writePpmPixel(red, green, blue);
        }
    }
}

#endif