cmake_minimum_required(VERSION 3.3)
project(Solitaire)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES jeuSolitaire.cpp ContratException.h ContratException.cpp ColonneCartes.cpp ColonneCartes.h Carte.cpp Carte.h Solitaire.cpp Solitaire.h)
set(CMAKE_CXX_FLAGS "-static-libgcc -static-libstdc++")
add_executable(Solitaire ${SOURCE_FILES})