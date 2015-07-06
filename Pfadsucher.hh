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
//         // Knoten mit dem geringsten Heuristik(f) Wert aus der Open List entfernen
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
//         // Heuristik (f) Wert für den neuen Weg berechnen:
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
  HeuristikVergleich<Heuristik> vergleicheHeuristik(f);
  //fuege start zur offen Liste
  Knoten startknoten(start,0,karte_.abstand(start,ziel),start);
  offen_.push_back(startknoten);
  do {
      // Knoten mit dem geringsten Heuristik(f) Wert aus der Open List entfernen
      std::list<Knoten>::const_iterator minele = min_element(offen_.begin(),offen_.end(),vergleicheHeuristik);
      const Knoten& minknoten = *minele;
      offen_.remove(minknoten);
      // Knoten zur geschlossen Liste hinzufuegen

      // wurde das Ziel gefunden? Wenn ja, abbruc

      // Nachfolgeknoten(Nachbarn) auf die Open List setzen


      //fuer all Nachbarn:
      //        // wenn der Nachfolgeknoten bereits auf der Closed List ist - tue nichts

      //        // Heuristik (f) Wert für den neuen Weg berechnen:
      //        // Vorgängerzeiger setzen

      //         // wenn der Nachfolgeknoten bereits auf der Open List ist,
      //         // aber der neue Weg länger ist als der alte - tue nichts

      //         // Vorgängerzeiger setzen

      //         // f Wert des Knotens in der Open List aktualisieren
      //         // bzw. Knoten mit f Wert in die Open List einfügen
  } while (! offen_.empty());

  //Konstruiere Pfad; Ziel sollte in geschlossen sein, wenn Pfad gefunden.
  std::list<Koordinate> pfad;

  //Kosmetik
  pfad.reverse();
  std::cout << "Pfadlaenge:" << pfad.size() << " Knoten in offen:" << offen_.size() << " Knoten in geschklossen:"
      << geschlossen_.size() << std::endl;
  //loesche Listen wieder
  offen_.clear();
  geschlossen_.clear();
  return pfad;
} 



#endif
