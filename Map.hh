#ifndef KARTE_HH
#define KARTE_HH

#include "Coordinate.hh"
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

class Map {
private:
  std::vector<std::vector<bool>> fields_;

public:
  Map() : fields_(0) {}
  double distance(const Coordinate &a, const Coordinate &b) const { return -1;}
  bool operator()(const Coordinate &k) const { return fields_[k.x()][k.y()]; }
  unsigned long height() const {
    return fields_.empty() ? 0 : fields_[0].size();
  }
  unsigned long width() const { return fields_.size(); }
  void print(const std::list<Coordinate> &path) const;

  std::list<Coordinate> neighbors(const Coordinate &k) const;

  friend std::ostream &operator<<(std::ostream &os, const Map &k);
  friend std::istream &operator>>(std::istream &is, Map &k);
};

#endif
