#ifndef PATHFINDER_HH
#define PATHFINDER_HH

#include "Coordinate.hh"
#include "Map.hh"
#include "Node.hh"

class PathFinder {
public:
  virtual ~PathFinder() = default;
  virtual std::list<Coordinate> search(Map map, Coordinate start,
                                       Coordinate goal) = 0;
};

#endif
