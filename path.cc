#include "Astar.hh"
#include "Coordinate.hh"
#include "Map.hh"
#include "Node.hh"
#include "PathFinder.hh"

#include <fstream>
#include <iostream>
#include <list>
#include <memory>

int main() {
  Map map;
  std::ifstream f("karte.txt");
  f >> map;
  f.close();

  Coordinate start(1, 1);
  Coordinate goal(40, 13);

  std::cout << "A*:" << std::endl;
  std::unique_ptr<PathFinder> pf(new Astar());
  std::list<Coordinate> path = pf->search(map, start, goal);
  std::cout << "Laenge:" << path.size() << std::endl;
  map.print(path);
}
