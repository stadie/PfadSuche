#include "Map.hh"

std::list<Coordinate> Map::neighbors(const Coordinate &k) const {
  std::list<Coordinate> klist;
  //...
  return klist;
}

void Map::print(const std::list<Coordinate> &path) const {
  for (unsigned int y = 0; y < height(); ++y) {
    for (unsigned int x = 0; x < width(); ++x) {
      Coordinate k(x, y);
      if (find(path.begin(), path.end(), k) != path.end()) {
        std::cout << 'p';
      } else {
        std::cout << (this->operator()(k) ? '.' : 'X');
      }
    }
    std::cout << std::endl;
  }
}

std::ostream &operator<<(std::ostream &os, const Map &k) {
  os << k.width() << std::endl;
  os << k.height() << std::endl;
  for (unsigned int y = 0; y < k.height(); ++y) {
    for (unsigned int x = 0; x < k.width(); ++x) {
      os << (k(Coordinate(x, y)) ? '.' : 'X');
    }
    os << std::endl;
  }
  return os;
}

std::istream &operator>>(std::istream &is, Map &k) {
  //...
  return is;
}
