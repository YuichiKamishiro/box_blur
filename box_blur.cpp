//It's a simple BoxBlur without applying on borders
#include <SFML/Graphics.hpp>

#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <cmath>

using namespace std;
using namespace sf;

Image box_blur(Vector2u size, Image img, int delta);
//BoxBlur

int main(int argc, char* argv[]){
    Image img;
    int delta = atoi(argv[2]); //from the command line
    if(!(delta % 2 == 1)){
        cout << "Only odd numbers are accepted as blur delta\n";
        exit(0);
    }
    if(!img.loadFromFile(argv[1])){
        cout << "File was not find, try another argument\n";
        exit(0);
    }
    //Loading image
    Vector2u size = img.getSize();
    cout << "Size of this image -> x: " << size.x << " y: " << size.y << endl;
    //Getting Size
    for(int i = 0;i < 1;i++)
        img = box_blur(size, img, delta);
    //How many blur effects will be applied
    Sprite spr;
    Texture texture;
    texture.loadFromImage(img);
    spr.setTexture(texture);
    //Converting image to sprite
    RenderWindow window(VideoMode(700, 700),"window");
    while(window.isOpen()){
        window.clear();
        window.draw(spr);
        window.display();
    }
    //Window processing
}

Image box_blur(Vector2u size, Image img, int delta){
    cout << "box_blur called\n";
    for(int x = delta / 2;x < size.x - 1; x++){
        for(int y = delta / 2;y < size.y - 1; y++){
            int r = 0; int g = 0; int b = 0; int a = 0;
            // 3x3 pixel scanning for red color
            for(int deltaY = -(delta / 2); deltaY <= delta / 2; deltaY++){
                for(int deltaX = -(delta / 2); deltaX <= delta / 2; deltaX++){
                    r += img.getPixel(x + deltaX, y + deltaY).r;}};
            // 3x3 pixel scanning for green color
            for(int deltaY = -(delta / 2); deltaY <= delta / 2; deltaY++){
                for(int deltaX = -(delta / 2); deltaX <= delta / 2; deltaX++){
                    g += img.getPixel(x + deltaX, y + deltaY).g;}};
            // 3x3 pixel scanning for blue color
            for(int deltaY = -(delta / 2); deltaY <= delta / 2; deltaY++){
                for(int deltaX = -(delta / 2); deltaX <= delta / 2; deltaX++){
                    b += img.getPixel(x + deltaX, y + deltaY).b;}};
            // 3x3 pixel scanning for alpha
            for(int deltaY = -(delta / 2); deltaY <= delta / 2; deltaY++){
                for(int deltaX = -(delta / 2); deltaX <= delta / 2; deltaX++){
                    a += img.getPixel(x + deltaX, y + deltaY).a;}};
              
            //dividing by delta^2 to find the average between 9 pixels
            b = b / pow(delta, 2);
            r = r / pow(delta, 2);
            g = g / pow(delta, 2);
            a = a / pow(delta, 2);
            //creating color from achieved averages for each r g b a
            Color color;
            color.r = r;
            color.g = g;
            color.b = b;
            color.a = a;

            img.setPixel(x, y, color); 
            //Average of p pixel
            // x,x,x  1
            // x,p,x  -
            // x,x,x  9
        }
    }
    return img;
}
