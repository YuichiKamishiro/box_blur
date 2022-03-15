# Installing library
  `sudo apt-get install libsfml-dev`

## Building
  `g++ box_blur.cpp -lsfml-graphics -lsfml-window -lsfml-system -pthread -o build`
### Launching
  `./build image.jpg 10`
