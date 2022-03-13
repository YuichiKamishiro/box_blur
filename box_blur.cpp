//It's a simple BoxBlur without applying on borders
#include <SFML/Graphics.hpp>

#include <SFML/System/Vector2.hpp>
#include <iostream>

using namespace std;
using namespace sf;

Image box_blur(Vector2u size, Image img);
//BoxBlur

int main(int argc, char* argv[]){
    Image img;
    if(!img.loadFromFile(argv[1])){
        cout << "File was not find, try another argument\n";
        exit(0);
    }
    //Loading image
    Vector2u size = img.getSize();
    cout << "Size of this image -> x: " << size.x << " y: " << size.y << endl;
    //Getting Size
    for(int i = 0;i < 10;i++)
        img = box_blur(size, img);
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

Image box_blur(Vector2u size, Image img){
    for(int x = 1;x < size.x - 1;x++){
        for(int y = 1;y < size.y - 1;y++){
            int r = 0; int g = 0; int b = 0; int a = 0;
            r += img.getPixel(x - 1, y + 1).r;
            r += img.getPixel(x + 0, y + 1).r;  // Top center
            r += img.getPixel(x + 1, y + 1).r;  // Top right
            r += img.getPixel(x - 1, y + 0).r;  // Mid left
            r += img.getPixel(x + 0, y + 0).r;  // Current pixel
            r += img.getPixel(x + 1, y + 0).r;  // Mid right
            r += img.getPixel(x - 1, y - 1).r;  // Low left
            r += img.getPixel(x + 0, y - 1).r;  // Low center
            r += img.getPixel(x + 1, y - 1).r;  // Low right
              
            g += img.getPixel(x - 1, y + 1).g;
            g += img.getPixel(x + 0, y + 1).g;  // Top center
            g += img.getPixel(x + 1, y + 1).g;  // Top right
            g += img.getPixel(x - 1, y + 0).g;  // Mid left
            g += img.getPixel(x + 0, y + 0).g;  // Current pixel
            g += img.getPixel(x + 1, y + 0).g;  // Mid right
            g += img.getPixel(x - 1, y - 1).g;  // Low left
            g += img.getPixel(x + 0, y - 1).g;  // Low center
            g += img.getPixel(x + 1, y - 1).g;  // Low right
              
            b += img.getPixel(x - 1, y + 1).b;
            b += img.getPixel(x + 0, y + 1).b;  // Top center
            b += img.getPixel(x + 1, y + 1).b;  // Top right
            b += img.getPixel(x - 1, y + 0).b;  // Mid left
            b += img.getPixel(x + 0, y + 0).b;  // Current pixel
            b += img.getPixel(x + 1, y + 0).b;  // Mid right
            b += img.getPixel(x - 1, y - 1).b;  // Low left
            b += img.getPixel(x + 0, y - 1).b;  // Low center
            b += img.getPixel(x + 1, y - 1).b;  // Low right
              
            a += img.getPixel(x - 1, y + 1).a;
            a += img.getPixel(x + 0, y + 1).a;  // Top center
            a += img.getPixel(x + 1, y + 1).a;  // Top right
            a += img.getPixel(x - 1, y + 0).a;  // Mid left
            a += img.getPixel(x + 0, y + 0).a;  // Current pixel
            a += img.getPixel(x + 1, y + 0).a;  // Mid right
            a += img.getPixel(x - 1, y - 1).a;  // Low left
            a += img.getPixel(x + 0, y - 1).a;  // Low center
            a += img.getPixel(x + 1, y - 1).a;  // Low right
              
            b = b / 9;
            r = r / 9;
            g = g / 9;
            a = a / 9;
               
            Color color;
            color.r = r;
            color.g = g;
            color.b = b;
            color.a = img.getPixel(x, y).a;

            img.setPixel(x, y, color); 
            //Average of p pixel
            // x,x,x  1
            // x,p,x  -
            // x,x,x  9
        }
    }
    return img;
}
