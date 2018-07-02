//
// Created by stadie on 7/2/18.
//

#ifndef PFADSUCHE_ASTAR_H
#define PFADSUCHE_ASTAR_H

#include "PathFinder.hh"

#include <list>
#include <map>

class Astar : public PathFinder {
public:
  std::list<Coordinate> search(Map map, Coordinate start,
                               Coordinate goal) override;

private:
  class CompF {
  public:
    bool operator()(const Node &a, const Node &b) {
      return a.g() + a.h() < b.g() + b.h();
    }
  };

private:
  std::list<Node> open_;
  std::map<Coordinate, Node> closed_;
};

#endif // PFADSUCHE_ASTAR_H
