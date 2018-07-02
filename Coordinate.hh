#ifndef COORDINATE_HH
#define COORDINATE_HH

#include <iostream>

class Coordinate {
private:
  unsigned int x_;
  unsigned int y_;

public:
  explicit Coordinate(unsigned int x = 0, unsigned int y = 0) : x_(x), y_(y) {}

  unsigned int x() const { return x_; }
  unsigned int y() const { return y_; }

  bool operator==(const Coordinate &k) const {
    return k.x_ == x_ && k.y_ == y_;
  }
  bool operator!=(const Coordinate &k) const { return !(*this == k); }
  bool operator<(const Coordinate &k) const {
    if (x_ < k.x_)
      return true;
    if (x_ == k.x_)
      return y_ < k.y_;
    return false;
  }

  friend std::ostream &operator<<(std::ostream &os, const Coordinate &k) {
    os << "(" << k.x_ << "," << k.y_ << ")";
    return os;
  }
  friend std::istream &operator>>(std::istream &is, Coordinate &k) {
    is >> k.x_ >> k.y_;
    return is;
  }
};

#endif
