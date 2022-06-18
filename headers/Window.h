#ifndef WINDOW_H
#define WINDOW_H
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 720

class Window{
private:
  static SDL_Window* win;
  Window();
  Window(const Window& w) = delete;
public:
  static SDL_Window* get_window();
  static void destroy_window();
};

#endif