#include"MyWaterErosion.h"
#include "FastNoiseLite.h"
#include "PerlinNoise.hpp"

std::vector<Color32> MYWaterErosion::Generate(int sideSize,
                                                       float displacement) {
  //std::vector<Color32> colors;
  ////   create your own function for noise generation
  //FastNoiseLite base;
  //base.SetFractalOctaves(3);
  //base.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2S);
  //base.SetFractalType(FastNoiseLite::FractalType_FBm);
  //FastNoiseLite cellular;
  //cellular.SetNoiseType(FastNoiseLite::NoiseType_Cellular);
  //cellular.SetFractalOctaves(3);
  //for (int l = 0; l < sideSize; l++) {
  //  for (int c = 0; c < sideSize; c++) {
  //    float c1 =
  //        ((base.GetNoise((float)c, (float)l, displacement * 50) + 1) / 2) *  255;
  //    float c2 =
  //        ((cellular.GetNoise((float)c, (float)l, displacement * 50) + 1) / 2) *  255;
  //    auto avg = (c1 + c2) / 2;
  //    colors.emplace_back(avg, avg, avg);
  //  }
  //}
  //std::cout << colors.size() << std::endl;
  //return colors;

  
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
      if (height > 0 && height < 0.2) //Water
      {
        color = Color::Blue;
      }
      
      else if (height > 0.2 && height < 0.3)  // Heat
      {
        color = Color::Red;
      }

      else if (height > 0.3 && height < 0.4) //Forest
      {
        color = Color::Green;
      }

      else if (height > 0.4 && height < 0.5)  //Jungle
      {
        color = Color::DarkGreen;
      }

      else if (height > 0.5 && height < 0.6)  //Smoke
      {
        color = Color::Gray;
      }

      else if (height > 0.6 && height < 0.8)  //Desert
      {
        color = Color::LightYellow;
      }

      else if (height > 0.8 && height < 1)  // Snow
      {
        color = Color::White;
      }    

      colors.push_back(color);
    }
  }
  
  std::cout << colors.size() << std::endl;
  return colors;
  
  
}
std::string MYWaterErosion::GetName() { return "MYWaterErosion"; }
