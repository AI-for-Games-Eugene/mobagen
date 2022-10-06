#include "Agent.h"

bool EnrichedMapEntry::operator<(const EnrichedMapEntry& rhs) const {
  return this->weight < rhs.weight;
}

