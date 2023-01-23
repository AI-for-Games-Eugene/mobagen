#include"MyWaterErosion.h"
#include "FastNoiseLite.h"
#include "PerlinNoise.hpp"

std::vector<Color32> MYWaterErosion::Generate(int sideSize,
                                                       float displacement) {
  std::vector<Color32> colors;
  //   create your own function for noise generation
  FastNoiseLite base;
  base.SetFractalOctaves(3);
  base.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2S);
  base.SetFractalType(FastNoiseLite::FractalType_FBm);
  FastNoiseLite cellular;
  cellular.SetNoiseType(FastNoiseLite::NoiseType_Cellular);
  cellular.SetFractalOctaves(3);
  for (int l = 0; l < sideSize; l++) {
    for (int c = 0; c < sideSize; c++) {
      float c1 =
          ((base.GetNoise((float)c, (float)l, displacement * 50) + 1) / 2) *  255;
      float c2 =
          ((cellular.GetNoise((float)c, (float)l, displacement * 50) + 1) / 2) *  255;
      auto avg = (c1 + c2) / 2;
      colors.emplace_back(avg, avg, avg);
    }
  }
  std::cout << colors.size() << std::endl;
  return colors;
}
std::string MYWaterErosion::GetName() { return "MYWaterErosion"; }
