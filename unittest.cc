#include "Coordinate.hh"
#include "Map.hh"
#include "Node.hh"
#include "PathFinder.hh"

#include <fstream>
#include <iostream>
#include <list>

int main() {
  std::cout << "###########################################################\n";
  std::cout << "Teste Koordinate:\n";
  Coordinate k12(1, 2);
  Coordinate k43(4, 3);
  Coordinate k15(1, 5);

  std::cout << "(1,2) == (1,2)" << ((k12 == k12) ? "ok" : "error") << std::endl;
  std::cout << "(1,2) != (1,2)" << ((k12 != k12) ? "error" : "ok") << std::endl;
  std::cout << "(1,2) < (1,2)" << ((k12 < k12) ? "error" : "ok") << std::endl;
  std::cout << "(1,2) == (4,3)" << ((k12 == k43) ? "error" : "ok") << std::endl;
  std::cout << "(1,2) != (4,3)" << ((k12 != k43) ? "ok" : "error") << std::endl;

  std::cout << "(1,2) =? " << k12 << std::endl;
  Coordinate x;
  std::cout << "Geben Sie 5 7 ein:" << std::endl;
  std::cin >> x;
  std::cout << x << " == " << Coordinate(5, 7)
            << ((x == Coordinate(5, 7)) ? "ok" : "error") << std::endl;

  std::cout << "###########################################################\n";
  std::cout << "Teste Map:\n";
  Map karte;
  std::cout << "Abstand " << k12 << " und " << k12 << ":"
            << karte.distance(k12, k12) << " "
            << ((karte.distance(k12, k12) == 0) ? "ok" : "error") << std::endl;
  std::cout << "Abstand " << k12 << " und " << k43 << ":"
            << karte.distance(k12, k43) << " "
            << ((karte.distance(k12, k43) == 3) ? "ok" : "error") << std::endl;
  std::cout << "Abstand " << k43 << " und " << k12 << ":"
            << karte.distance(k43, k12) << " "
            << ((karte.distance(k43, k12) == 3) ? "ok" : "error") << std::endl;
  std::cout << "Abstand " << k12 << " und " << k15 << ":"
            << karte.distance(k12, k15) << " "
            << ((karte.distance(k12, k15) == 3) ? "ok" : "error") << std::endl;

  std::ifstream f("karte.txt");
  f >> karte;
  f.close();
  std::cout << "Eingelesene Map:\n";
  std::cout << karte;

  std::cout << "Map mit Pfad:\n";
  std::list<Coordinate> testPfad = {Coordinate(1, 2), Coordinate(1, 3),
                                    Coordinate(1, 4)};
  karte.print(testPfad);

  Coordinate kn(1, 1);
  std::list<Coordinate> nachbarn = karte.neighbors(kn);
  std::cout << "Nachbarn von " << kn << ":";
  for (std::list<Coordinate>::const_iterator i = nachbarn.begin();
       i != nachbarn.end(); ++i) {
    std::cout << *i << " ";
  }
  std::cout << std::endl;
}
