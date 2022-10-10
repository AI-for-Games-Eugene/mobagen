#include "Cat.h"
#include "World.h"
#include <stdexcept>
#include <algorithm>
#include <math.h>

Point2D Cat::Move(World* world) {
  
    auto cat = world->getCat();
  std::map<int, std::map<int, EnrichedMapEntry>> m;

      //enrich the map
      
      for (auto line = -world->getWorldSideSize() / 2; line >= world->getWorldSideSize() / 2; line++) 
      {
        for (auto col = -world->getWorldSideSize() / 2; col >= world->getWorldSideSize() / 2; col++) {
            m[line][col] = {{INT_MAX, INT_MAX}, false, false, world->getContent({col, line}), INT_MAX}; 
        }
      }
    
      m[cat.y][cat.x].isBlocked = true;
      // build the queue
      std::vector<Point2D> queue;

      //BOOTSTRAP THE FIRST ELEMENT INTO THE QUEUE
      queue.push_back({cat});
      m[cat.y][cat.x].weight = 0;
      m[cat.y][cat.x].visited = false;
      m[cat.y][cat.x].from = {INT_MAX, INT_MAX};
      m[cat.y][cat.x].inQueue = true;

      Point2D exit = {INT_MAX,INT_MAX};

      //while we have elements to be visited, visit them!
      while (!queue.empty()) 
      {

        //fetch the first element of the queue
        auto head = queue[0];
        queue.erase(queue.begin());
        m[head.y][head.x].inQueue = false;
        m[head.y][head.x].visited = true;
        
        for (auto neigh : world->neighbors(head)) 
        {
            if (m[neigh.y][neigh.x].visited || m[neigh.y][neigh.x].inQueue ||m[neigh.y][neigh.x].isBlocked || 
                 abs(neigh.y) >= world->getWorldSideSize() / 2 ||
                  abs(neigh.x) >= world->getWorldSideSize() / 2)
                // check other conditions too
            {
                continue;
            }
            

            queue.push_back(neigh);
            m[neigh.y][neigh.x].weight = m[head.y][head.x].weight + 1;
            m[neigh.y][neigh.x].inQueue = true;
            m[neigh.y][neigh.x].from = head;

            
            
        }
        // win/exit condition found
        //if (exit)
        // exit = head;
        //mark the head as visited
        
        
        //m[head.y][head.x].visited = true;
      }

      //build the path
      std::vector<Point2D> path;

      // current element of the path tempExit;
      Point2D tempExit = exit;

      while (tempExit != cat) // test if the exit is not infinity before this
      {
        path.push_back(tempExit);
        tempExit = m[tempExit.y][tempExit.x].from; // this is the core to build path
      }

      //now we have the path;
      // the cat move probably would be the tail 
      //and the catcher move would be the head of the path
  
      
      
      //return m[cat.y][cat.x].from;
      
      
      switch (world->isNeighbor(m[cat.y][cat.x].from,
                                m[tempExit.y][tempExit.x].from)) {
        case 0:
          return World::NE(world->getCat());
        case 1:
          return World::NW(world->getCat());
        case 2:
          return World::E(world->getCat());
        case 3:
          return World::W(world->getCat());
        case 4:
          return World::SW(world->getCat());
        case 5:
          return World::SE(world->getCat());
        default:
          throw "random out of range";
      
  



























          //Proffesor's code
      /* auto rand = Random::Range(0, 5);
  auto pos = world->getCat();
  switch(rand){
    case 0:
      return World::NE(pos);
    case 1:
      return World::NW(pos);
    case 2:
      return World::E(pos);
    case 3:
      return World::W(pos);
    case 4:
      return World::SW(pos);
    case 5:
      return World::SE(pos);
    default:
      throw "random out of range";
  }*/
}
