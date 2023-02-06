#include "GeneratorBase.h"
#include <iostream>
#include <vector>
#include <glm/vec3.hpp>
#include <glm/gtx/normal.hpp>

class MYWaterErosion : public ScenarioGeneratorBase {
 public:
	std::vector<Color32> Generate(int sideSize, float displacement = 0) override;
	std::string GetName() override { return "MYWaterErosion"; };
};