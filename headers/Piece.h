#ifndef PIECE_H
#define PIECE_H
#include <SDL2/SDL.h>

class Rook{
private:
  static SDL_Texture* light;
  static SDL_Texture* dark;
public:
  static SDL_Texture* get_light();
  static SDL_Texture* get_dark();
};

class Horse{
  private:
  static SDL_Texture* light;
  static SDL_Texture* dark;
public:
  static SDL_Texture* get_light();
  static SDL_Texture* get_dark();
};

class Bishop{
  private:
  static SDL_Texture* light;
  static SDL_Texture* dark;
public:
  static SDL_Texture* get_light();
  static SDL_Texture* get_dark();
};

class Queen{
  private:
  static SDL_Texture* light;
  static SDL_Texture* dark;
public:
  static SDL_Texture* get_light();
  static SDL_Texture* get_dark();
};

class King{
  private:
  static SDL_Texture* light;
  static SDL_Texture* dark;
public:
  static SDL_Texture* get_light();
  static SDL_Texture* get_dark();
};

class Pawn{
  private:
  static SDL_Texture* light;
  static SDL_Texture* dark;
public:
  static SDL_Texture* get_light();
  static SDL_Texture* get_dark();
};

#endif