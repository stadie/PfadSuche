//
// Created by stadie on 7/2/18.
//

#include "Astar.hh"
#include <algorithm>
#include <iostream>
// program a-star
//     // Initialisierung der Open List, die Closed List ist noch leer
//     // (die Priorität bzw. der f Wert des Startknotens ist unerheblich)
//     openlist.enqueue(startknoten, 0)
//     // diese Schleife wird durchlaufen bis entweder
//     // - die optimale Lösung gefunden wurde oder
//     // - feststeht, dass keine Lösung existiert
//     repeat
//         // Knoten mit dem geringsten Heuristik(f) Wert aus der Open List
//         entfernen
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

// // überprüft alle Nachfolgeknoten und fügt sie der Open List hinzu, wenn
// entweder
// // - der Nachfolgeknoten zum ersten Mal gefunden wird oder
// // - ein besserer Weg zu diesem Knoten gefunden wird
// function expandNode(currentNode)
//     foreach successor of currentNode
//         // wenn der Nachfolgeknoten bereits auf der Closed List ist - tue
//         nichts
//         if closedlist.contains(successor) then
//             continue
//         // Heuristik (f) Wert für den neuen Weg berechnen:
//         // wenn der Nachfolgeknoten bereits auf der Open List ist,
//         // aber der neue Weg länger ist als der alte - tue nichts
//         if openlist.contains(successor) and f > openlist.find(successor).f
//         then
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
std::list<Coordinate> Astar::search(Map map, Coordinate start,
                                    Coordinate goal) {
  // fuege start zur offen Liste
  Node startknoten(start, 0, map.distance(start, goal), start);
  open_.push_back(startknoten);
  do {
    // Knoten mit dem geringsten Heuristik(f) Wert aus der Open List entfernen
    auto minele = min_element(open_.begin(), open_.end(), CompF());
    const Node &n = *minele;
    open_.remove(n);
    // zur Closed List hinzufuegen
    closed_[n.coord()] = n;

    // wurde das Ziel gefunden? Wenn ja, abbruch

    // Nachfolgeknoten(Nachbarn) auf die Open List setzen

    // fuer all Nachbarn:
    //        // wenn der Nachfolgeknoten bereits auf der Closed List ist - tue
    //        nichts
    // if(closed_.find(nn.coord()) == closed_.end();
    //        // Heuristik (f) Wert für den neuen Weg berechnen:
    //        // Vorgängerzeiger setzen

    //         // wenn der Nachfolgeknoten bereits auf der Open List ist,
    //         // aber der neue Weg länger ist als der alte - tue nichts

    //         // Vorgängerzeiger setzen

    //         // f Wert des Knotens in der Open List aktualisieren
    //         // bzw. Knoten mit f Wert in die Open List einfügen
  } while (!open_.empty());

  // Konstruiere Pfad; Ziel sollte in geschlossen sein, wenn Pfad gefunden.
  std::list<Coordinate> path;
  Node last = closed_[goal];

  // Kosmetik
  path.reverse();
  std::cout << "Pfadlaenge:" << path.size()
            << " Knoten in offen:" << open_.size()
            << " Knoten in geschklossen:" << closed_.size() << std::endl;
  // loesche Listen wieder
  open_.clear();
  closed_.clear();
  return path;
}
