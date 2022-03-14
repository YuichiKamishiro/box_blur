//It's a simple BoxBlur without applying on borders
//Author: YuichiKamishiro
//Contributors: RoziePlaysPython(https://github.com/RoziePlaysPython)
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
    Image imgc = img;
    for(int x = 1;x < size.x - 1;x++){
        for(int y = 1;y < size.y - 1;y++){
            int r = 0; int g = 0; int b = 0; int a = 0;
            
            // 3x3 pixel scanning for red color
            for(int deltaY = -1; deltaY < 2; deltaY++){
                for(int deltaX = -1; deltaX < 2; deltaX++){
                    r += imgc.getPixel(x + deltaX, y + deltaY).r;}};
            // 3x3 pixel scanning for green color
            for(int deltaY = -1; deltaY < 2; deltaY++){
                for(int deltaX = -1; deltaX < 2; deltaX++){
                    g += imgc.getPixel(x + deltaX, y + deltaY).g;}};
            // 3x3 pixel scanning for blue color
            for(int deltaY = -1; deltaY < 2; deltaY++){
                for(int deltaX = -1; deltaX < 2; deltaX++){
                    b += imgc.getPixel(x + deltaX, y + deltaY).b;}};
            // 3x3 pixel scanning for alpha
            for(int deltaY = -1; deltaY < 2; deltaY++){
                for(int deltaX = -1; deltaX < 2; deltaX++){
                    a += imgc.getPixel(x + deltaX, y + deltaY).a;}};

            b = b / 9;
            r = r / 9;
            g = g / 9;
            a = a / 9;
               
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
