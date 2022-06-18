#include "../headers/Window.h"
#include "../headers/ErrorLoger.hpp"
#include <SDL2/SDL.h>
#include <iostream>

SDL_Window *Window::win = nullptr;

SDL_Window *Window::get_window(){
  
  if(win == nullptr){
    win = SDL_CreateWindow("Chess Game",
                          SDL_WINDOWPOS_CENTERED,
                          SDL_WINDOWPOS_CENTERED,
                          SCREEN_WIDTH,
                          SCREEN_HEIGHT,
                          SDL_WINDOW_SHOWN);

    if (win == nullptr){
      ErrorLoger::LogError(std::cout, "Window creating");
      SDL_Quit();
    }
    SDL_SetWindowResizable(win, SDL_FALSE);
  }
  return win;
}

void Window::destroy_window(){
  SDL_DestroyWindow(win);
}
