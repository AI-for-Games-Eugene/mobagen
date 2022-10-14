#include "Catcher.h"
#include "World.h"
#include <stdexcept>
#include <algorithm>

Point2D Catcher::Move(World* world) 
{
  //block path base on the direction where the cat is facing
  
  // Note: Code is similar to the code made for the cat
  // It is set to block any open paths to trap the cat

  
  auto cat = world->getCat(); // gets Cat Position

  std::map<int, std::map<int, EnrichedMapEntry>> m; //Sets up map

  // enrich the map
  for (auto line = -world->getWorldSideSize() / 2;
       line >= world->getWorldSideSize() / 2; line++) {
    for (auto col = -world->getWorldSideSize() / 2;
         col >= world->getWorldSideSize() / 2; col++) {
      m[line][col] = {{INT_MAX, INT_MAX}, false, false, world->getContent({col, line}), INT_MAX};
    }
  }

  m[cat.y][cat.x].isBlocked = true; // to make sure that the blocker isn't on top of the cat
  
  std::vector<Point2D> queue; // build the queue

  // BOOTSTRAP THE FIRST ELEMENT INTO THE QUEUE
  queue.push_back({cat});
  m[cat.y][cat.x].weight = 0;
  m[cat.y][cat.x].visited = false;
  m[cat.y][cat.x].from = {INT_MAX, INT_MAX};
  m[cat.y][cat.x].inQueue = true;

  Point2D exit = {INT_MAX, INT_MAX};

  // while we have elements to be visited, visit them!
  while (!queue.empty()) 
  {
    // fetch the first element of the queue
    auto head = queue[0];
    queue.erase(queue.begin());
    m[head.y][head.x].inQueue = false;
    m[head.y][head.x].visited = true;

    if (abs(head.x) >= world->getWorldSideSize() / 2 || abs(head.y) >= world->getWorldSideSize() / 2) // Checks if the Absolute value of head is grater than or equal to World Size
    { 
      exit = head; //Exit equals the head
      break;
    }

    for (auto neigh : world->neighbors(head)) { // It loops until all elements are in the queue

      if (m[neigh.y][neigh.x].visited || m[neigh.y][neigh.x].inQueue ||
          m[neigh.y][neigh.x].isBlocked ||
          abs(neigh.y) > world->getWorldSideSize() / 2 ||
          abs(neigh.x) > world->getWorldSideSize() / 2 ||
          world->getContent(neigh)) // checks to see if thr element is either visted, blocked, in the queue, and that it is in the grid
      {
        continue;
      }

      queue.push_back(neigh); // pushes the nighbor into the queue

      m[neigh.y][neigh.x].weight = m[head.y][head.x].weight + 1; // adds the wieght to m Neighbor

      m[neigh.y][neigh.x].inQueue = true; //marks that it is in the queue

      m[neigh.y][neigh.x].from = head; // m nieghbor becomes the head
    }
    
    m[head.y][head.x].visited = true; // mark the head as visited
  }

  // build the path
  std::vector<Point2D> path;

  // current element of the path tempExit;
  Point2D tempExit = exit;

  while (tempExit != cat)  // test if the exit is not infinity before this
  {
    path.push_back(tempExit);
    tempExit =
        m[tempExit.y][tempExit.x].from;  // this is the core to build path
  }

  path.push_back(tempExit); // pushes the tempExit into the path again

  if (exit.x == INT_MAX && exit.y == INT_MAX) // Checks if all of the corners on the map is blocked
  { 

    if (!world->getContent(World::E(cat))) // Checks if East is not blocked
    { 
      return World::E(cat); // returns East
    }

    else if (!world->getContent(World::NE(cat))) // Checks if NorthEast is not blocked
    { 
      return World::NE(cat); // returns NorthEast
    }

    else if (!world->getContent(World::NW(cat))) // Checks if NorthWest is not blocked
    {
      return World::NW(cat); // returns NorthWest
    } 

    else if (!world->getContent(World::SE(cat))) // Checks if SouthEast is not blocked
    { 
      return World::SE(cat); // returns SouthEast
    } 

    else if (!world->getContent(World::SW(cat))) // Checks if SouthWest is not blocked
    { 
      return World::SW(cat); // returns SouthWest
    }

    else if (!world->getContent(World::W(cat))) // Checks if West is not blocked
    { 
      return World::W(cat); // returns West
    }
  }

    return path[0];  // returns the path
}
