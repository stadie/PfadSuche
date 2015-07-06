#ifndef KARTE_HH
#define KARTE_HH

#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include "Koordinate.hh"

class Karte {
private:
  std::vector<std::vector<bool> > felder_;
public:
  Karte() : felder_(0) {}
  double abstand(const Koordinate& a, const Koordinate& b) const {
    return std::max(std::abs(a.x()-b.x()),std::abs(a.y()-b.y()));
  }
  bool operator()(const Koordinate& k) const { return felder_[k.x()][k.y()];}
  int hoehe() const { return felder_.size() ? felder_[0].size() : 0;}
  int breite() const { return felder_.size() ;}
  void print(const std::list<Koordinate>& pfad) const;

  std::list<Koordinate> nachbarn(const Koordinate& k) const;


  friend std::ostream& operator<<(std::ostream& os, const Karte& k);
  friend std::istream& operator>>(std::istream& is, Karte& k);
};

#endif
