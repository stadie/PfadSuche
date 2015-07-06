#include "Karte.hh"
#include "Pfadsucher.hh"
#include "Koordinate.hh"
#include "Knoten.hh"

#include <list>
#include <iostream>
#include <fstream>

int main() {
  Koordinate k12(1,2);
  Koordinate k43(4,3);
  Koordinate k15(1,5);

  std::cout << "(1,2) == (1,2)" << ((k12 == k12) ? "ok" : "error") << std::endl;
  std::cout << "(1,2) != (1,2)" << ((k12 != k12) ? "error" : "ok") << std::endl;
  std::cout << "(1,2) < (1,2)" << ((k12 < k12) ? "error" : "ok") << std::endl;
  std::cout << "(1,2) == (4,3)" << ((k12 == k43) ? "error" : "ok") << std::endl;
  std::cout << "(1,2) != (4,3)" << ((k12 != k43) ? "ok" : "error") << std::endl;

  std::cout << "(1,2) =? " << k12 << std::endl;
  Koordinate x;
  std::cout << "Geben Sie 5 7 ein:" << std::endl;
  std::cin >> x;
  std::cout << x << " == " << Koordinate(5,7) << ((x == Koordinate(5,7)) ? "ok" : "error") << std::endl;



  Karte karte;
  std::cout << "Abstand " << k12 << " und " << k12 << ":" << karte.abstand(k12,k12) << " "
	    << ((karte.abstand(k12,k12)==0) ? "ok" : "error") << std::endl;
  std::cout << "Abstand " << k12 << " und " << k43 << ":" << karte.abstand(k12,k43) << " "
	    << ((karte.abstand(k12,k43)==3) ? "ok" : "error") << std::endl;
  std::cout << "Abstand " << k43 << " und " << k12 << ":" << karte.abstand(k43,k12) << " "
	    << ((karte.abstand(k43,k12)==3) ? "ok" : "error") << std::endl;
  std::cout << "Abstand " << k12 << " und " << k15 << ":" << karte.abstand(k12,k15) << " "
	    << ((karte.abstand(k12,k15)==3) ? "ok" : "error") << std::endl;


  std::ifstream f("karte.txt");
  f >> karte;
  f.close();
  std::cout << karte;

  Koordinate kn(13,5);
  std::list<Koordinate> nachbarn = karte.nachbarn(kn);
  std::cout << "Nachbarn von " << kn << ":";
  for(std::list<Koordinate>::const_iterator i = nachbarn.begin(); i != nachbarn.end() ; ++i) {
      std::cout << *i << " ";
  }
  std::cout << std::endl;
}


