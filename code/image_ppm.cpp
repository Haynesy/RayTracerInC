#ifndef IMAGE_PPM
#define IMAGE_PPM

#include <iostream>

using namespace std;

void writePpmHeader(int width, int height){
    cout << "P3\n" << width << " " << height << "\n255\n";    
}

void writePpmPixel(int red, int green, int blue){
    cout << red << " " << green << " " << blue << "\n";
}

void writePpmFile(int width, int height){

    writePpmHeader(width, height);

    for(int y = height - 1; y >= 0; y--){
        for(int x = 0; x < width; x++){
            float r  = float(x) / float(width);
            float g  = float(y) / float(height);
            float b = 0.2f;

            int red = int(255.99 * r);
            int green = int(255.99 * g);
            int blue = int(255.99 * b);

            writePpmPixel(red, green, blue);
        }
    }
}

#endif