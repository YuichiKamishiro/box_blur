# Installing library
  `sudo apt-get install libsfml-dev`

## Building
  `g++ box_blur.cpp -lsfml-graphics -lsfml-window -lsfml-system -pthread -o build`
## Launching
  `./build path_to_file blur_delta`
  
  where blur_delta should be odd integer
