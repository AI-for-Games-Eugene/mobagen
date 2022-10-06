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
  for(;;) {
    Point2D p = {Random::Range(-side, side), Random::Range(-side, side)};
    auto cat = world->getCat();
    if(cat.x!=p.x && cat.y!=p.y && !world->getContent(p))
      return p;
  }
}
