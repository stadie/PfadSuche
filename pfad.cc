#include "Karte.hh"
#include "Pfadsucher.hh"
#include "Koordinate.hh"
#include "Knoten.hh"

#include <list>
#include <fstream>
#include <iostream>

struct F {
  double operator()(const Knoten& k) {
    return k.g()+k.h();
  }
};

struct G {
  double operator()(const Knoten& k) {
    return k.g();
  }
};

struct H {
  double operator()(const Knoten& k) {
    return k.h();
  }
};


int main() {
  Karte k;
  std::ifstream f("karte.txt");
  f >> k;
  f.close();

  Koordinate start(1,1);
  Koordinate  ziel(40,13);
  Pfadsucher pf(k);
  std::cout << "Dijkstra:" << std::endl;
  std::list<Koordinate>  pfad = pf.suche(start,ziel,G());
  k.print(pfad);
  std::cout << "A*:" << std::endl;
  pfad = pf.suche(start,ziel,F());
  std::cout << "Laenge:" << pfad.size() << std::endl;
  k.print(pfad);
  std::cout << "BFS:" << std::endl;
  pfad = pf.suche(start,ziel,H());
  std::cout << "Laenge:" << pfad.size() << std::endl;
  k.print(pfad);
}
