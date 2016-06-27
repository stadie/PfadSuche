#include "Karte.hh"

std::list<Koordinate> Karte::nachbarn(const Koordinate& k) const {
  std::list<Koordinate> klist;
  return klist;
}

void Karte::print(const std::list<Koordinate>& pfad) const {
  for (int y = 0; y < hoehe(); ++y) {
    for (int x = 0; x < breite(); ++x) {
      Koordinate k(x, y);
      if (find(pfad.begin(), pfad.end(), k) != pfad.end()) {
        std::cout << 'p';
      } else {
        std::cout << (this->operator()(k) ? '.' : 'X');
      }
    }
    std::cout << std::endl;
  }
}

std::ostream& operator<<(std::ostream& os, const Karte& k) {
  os << k.breite() << std::endl;
  os << k.hoehe() << std::endl;
  for (int y = 0; y < k.hoehe(); ++y) {
    for (int x = 0; x < k.breite(); ++x) {
      os << (k(Koordinate(x, y)) ? '.' : 'X');
    }
    os << std::endl;
  }
  return os;
}

std::istream& operator>>(std::istream& is, Karte& k) {
  // lese Karte
  return is;
}
