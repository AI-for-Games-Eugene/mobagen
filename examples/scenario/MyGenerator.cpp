
#include "PerlinNoise.hpp"
#include "MyGenerator.h"
#include <iostream>

std::vector<Color32> MyGenerator::Generate(int sideSize, float displacement) {
  std::vector<Color32> colors;
  
  siv::BasicPerlinNoise<float> noise;
  noise.reseed(1337);
  
  for (int l = 0; l < sideSize; l++) {
    for (int c = 0; c < sideSize; c++) {
      float rgb = abs(noise.octave3D(c / 50.0, l / 50.0, displacement, 2) * 255);      
      // try and create biomes
      if (rgb >= 0 && rgb <= 50) 
      {
        colors.emplace_back(Color::Blue);
        
        
      }
      
      else
      {
        colors.emplace_back(Color::Green);
      }

      /*
      function biome(e) 
      {
        // a threshold between 0.2 and 0.5 work well in the demo
        // but each generator will need its own parameter tuning
        if (e < waterlevel) return WATER;
        else return LAND;
      }
      */
      /*
      function biome(e) 
      {
        // these thresholds will need tuning to match your generator
        if (e < 0.1) return WATER;
        else if (e < 0.2) return BEACH;
        else if (e < 0.3) return FOREST;
        else if (e < 0.5) return JUNGLE;
        else if (e < 0.7) return SAVANNAH;
        else if (e < 0.9) return DESERT;
        else return SNOW;
      }
      */
      /*
      function biome(e, m) 
      {      
        // these thresholds will need tuning to match your generator
        if (e < 0.1) return OCEAN;
        if (e < 0.12) return BEACH;
  
        if (e > 0.8) 
        {
            if (m < 0.1) return SCORCHED;
            if (m < 0.2) return BARE;
            if (m < 0.5) return TUNDRA;
            return SNOW;
        }

        if (e > 0.6) 
        {
            if (m < 0.33) return TEMPERATE_DESERT;
            if (m < 0.66) return SHRUBLAND;
            return TAIGA;
        }

        if (e > 0.3) 
        {
            if (m < 0.16) return TEMPERATE_DESERT;
            if (m < 0.50) return GRASSLAND;
            if (m < 0.83) return TEMPERATE_DECIDUOUS_FOREST;
            return TEMPERATE_RAIN_FOREST;
        }

        if (m < 0.16) return SUBTROPICAL_DESERT;
        if (m < 0.33) return GRASSLAND;
        if (m < 0.66) return TROPICAL_SEASONAL_FOREST;
         return TROPICAL_RAIN_FOREST;
      }
      */


    }
    
  }

  

  


  
  std::cout << colors.size() << std::endl;
  return colors;
}
std::string MyGenerator::GetName() { return "MyGenerator"; }
