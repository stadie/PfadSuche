#include "Karte.hh"
#include "Pfadsucher.hh"
#include "Koordinate.hh"
#include "Knoten.hh"

#include <list>
#include <iostream>
#include <fstream>

int main() {
  std::cout << "###########################################################\n";
  std::cout << "Teste Koordinate:\n";
  Koordinate k12(1, 2);
  Koordinate k43(4, 3);
  Koordinate k15(1, 5);

  std::cout << "(1,2) == (1,2)" << ((k12 == k12) ? "ok" : "error") << std::endl;
  std::cout << "(1,2) != (1,2)" << ((k12 != k12) ? "error" : "ok") << std::endl;
  std::cout << "(1,2) < (1,2)" << ((k12 < k12) ? "error" : "ok") << std::endl;
  std::cout << "(1,2) == (4,3)" << ((k12 == k43) ? "error" : "ok") << std::endl;
  std::cout << "(1,2) != (4,3)" << ((k12 != k43) ? "ok" : "error") << std::endl;

  std::cout << "(1,2) =? " << k12 << std::endl;
  Koordinate x;
  std::cout << "Geben Sie 5 7 ein:" << std::endl;
  std::cin >> x;
  std::cout << x << " == " << Koordinate(5, 7)
            << ((x == Koordinate(5, 7)) ? "ok" : "error") << std::endl;

  std::cout << "###########################################################\n";
  std::cout << "Teste Karte:\n";
  Karte karte;
  std::cout << "Abstand " << k12 << " und " << k12 << ":"
            << karte.abstand(k12, k12) << " "
            << ((karte.abstand(k12, k12) == 0) ? "ok" : "error") << std::endl;
  std::cout << "Abstand " << k12 << " und " << k43 << ":"
            << karte.abstand(k12, k43) << " "
            << ((karte.abstand(k12, k43) == 3) ? "ok" : "error") << std::endl;
  std::cout << "Abstand " << k43 << " und " << k12 << ":"
            << karte.abstand(k43, k12) << " "
            << ((karte.abstand(k43, k12) == 3) ? "ok" : "error") << std::endl;
  std::cout << "Abstand " << k12 << " und " << k15 << ":"
            << karte.abstand(k12, k15) << " "
            << ((karte.abstand(k12, k15) == 3) ? "ok" : "error") << std::endl;

  std::ifstream f("karte.txt");
  f >> karte;
  f.close();
  std::cout << "Eingelesene Karte:\n";
  std::cout << karte;

  std::cout << "Karte mit Pfad:\n";
  std::list<Koordinate> testPfad = {Koordinate(1, 2), Koordinate(1, 3),
                                    Koordinate(1, 4)};
  karte.print(testPfad);

  Koordinate kn(13, 5);
  std::list<Koordinate> nachbarn = karte.nachbarn(kn);
  std::cout << "Nachbarn von " << kn << ":";
  for (std::list<Koordinate>::const_iterator i = nachbarn.begin();
       i != nachbarn.end(); ++i) {
    std::cout << *i << " ";
  }
  std::cout << std::endl;
}
