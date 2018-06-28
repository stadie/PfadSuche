#ifndef KNOTEN_HH
#define KNOTEN_HH

#include "Koordinate.hh"

class Knoten : public Koordinate {
 private:
  double g_, h_;
  Koordinate vorgaenger_;

 public:
  Knoten(Koordinate x, double g, double h, Koordinate vorgaenger)
  : Koordinate(x), g_(g), h_(h), vorgaenger_(vorgaenger) {}
  double g() const { return g_; }  // kosten vom Start
  double h() const { return h_; }  // abstand zum Ziel
  Koordinate vorgaenger() const { return vorgaenger_; }
};

#endif
