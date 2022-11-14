#ifndef MOBAGEN_MAZEGENERATOR_H
#define MOBAGEN_MAZEGENERATOR_H

#include "MazeGeneratorBase.h"
#include <map>
#include <vector>
#include "Point2D.h"

class MazeGenerator: public MazeGeneratorBase {
 private:
  std::vector<Point2D> stack;
  std::map<int, std::map<int, bool>> visited;
  Point2D RanStart(World* w);
  std::vector<Point2D> getVisitables(World* w, const Point2D& p);
  Point2D getBreakable(World* world, const Point2D& point);

 public:
  MazeGenerator() = default;
  std::string GetName() override { return "Hunt and Kill (Eugene)"; };
  bool Step(World* world) override;
  void Clear(World* world) override;
};

#endif
