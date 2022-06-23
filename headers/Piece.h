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
  static void destroy();
};

class Horse{
  private:
  static SDL_Texture* light;
  static SDL_Texture* dark;
public:
  static SDL_Texture* get_light(SDL_Renderer* render);
  static SDL_Texture* get_dark(SDL_Renderer* render);
  static void destroy();
};

class Bishop{
  private:
  static SDL_Texture* light;
  static SDL_Texture* dark;
public:
  static SDL_Texture* get_light(SDL_Renderer* render);
  static SDL_Texture* get_dark(SDL_Renderer* render);
  static void destroy();
};

class Queen{
  private:
  static SDL_Texture* light;
  static SDL_Texture* dark;
public:
  static SDL_Texture* get_light(SDL_Renderer* render);
  static SDL_Texture* get_dark(SDL_Renderer* render);
  static void destroy();
};

class King{
  private:
  static SDL_Texture* light;
  static SDL_Texture* dark;
public:
  static SDL_Texture* get_light(SDL_Renderer* render);
  static SDL_Texture* get_dark(SDL_Renderer* render);
  static void destroy();
};

class Pawn{
  private:
  static SDL_Texture* light;
  static SDL_Texture* dark;
public:
  static SDL_Texture* get_light(SDL_Renderer* render);
  static SDL_Texture* get_dark(SDL_Renderer* render);
  static void destroy();
};

#endif