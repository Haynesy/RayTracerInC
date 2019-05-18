#include <iostream>

using namespace std;

void writeFile(int width, int height){
    cout << "P3\n" << width << " " << height << "\n255\n";    
    for(int y = height - 1; y >= 0; y--){
        for(int x = 0; x < width; x++){
            float r  = float(x) / float(width);
            float g  = float(y) / float(height);
            float b = 0.2f;

            int red = int(255.99 * r);
            int green = int(255.99 * g);
            int blue = int(255.99 * b);

            cout << red << " " << green << " " << blue << "\n";
        }
    }
}

int main(int argc, char *argv[]){

    writeFile(200, 100);
    return 0;
}