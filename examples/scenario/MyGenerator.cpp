
#include "PerlinNoise.hpp"
#include "MyGenerator.h"
#include <iostream>

std::vector<Color32> MyGenerator::Generate(int sideSize,
                                                       float displacement) {
  std::vector<Color32> colors;
  //   create your own function for noise generation
  siv::BasicPerlinNoise<float> noise;
  noise.reseed(1337);
  //  Noise noise(1337, 1024,0,255);
  for (int l = 0; l < sideSize; l++) {
    for (int c = 0; c < sideSize; c++) {
      float rgb = abs(noise.octave3D(c / 50.0, l / 50.0, displacement, 2) * 255);

      // note: work on color

      if (rgb >= 0 && rgb <= 50) 
      {
        colors.emplace_back(Color::Blue);
      }

      else
      {
        colors.emplace_back(Color::Green);
      }
    }
  }

  for (int l = 0; l < sideSize; l++) {
    for (int c = 0; c < sideSize; c++) {
      float rgb =
          abs(noise.octave3D(c / 50.0, l / 50.0, displacement, 2) * 255);

      
      }
    }
  }


  
  std::cout << colors.size() << std::endl;
  return colors;
}
std::string MyGenerator::GetName() { return "MyGenerator"; }
