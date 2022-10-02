#include "Agent.h"

bool queueEntry::operator<(const queueEntry& rhs) const { return true; }
int queueEntry::setWeight(int weight) 
{ 
	this->weight += weight;
  return this->weight;
}
