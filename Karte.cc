#include "Karte.hh"


std::list<Koordinate> Karte::nachbarn(const Koordinate& k) const {
  std::list<Koordinate> klist;
  for(int x = k.x() -1 ; x <= k.x()+1 ; ++x) {
      for(int y = k.y() -1 ; y <= k.y()+1 ; ++y) {
          Koordinate nk(x,y);
          if(nk == k) continue;
          if((*this)(nk)) klist.push_back(nk);
      }
  }
  return klist;
}

void Karte::print(const std::list<Koordinate>& pfad) const {
  for(int y = 0  ; y < hoehe() ; ++y) {
       for(int x = 0 ; x < breite() ; ++x) {
           Koordinate k(x,y);
           if(find(pfad.begin(),pfad.end(),k) != pfad.end())  {
             std::cout << 'p';
           } else {
           std::cout << (this->operator()(k)  ? '.' : 'X');
           }
       }
       std::cout << std::endl;
   }
}


std::ostream& operator<<(std::ostream& os, const Karte& k) {
  os << k.breite() << std::endl;
  os << k.hoehe() << std::endl;
  for(int y = 0  ; y < k.hoehe() ; ++y) {
      for(int x = 0 ; x < k.breite() ; ++x) {
          os << (k(Koordinate(x,y)) ? '.' : 'X');
      }
      os << std::endl;
  }
  return os;
}

std::istream& operator>>(std::istream& is, Karte& k) {
  int b,h;
  is >> b >> h;
  k.felder_.resize(b);
  for(int x = 0 ; x < b ; ++x) {
      k.felder_[x].resize(h);
  }
  for(int y = 0  ; y < k.hoehe() ; ++y) {
      for(int x = 0 ; x < k.breite() ; ++x) {
          char c;
          is >> c;
          k.felder_[x][y] = (c == '.');
      }
  }
  return is;
}
