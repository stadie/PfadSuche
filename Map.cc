#include "Map.hh"

std::list<Coordinate> Map::neighbors(const Coordinate &k) const {
  std::list<Coordinate> klist;
  for (unsigned int x = k.x() - 1; x <= k.x() + 1; ++x) {
    for (unsigned int y = k.y() - 1; y <= k.y() + 1; ++y) {
      Coordinate nk(x, y);
      if (nk == k)
        continue;
      if (fields_[x][y])
        klist.push_back(nk);
    }
  }
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
  unsigned int b, h;
  is >> b >> h;
  k.fields_.resize(b);
  for (unsigned int x = 0; x < b; ++x) {
    k.fields_[x].resize(h);
  }
  for (unsigned int y = 0; y < k.height(); ++y) {
    for (unsigned int x = 0; x < k.width(); ++x) {
      char c;
      is >> c;
      k.fields_[x][y] = (c == '.');
    }
  }
  return is;
}
