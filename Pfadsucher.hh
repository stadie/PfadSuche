#ifndef PFADSUCHER_HH
#define PFADSUCHER_HH

#include "Koordinate.hh"
#include "Knoten.hh"
#include "Karte.hh"

#include <list>
#include <algorithm>
#include <iostream>

class Pfadsucher {
public:
  Pfadsucher(const Karte& k);
  template<class Heuristik> std::list<Koordinate>  suche(Koordinate start, Koordinate ziel, Heuristik f);

  template<class Heuristik> class HeuristikVergleich {
  public:
    HeuristikVergleich(Heuristik f) : f_(f) {}
    bool operator()(const Knoten &a, const Knoten &b) {
      return f_(a) < f_(b);
    }
  private:
    Heuristik f_;
  };


private:
  std::list<Knoten> offen_;
  std::list<Knoten> geschlossen_;
  const Karte& karte_; 
};

//to get the template compiled the code has to be here
Pfadsucher::Pfadsucher(const Karte& k) : karte_(k) {
}



// program a-star
//     // Initialisierung der Open List, die Closed List ist noch leer
//     // (die Priorität bzw. der f Wert des Startknotens ist unerheblich)
//     openlist.enqueue(startknoten, 0)
//     // diese Schleife wird durchlaufen bis entweder
//     // - die optimale Lösung gefunden wurde oder
//     // - feststeht, dass keine Lösung existiert
//     repeat
//         // Knoten mit dem geringsten f Wert aus der Open List entfernen
//         currentNode := openlist.removeMin()
//         // wurde das Ziel gefunden?
//         if (currentNode == zielknoten) then
//             return PathFound
//         // Nachfolgeknoten auf die Open List setzen
//         expandNode(currentNode)
//         // der aktuelle Knoten ist nun abschließend untersucht
//         closedlist.add(currentNode)
//     until openlist.isEmpty()
//     // die Open List ist leer, es existiert kein Pfad zum Ziel
//     return NoPathFound
// end

// // überprüft alle Nachfolgeknoten und fügt sie der Open List hinzu, wenn entweder
// // - der Nachfolgeknoten zum ersten Mal gefunden wird oder
// // - ein besserer Weg zu diesem Knoten gefunden wird
// function expandNode(currentNode)
//     foreach successor of currentNode
//         // wenn der Nachfolgeknoten bereits auf der Closed List ist - tue nichts
//         if closedlist.contains(successor) then
//             continue
//         // f Wert für den neuen Weg berechnen: g Wert des Vorgängers plus die Kosten der
//         // gerade benutzten Kante plus die geschätzten Kosten von Nachfolger bis Ziel
//         f := g(currentNode) + c(currentNode, successor) + h(successor)
//         // wenn der Nachfolgeknoten bereits auf der Open List ist,
//         // aber der neue Weg länger ist als der alte - tue nichts
//         if openlist.contains(successor) and f > openlist.find(successor).f then
//             continue
//         // Vorgängerzeiger setzen
//         successor.predecessor := currentNode
//         // f Wert des Knotens in der Open List aktualisieren
//         // bzw. Knoten mit f Wert in die Open List einfügen
//         if openlist.contains(successor) then
//             openlist.decreaseKey(successor, f)
//         else
//             openlist.enqueue(successor, f)
//     end
// end
template<class Heuristik> std::list<Koordinate>  Pfadsucher::suche(Koordinate start, Koordinate ziel, Heuristik f)
{  
  std::list<Koordinate> pfad;
  HeuristikVergleich<Heuristik> vergleicheHeuristik(f);
  //fuege start zur offen Liste
  Knoten startknoten(start,0,karte_.abstand(start,ziel),start);
  offen_.push_back(startknoten);
  do {
    std::list<Knoten>::const_iterator minele = min_element(offen_.begin(),offen_.end(),vergleicheHeuristik);
    Knoten k = *minele;
    offen_.remove(*minele);
    geschlossen_.push_back(k);
    if(k == ziel)  break;
    std::list<Koordinate> nachbarn = karte_.nachbarn(k);
    for(std::list<Koordinate>::const_iterator i = nachbarn.begin(); i != nachbarn.end() ; ++i) {
        if(find(geschlossen_.begin(),geschlossen_.end(),*i) != geschlossen_.end()) continue;
        Knoten nk(*i,k.g()+1,karte_.abstand(nk,ziel),k);
        std::list<Knoten>::iterator offeniter =find(offen_.begin(),offen_.end(),*i);
        if(offeniter != offen_.end()) {
            Knoten& ok = *offeniter;
            if(f(nk) >= f(ok)) continue;
            ok = nk;
        } else {
            offen_.push_back(nk);
        }
    }
  } while (! offen_.empty());
  std::list<Knoten>::const_iterator iter = find(geschlossen_.begin(),geschlossen_.end(),ziel);
  if(iter != geschlossen_.end()) {
      pfad.push_back(*iter);
      do {
          iter = find(geschlossen_.begin(),geschlossen_.end(),iter->vorgaenger());
          pfad.push_back(*iter);
      } while (*iter != start);
      pfad.reverse();
  }
  //loesche Listen wieder
  std::cout << "Pfadlaenge:" << pfad.size() << " Knoten in offen:" << offen_.size() << " Knoten in geschklossen:"
            << geschlossen_.size() << std::endl;
  offen_.clear();
  geschlossen_.clear();
  return pfad;
} 



#endif
