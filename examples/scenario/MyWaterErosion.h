#include "GeneratorBase.h"
#include <iostream>
#include <vector>
#include <glm/vec3.hpp>
#include <glm/gtx/normal.hpp>

class MYWaterErosion : public ScenarioGeneratorBase {
 private:
  float heights[2048][2048];
  int sideSizeCached = 0;
  glm::vec2 surfaceNormal(int i, int j);
  std::vector<Color32> heightsToColor();
  void generateRandomHeights();
  void Erode(float dt);
  float minVol = 0.01;
  float density = 1;
  float friction = 0.05;
  float depositionRate = 0.1;
  float evapRate = 0.001;
  float lastUpdate = 0; 

public:
  std::vector<Color32> Generate(int sideSize, float displacement = 0) override;
 std::string GetName() override { return "MYWaterErosion"; };
};

struct WaterDrop {
  // Construct Particle at Position
  WaterDrop(glm::vec2 _pos) { pos = _pos; }

  glm::vec2 pos;
  glm::vec2 speed = glm::vec2(0.0);

  float volume = 1.0;    // This will vary in time
  float sediment = 0.0;  // Fraction of Volume that is Sediment!
};