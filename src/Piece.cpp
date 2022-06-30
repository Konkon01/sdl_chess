#include "../headers/Piece.h"
#include "../headers/ErrorLoger.hpp"

#include <iostream>

Piece::Piece(const char* light_path, const char* dark_path, SDL_Renderer* &renderer){
  //LIGHT
  SDL_Surface* light_surf = SDL_LoadBMP(light_path);
  if(light_surf == nullptr){
    ErrorLoger::LogError(std::cout, "Piece Surface creating");
  }
  light = SDL_CreateTextureFromSurface(renderer, light_surf);
  if(light == nullptr){
    ErrorLoger::LogError(std::cout, "Piece Texture creating");
  }
  SDL_FreeSurface(light_surf);

  //DARK
  SDL_Surface* dark_surf = SDL_LoadBMP(dark_path);
  if(dark_surf == nullptr){
    ErrorLoger::LogError(std::cout, "Piece Surface creating");
  }
  dark = SDL_CreateTextureFromSurface(renderer, dark_surf);
  if(dark == nullptr){
    ErrorLoger::LogError(std::cout, "Piece Texture creating");
  }
  SDL_FreeSurface(dark_surf);
}

  SDL_Texture* &Piece::get_light(){
    return light;
  }
  SDL_Texture* &Piece::get_dark(){
    return dark;
  }

Piece::~Piece(){
  SDL_DestroyTexture(light);
  SDL_DestroyTexture(dark);
}
