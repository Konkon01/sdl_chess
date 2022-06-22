#ifndef PIECE_H
#define PIECE_H
#include <SDL2/SDL.h>

class Rook{
private:
  static SDL_Texture* light;
  static SDL_Texture* dark;
public:
  static SDL_Texture* get_light(SDL_Renderer* render);
  static SDL_Texture* get_dark(SDL_Renderer* render);
};

class Horse{
  private:
  static SDL_Texture* light;
  static SDL_Texture* dark;
public:
  static SDL_Texture* get_light(SDL_Renderer* render);
  static SDL_Texture* get_dark(SDL_Renderer* render);
};

class Bishop{
  private:
  static SDL_Texture* light;
  static SDL_Texture* dark;
public:
  static SDL_Texture* get_light(SDL_Renderer* render);
  static SDL_Texture* get_dark(SDL_Renderer* render);
};

class Queen{
  private:
  static SDL_Texture* light;
  static SDL_Texture* dark;
public:
  static SDL_Texture* get_light(SDL_Renderer* render);
  static SDL_Texture* get_dark(SDL_Renderer* render);
};

class King{
  private:
  static SDL_Texture* light;
  static SDL_Texture* dark;
public:
  static SDL_Texture* get_light(SDL_Renderer* render);
  static SDL_Texture* get_dark(SDL_Renderer* render);
};

class Pawn{
  private:
  static SDL_Texture* light;
  static SDL_Texture* dark;
public:
  static SDL_Texture* get_light(SDL_Renderer* render);
  static SDL_Texture* get_dark(SDL_Renderer* render);
};

#endif