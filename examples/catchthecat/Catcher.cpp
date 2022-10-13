#include "Catcher.h"
#include "World.h"
#include <stdexcept>
#include <algorithm>

Point2D Catcher::Move(World* world) {
  //block path base on the direction where the cat is facing
  //last element



  /*visited.clear();
  from.clear();
  
  std::vector<queueEntry> queue;

  while (!queue.empty()) {
    std::sort(queue.begin(), queue.end());
    
    auto last = queue[5];
    queue.erase(queue.end());

    blocked[world->getCat().x - 30][world->getCat().y - 30];
  }*/

  auto side = world->getWorldSideSize()/2;
  auto cat = world->getCat();
  std::map<int, std::map<int, EnrichedMapEntry>> m;
  Point2D exit = {INT_MAX, INT_MAX};

  // build the path
  std::vector<Point2D> path;

  // current element of the path tempExit;
  Point2D tempExit = exit;

  while (tempExit != cat)  // test if the exit is not infinity before this
  {
    /*if (m[tempExit.y][tempExit.x].isBlocked) {

    }*/
    path.push_back(tempExit);
    tempExit =
        m[tempExit.y][tempExit.x].from;  // this is the core to build path
  }

  // now we have the path;
  //  the cat move probably would be the tail
  // and the catcher move would be the head of the path

  while (cat != tempExit) {
    path.push_back(cat);
    cat = m[cat.y][cat.x].from;
  }
  path.push_back(tempExit);  // optional

  //std::reverse(path.begin(), path.end());
  
  return path[0];

  /*for(;;) {
    Point2D p = {Random::Range(-side, side), Random::Range(-side, side)};
    auto cat = world->getCat();
    if(cat.x!=p.x && cat.y!=p.y && !world->getContent(p))
      return p;
  }*/
}
