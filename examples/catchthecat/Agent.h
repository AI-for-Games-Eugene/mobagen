#ifndef AGENT_H
#define AGENT_H
#include "Point2D.h"
#include <unordered_map>
#include <map>
#include<iostream>
#include <iomanip>

using namespace std;

class World;

//struct queueEntry {
//  Point2D position;
//  int weight;
//  bool operator<(const queueEntry& rhs) const;
//};

struct EnrichedMapEntry {
  Point2D position;
  Point2D from;
  bool visited;
  bool inQueue;
  bool isBlocked;
  int weight;
  bool operator<(const EnrichedMapEntry& rhs) const;
};

//struct Point {
//  Point(int x, int y) : x(x), y(y){};
//};

class Agent {
public:
  explicit Agent()= default;;
  virtual Point2D Move(World*)=0;
  /*std::unordered_map<int, std::unordered_map <int, bool>> visited;
  std::unordered_map<int, std::unordered_map<int, Point2D>> from;

  std::map<int, std::map<int, char>> blocked;*/
  
};

#endif  // AGENT_H
