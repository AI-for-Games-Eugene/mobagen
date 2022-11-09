#include "MazeGenerator.h"
#include "World.h"
#include "Point2D.h"
#include <map>
#include <vector>
#include "Random.h"


bool MazeGenerator::Step(World* world) {
        //Hunt and Kill Algorithm
        //Similar to Recursive Backtracking but it doesn't backtrack
        //Works fine just has a few boxes (which can be used as decorations)
  
        // check if we need to find a new starting point
        if (stack.empty()) {
    auto point = RanStart(world);
          
          if (point.x == INT_MAX && point.y == INT_MAX)
            return false;  // no empty space no fill


           if (point.x != -world->GetSize() &&
                   point.y != -world->GetSize()) {
            
             visited[point.x - 1][point.y] = false;
             auto visit = getVisitables(world, point);
             
             
             //randomize visitable


             auto random = Random::Range(0, visit.size());
             if (visit.size() != 0) 
             {
               auto next = visit[random]; 

               // remove the wall bewtween the visiables and the point

               if (next.y == visited[point.x][point.y - 1])  // north
               {
                 world->SetNorth(point, false);
                 world->SetNodeColor(stack[point.y + 1], Color::Black);
               }
                 
               else if (next.x == visited[point.x + 1][point.y])  // east
               {
                 world->SetEast(point, false);
                 world->SetNodeColor(stack[point.x], Color::Black);
               }
                 
               else if (next.y == visited[point.x][point.y + 1])  // south
               {
                 world->SetSouth(point, false);
                 world->SetNodeColor(stack[point.y], Color::Black);
               }
                 
               else if (next.x == visited[point.x - 1][point.y])  // west
               {
                 world->SetWest(point, false);
                 world->SetNodeColor(stack[point.x + 1], Color::Black);
               }
             }
           }

          stack.push_back(point);
          world->SetNodeColor(point, Color::Red.Dark());
          
        }

        // visit the current element
        auto current = stack.back();
        visited[current.y][current.x] = true;
        world->SetNodeColor(current, Color::Red.Dark());

        // check if we should go deeper
        std::vector<Point2D> visitables = getVisitables(world, current);
        

        if (visitables.empty()) {
          for (int i = 0; i < stack.size(); i++) {
            world->SetNodeColor(stack[i], Color::Black);
          }

          stack.clear();

         
          return true;
        }

        else 
        {  // go deeper

          auto r = Random::Range(0, visitables.size() - 1);
          auto next = visitables[r];
          world->SetNodeColor(next, Color::Green);
          stack.push_back(next);
          auto delta = next - current;

          // remove walls

          if (delta.y == -1)  // north
            world->SetNorth(current, false);
          else if (delta.x == 1)  // east
            world->SetEast(current, false);
          else if (delta.y == 1)  // south
            world->SetSouth(current, false);
          else if (delta.x == -1)  // west
            world->SetWest(current, false);
          return true;
        }
}

void MazeGenerator::Clear(World* world) 
{
  visited.clear();
  stack.clear();
  auto sideOver2 = world->GetSize() / 2;

  for (int i = -sideOver2; i <= sideOver2; i++) {
    for (int j = -sideOver2; j <= sideOver2; j++) {
      visited[i][j] = false;
    }
  }
}

Point2D MazeGenerator::RanStart(World* w) { 
	auto sideOver2 = w->GetSize() / 2;

  for (int y = -sideOver2; y <= sideOver2; y++)
    for (int x = -sideOver2; x <= sideOver2; x++)
      if (!visited[y][x]) return {x, y};
  return {INT_MAX, INT_MAX};
}

std::vector<Point2D> MazeGenerator::getVisitables(World * w, const Point2D& p) {
  auto sideOver2 = w->GetSize() / 2;
  std::vector<Point2D> visitables;

  
  // north
  if ((abs(p.x) <= sideOver2 &&
       abs(p.y - 1) <= sideOver2) &&  // should be inside the board
      !visited[p.y - 1][p.x] &&       // not visited yet
      w->GetNorth({p.x, p.y - 1}))    // has wall
    visitables.emplace_back(p.x, p.y - 1);
  // east
  if ((abs(p.x + 1) <= sideOver2 &&
       abs(p.y) <= sideOver2) &&    // should be inside the board
      !visited[p.y][p.x + 1] &&     // not visited yet
      w->GetNorth({p.x + 1, p.y}))  // has wall
    visitables.emplace_back(p.x + 1, p.y);
  // south
  if ((abs(p.x) <= sideOver2 &&
       abs(p.y + 1) <= sideOver2) &&  // should be inside the board
      !visited[p.y + 1][p.x] &&       // not visited yet
      w->GetNorth({p.x, p.y + 1}))    // has wall
    visitables.emplace_back(p.x, p.y + 1);
  // west
  if ((abs(p.x - 1) <= sideOver2 &&
       abs(p.y) <= sideOver2) &&    // should be inside the board
      !visited[p.y][p.x - 1] &&     // not visited yet
      w->GetNorth({p.x - 1, p.y}))  // has wall
    visitables.emplace_back(p.x - 1, p.y);

  return visitables;
}
