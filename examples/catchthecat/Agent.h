#ifndef AGENT_H
#define AGENT_H
#include "Point2D.h"
#include <unordered_map>
#include <map>
#include<iostream>
#include <iomanip>

using namespace std;

class World;

struct EnrichedMapEntry {
  Point2D from;
  bool visited;
  bool inQueue;
  bool isBlocked;
  int weight;
  bool operator<(const EnrichedMapEntry& rhs) const;
};

class Agent {
public:
  explicit Agent()= default;;
  virtual Point2D Move(World*)=0;  
};

#endif  // AGENT_H
