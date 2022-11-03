#include "MazeGenerator.h"
#include "World.h"
#include "Point2D.h"
#include <map>
#include <vector>
#include "Random.h"


bool MazeGenerator::Step(World* world) {
  //Hunt and Kill Algorithm

	if (stack.empty()) 
	{
		auto point = RanStart(world);

		if (point.x == INT_MAX && point.y == INT_MAX) 
		{
			return false;
		}
                stack.push_back(point);
                world->SetNodeColor(point, Color::Yellow);
	}
  
  //std::vector<Point2D> stack;
  //std::map<int, std::map<int, bool>> visited;
  //Random random;

  int end = world->GetSize();
  int start = -world->GetSize() + world->GetSize() + 1;

	//x, y = rand(width), rand(height)
  int x = random.Range(start, end);
  int y = random.Range(start, end);
  auto walk = stack.back();
  auto hunt = stack.begin();

	// loop do (do while loop)
  do {
    visited[walk.y][walk.x];
  
  } while (!stack.empty());
	//x, y = walk (grid, x, y)
	//x, y = hunt (grid) unless x
	//break unless x
	//end

	//def walk (grid, x, y)
	//[N, S, E, W].shuffle.each do |dir|
	// #...
	//end
	//nil
	//end

	//nx, ny = x + DX [dir], y + DY[dir]
	//if nx >= 0 && ny >= 0 && ny < grid.length && nx < grid[ny].length && grid[ny][nx] == 0
  if (visited[walk.y][walk.x]) {
  
  }
	//#...
	//end

	//grid[y][x] | = dir
	//grid[ny][nx] | = OPPOSITE[dir]
	//return [nx, ny]
  return visited[walk.y][walk.x];

	//def hunt(grid)
	//grid.each_with_index do |row, y|
	//row.each_with_index do |cell, x|
	//next unless cell == 0
	//#...
	//end
	//end
	//nil
	//end

	//neighbors = []
	//neighbors << N if y > 0 && grid[y-1][x] != 0
	//neighbors << W if x > 0 && grid[y][x-1] != 0
	//neighbors << E if x+1 < grid[y].length && grid[y][x+1] != 0
	//neighbors << S if y+1 < grid.length && frid[y+1][x] != 0

	//direction = neighbors[rand(neighbors.length)] or next

	//nx, ny = x + DX[direction], y + DY[direction]
	//grid[y][x] |= direction
	//grid[ny][nx] |= OPPOSITE[direction]
	//return[x, y]
  return visited[walk.y][walk.x];

	return true;
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
	auto ran = w->GetSize() / 2;

	for(int y = -ran; y <= ran; y++) 
	{
          for (int x = - ran; x <= ran; x++) 
		  {
            if (!visited[y][x]) 
			{
              return {x, y};
			}

			return {INT_MAX, INT_MAX};
		  }
    }
}
