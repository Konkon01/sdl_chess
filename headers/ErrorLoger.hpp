#ifndef ERRORLOGER_H
#define ERRORLOGER_H
#include <iostream>
#include <SDL2/SDL.h>

class ErrorLoger {
public:
  static void LogError(std::ostream &os, const char* msg){
    os << msg << " error " << SDL_GetError() << std::endl;
  }
};

#endif