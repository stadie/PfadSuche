cmake_minimum_required(VERSION 3.10)
project(PfadSuche)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(pfad
        Map.cc
        Map.hh
        karte.txt
        Node.hh
        Coordinate.hh
        path.cc
        PathFinder.hh Astar.cc Astar.hh)

add_executable(unittest
        Map.cc
        Map.hh
        karte.txt
        Node.hh
        Coordinate.hh
        unittest.cc
        PathFinder.hh)

file(COPY karte.txt DESTINATION ${CMAKE_BINARY_DIR})