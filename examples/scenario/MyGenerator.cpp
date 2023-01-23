
#include "PerlinNoise.hpp"
#include "MyGenerator.h"
#include <iostream>

std::vector<Color32> MyGenerator::Generate(int sideSize, float displacement) {
  std::vector<Color32> colors;
  
  siv::BasicPerlinNoise<float> noise;
  noise.reseed(1337);
  
  for (int l = 0; l < sideSize; l++) 
  {
    for (int c = 0; c < sideSize; c++) 
    {
      float height = (noise.octave3D(c / 50.0, l / 50.0, displacement, 2) + 1) / 2;      
      Color32 color;

      // biomes
      if (height > 0 && height < 0.3) //Water
      {
        color = Color::Blue;
      }
      
      else if (height > 0.3 && height < 0.4)  // Beach
      {
        color = Color::Yellow;
      }

      else if (height > 0.4 && height < 0.5) //Forest
      {
        color = Color::Green;
      }

      else if (height > 0.5 && height < 0.6)  //Jungle
      {
        color = Color::DarkGreen;
      }

      else if (height > 0.6 && height < 0.7)  //Savannah
      {
        color = Color::Orange;
      }

      else if (height > 0.7 && height < 0.9)  //Desert
      {
        color = Color::LightYellow;
      }

      else if (height > 0.9 && height < 1)  // Snow
      {
        color = Color::White;
      }    

      colors.push_back(color);
    }
  }
  
  std::cout << colors.size() << std::endl;
  return colors;
}

std::string MyGenerator::GetName() { return "MyGenerator"; }