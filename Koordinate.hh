#ifndef KOORDINATE_HH
#define KOORDINATE_HH

#include <iostream>

class Koordinate {
private:
  int x_, y_;
public:
  Koordinate(int x=0, int y=0) : x_(x),y_(y) {}

  int x() const { return x_;}
  int y() const { return y_;}


  bool operator==(const Koordinate& k) const { return x_ == k.x_ && y_ == k.y_;}
  bool operator!=(const Koordinate& k) const { return !(*this==k);}
  bool operator<(const Koordinate& k) const {
    if(x_ < k.x_) return true;
    if(x_ == k.x_) return y_ < k.y_;
    return false;
  }

  friend std::ostream& operator<<(std::ostream& os, const Koordinate& k) {
    os << "(" << k.x_ << "," << k.y_ << ")";
    return os;
  }
  friend std::istream& operator>>(std::istream& is, Koordinate& k) {
    is >> k.x_ >> k.y_;
    return is;
  }
};


#endif
