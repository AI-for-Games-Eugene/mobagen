#include "MazeGenerator.h"
#include "World.h"

bool MazeGenerator::Step(World* world) {
  //Recursive Backtracking
	
	Point2D grid[100];

	Point2D point;


	for (int i = 0; i < world->GetSize(); i++) 
	{
		
	}

	if (world->GetNorth(point)) 
	{
          world->SetNorth(point, false);
          world->SetEast(point, true);
          world->SetSouth(point, true);
          world->SetWest(point, true);
    }
    
	if (world->GetEast(point)) 
	{
      world->SetEast(point, false);
      world->SetSouth(point, true);
      world->SetWest(point, true);
      world->SetNorth(point, true);
    }
    
	if (world->GetSouth(point)) 
	{
      world->SetSouth(point, false);
      world->SetWest(point, true);
      world->SetNorth(point, true);
      world->SetSouth(point, true);
    }
    
	if (world->GetWest(point)) 
	{
      world->SetWest(point, false);
      world->SetNorth(point, true);
      world->SetEast(point, true);
      world->SetSouth(point, true);
    }
	

  return true;
}
void MazeGenerator::Clear(World* world) {}
