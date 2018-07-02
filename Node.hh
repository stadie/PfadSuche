#ifndef NODE_HH
#define NODE_HH

#include "Coordinate.hh"

class Node {
private:
  Coordinate c_;
  double g_, h_;
  Coordinate parent_;

public:
  Node() : c_(0, 0), g_(-1), h_(-1), parent_(0, 0) {}
  Node(Coordinate c, double g, double h, Coordinate parent)
      : c_(c), g_(g), h_(h), parent_(parent) {}
  Coordinate coord() const { return c_; }
  double g() const { return g_; } // kosten vom Start
  double h() const { return h_; } // abstand zum Ziel
  Coordinate parent() const { return parent_; }
  bool operator==(const Node &n) const { return c_ == n.c_; }
};

#endif
