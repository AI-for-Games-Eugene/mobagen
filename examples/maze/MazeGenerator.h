#ifndef MOBAGEN_MAZEGENERATOR_H
#define MOBAGEN_MAZEGENERATOR_H

#include "MazeGeneratorBase.h"
#include <map>
#include <vector>
#include "Point2D.h"

// please do not use this one anymore. Move your code to the specific implementation.
// I am going to rename this interface soon to be a naive implementation.
class MazeGenerator: public MazeGeneratorBase {
 private:
  std::vector<Point2D> stack;
  std::map<int, std::map<int, bool>> visited;  // naive. not optimal
  Point2D RanStart(World* w);
  std::vector<Point2D> getVisitables(World* w, const Point2D& p);

 public:
  MazeGenerator() = default;
  std::string GetName() override { return "Hunt and Kill"; };
  bool Step(World* world) override;
  void Clear(World* world) override;
};

#endif
