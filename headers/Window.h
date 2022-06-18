#ifndef WINDOW_H
#define WINDOW_H
#include <SDL2/SDL.h>

#define WIN_WIDTH 640
#define WIN_HEIGHT 720

class Window{
private:
  static SDL_Window* win;
  Window();
public:
  static SDL_Window* get_window();
  static void destroy_window();
};

#endif