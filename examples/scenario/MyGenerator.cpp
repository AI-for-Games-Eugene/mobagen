
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

      colors.emplace_back(rgb, rgb, rgb); // note: work on color

      //      double color = noise.noise(c/50.0,l/50.0);
      //      colors.emplace_back(color,color,color);
    }
  }
  std::cout << colors.size() << std::endl;
  return colors;
}
std::string MyGenerator::GetName() { return "MyGenerator"; }

/*
std::vector<Color32> coloring;
  std::vector<float*> noise;
  //Noise noise;
  std::vector<double*> value;
  std::vector<double*> elevation;
  int x = 0;
  int y = 0;

  /***********************************************************/
/*
  for (int y = 0; y < height; y++) {
  for (int x = 0; x < width; x++) {
      double nx = x/width - 0.5, ny = y/height - 0.5;
      value[y][x] = noise(nx, ny);
  }
  }
*/

//Noise;
//for (int i = 0; i < sideSize; i++) {
//  for (int j = 0; j < sideSize; j++) {
//    double nx = j / sideSize - 0.5;
//    double ny = i / sideSize - 0.5;
//    value[i][j];
//    coloring.push_back(Color::Azure);
//  }
//}
/*****************************************************************/

/*elevation[y][x] = noise(nx, ny);*/

// Frequency
/*elevation[y][x] = noise(frequency * nx, frequency * ny);*/

// WaveLength
/*elevation[y][x] = noise(x / wavelength, y / wavelength);*/

// Octaves
/*
  elevation[y][x] =    1 * noise(1 * nx, 1 * ny);
              +  0.5 * noise(2 * nx, 2 * ny);
              + 0.25 * noise(4 * nx, 4 * ny);
*/

/*
e  =    1 * noise(1 * nx, 1 * ny);
              +  0.5 * noise(2 * nx, 2 * ny);
              + 0.25 * noise(4 * nx, 4 * ny);
  elevation[y][x] = e / (1 + 0.5 + 0.25);
*/

// Redistribution
/*e =    1 * noise(1 * nx, 1 * ny);
+  0.5 * noise(2 * nx, 2 * ny);
+ 0.25 * noise(4 * nx, 4 * ny);
e = e / (1 + 0.5 + 0.25);
elevation[y][x] = Math.pow(e, exponent);*/

// Biomes
/*function biome(e) {
  // a threshold between 0.2 and 0.5 work well in the demo
  // but each generator will need its own parameter tuning
  if (e < 0.00) return WATER;
  else return LAND;
}*/

/*
  function biome(e) {
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
  function biome(e, m) {
  // these thresholds will need tuning to match your generator
  if (e < 0.1) return OCEAN;
  if (e < 0.12) return BEACH;

  if (e > 0.8) {
  if (m < 0.1) return SCORCHED;
  if (m < 0.2) return BARE;
  if (m < 0.5) return TUNDRA;
  return SNOW;
  }

  if (e > 0.6) {
  if (m < 0.33) return TEMPERATE_DESERT;
  if (m < 0.66) return SHRUBLAND;
  return TAIGA;
  }

  if (e > 0.3) {
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

// Ridged noise
/*
  e0 =    1 * ridgenoise(1 * nx, 1 * ny);
  e1 =  0.5 * ridgenoise(2 * nx, 2 * ny) * e0;
  e2 = 0.25 * ridgenoise(4 * nx, 4 * ny) * (e0+e1);
  e = (e0 + e1 + e2) / (1 + 0.5 + 0.25);
  elevation[y][x] = Math.pow(e, exponent);
*/

// Tree placement
/*
  for (int y = 0; y < height; y++) {
  for (int x = 0; x < width; x++) {
      double nx = x/width - 0.5, ny = y/height - 0.5;
      // blue noise is high frequency; try varying this
      bluenoise[y][x] = noise(50 * nx, 50 * ny);
  }
  }

  for (int yc = 0; yc < height; yc++) {
  for (int xc = 0; xc < width; xc++) {
      double max = 0;
      // there are more efficient algorithms than this
      for (int yn = yc - R; yn <= yc + R; yn++) {
      for (int xn = xc - R; xn <= xc + R; xn++) {
          if (0 <= yn && yn < height && 0 <= xn && xn < width) {
          double e = bluenoise[yn][xn];
          if (e > max) { max = e; }
          }
          }
          }
      if (bluenoise[yc][xc] == max) {
      // place tree at xc,yc
      }
  }
  }
*/

// Wraparound maps
/*
const TAU = 2 * M_PI;

  function cylindernoise(double nx, double ny) {
  double angle_x = TAU * nx;

   In "noise parameter space", we need nx and ny to travel the
     same distance. The circle created from nx needs to have
     circumference=1 to match the length=1 line created from ny,
     which means the circle's radius is 1/2π, or 1/tau

  return noise3D(cos(angle_x) / TAU, sin(angle_x) / TAU, ny);
  }

  function torusnoise(double nx, double ny) {
  double angle_x = TAU * nx, angle_y = TAU * ny;
  return noise4D(cos(angle_x) / TAU, sin(angle_x) / TAU, cos(angle_y) / TAU,
               sin(angle_y) / TAU);
}
*/

// Implementation
/*
 module::Perlin gen; // if using libnoise
 double noise(double nx, double ny) { // if using libnoise
   // Rescale from -1.0:+1.0 to 0.0:1.0
   return gen.GetValue(nx, ny, 0) / 2.0 + 0.5;
 }

 FastNoiseLite gen; // if using fastnoiselite
 double noise(double nx, double ny) { // if using fastnoiselite
   // Rescale from -1.0:+1.0 to 0.0:1.0
   return gen.GetNoise(nx, ny) / 2.0 + 0.5;
 }

 double value[height][width];
 for (int y = 0; y < height; y++) {
   for (int x = 0; x < width; x++) {
     double nx = x/width - 0.5,
            ny = y/height - 0.5;
     value[y][x] = noise(nx, ny);
   }
 }
 

return coloring;
*/