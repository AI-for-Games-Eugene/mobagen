#include "Catcher.h"
#include "World.h"
#include <stdexcept>
#include <algorithm>

Point2D Catcher::Move(World* world) {
  visited.clear();
  from.clear();
  std::vector<queueEntry> queue;
  queue.push_back({world->getCat(), 0});

  auto head = queue[0];
  queue.erase(queue.begin());
  visited[head.position.x][head.position.y] = true;

  auto side = world->getWorldSideSize()/2;
  for(;;) {
    Point2D p = {Random::Range(-side, side), Random::Range(-side, side)};
    auto cat = world->getCat();
    if(cat.x!=p.x && cat.y!=p.y && !world->getContent(p))
      return p;
  }
}
