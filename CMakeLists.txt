cmake_minimum_required(VERSION 3.3)
project(Solitaire)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS -D__NO_INLINE__)
set(CMAKE_EXE_LINKER_FLAGS=-static)

set(SOURCE_FILES jeuSolitaire.cpp ContratException.h ContratException.cpp ColonneCartes.cpp ColonneCartes.h Carte.cpp Carte.h Solitaire.cpp Solitaire.h)
add_executable(Solitaire ${SOURCE_FILES})