#include "../headers/Piece.h"
#include "../headers/ErrorLoger.hpp"

#include <iostream>

//ROOK---------------
SDL_Texture* Rook::light = nullptr;
SDL_Texture* Rook::dark = nullptr;

SDL_Texture* Rook::get_light(SDL_Renderer* render){
  if(light == nullptr){
    SDL_Surface* temp = SDL_LoadBMP("../media/light/rook.bmp");
    if(temp == nullptr){
      ErrorLoger::LogError(std::cout, "Rook image loading");
      return nullptr;
    }
    SDL_Texture* light = SDL_CreateTextureFromSurface(render, temp);
    SDL_FreeSurface(temp);
  }

  return light;
}
SDL_Texture* Rook::get_dark(SDL_Renderer* render){
  if(dark == nullptr){
    SDL_Surface* temp = SDL_LoadBMP("../media/dark/rook.bmp");
    if(temp == nullptr){
      ErrorLoger::LogError(std::cout, "Rook image loading");
      return nullptr;
    }
    SDL_Texture* dark = SDL_CreateTextureFromSurface(render, temp);
    SDL_FreeSurface(temp);
  }

  return dark;
} 

//Horse-----------
SDL_Texture* Horse::light = nullptr;
SDL_Texture* Horse::dark = nullptr;

SDL_Texture* Horse::get_light(SDL_Renderer* render){
  if(light == nullptr){
    SDL_Surface* temp = SDL_LoadBMP("../media/light/horse.bmp");
    if(temp == nullptr){
      ErrorLoger::LogError(std::cout, "Horse image loading");
      return nullptr;
    }
    SDL_Texture* light = SDL_CreateTextureFromSurface(render, temp);
    SDL_FreeSurface(temp);
  }

  return light;
}
SDL_Texture* Horse::get_dark(SDL_Renderer* render){
  if(dark == nullptr){
    SDL_Surface* temp = SDL_LoadBMP("../media/dark/horse.bmp");
    if(temp == nullptr){
      ErrorLoger::LogError(std::cout, "Horse image loading");
      return nullptr;
    }
    SDL_Texture* dark = SDL_CreateTextureFromSurface(render, temp);
    SDL_FreeSurface(temp);
  }

  return dark;
} 

//Bishop-----------
SDL_Texture* Bishop::light = nullptr;
SDL_Texture* Bishop::dark = nullptr;

SDL_Texture* Bishop::get_light(SDL_Renderer* render){
  if(light == nullptr){
    SDL_Surface* temp = SDL_LoadBMP("../media/light/rook.bmp");
    if(temp == nullptr){
      ErrorLoger::LogError(std::cout, "Bishop image loading");
      return nullptr;
    }
    SDL_Texture* light = SDL_CreateTextureFromSurface(render, temp);
    SDL_FreeSurface(temp);
  }

  return light;
}
SDL_Texture* Bishop::get_dark(SDL_Renderer* render){
  if(dark == nullptr){
    SDL_Surface* temp = SDL_LoadBMP("../media/dark/rook.bmp");
    if(temp == nullptr){
      ErrorLoger::LogError(std::cout, "Bishop image loading");
      return nullptr;
    }
    SDL_Texture* dark = SDL_CreateTextureFromSurface(render, temp);
    SDL_FreeSurface(temp);
  }

  return dark;
} 



//QUEEN-------------
SDL_Texture* Queen::light = nullptr;
SDL_Texture* Queen::dark = nullptr;

SDL_Texture* Queen::get_light(SDL_Renderer* render){
  if(light == nullptr){
    SDL_Surface* temp = SDL_LoadBMP("../media/light/queen.bmp");
    if(temp == nullptr){
      ErrorLoger::LogError(std::cout, "Queen image loading");
      return nullptr;
    }
    SDL_Texture* light = SDL_CreateTextureFromSurface(render, temp);
    SDL_FreeSurface(temp);
  }

  return light;
}
SDL_Texture* Queen::get_dark(SDL_Renderer* render){
  if(dark == nullptr){
    SDL_Surface* temp = SDL_LoadBMP("../media/dark/queen.bmp");
    if(temp == nullptr){
      ErrorLoger::LogError(std::cout, "Queen image loading");
      return nullptr;
    }
    SDL_Texture* dark = SDL_CreateTextureFromSurface(render, temp);
    SDL_FreeSurface(temp);
  }

  return dark;
} 


//KING-------------
SDL_Texture* King::light = nullptr;
SDL_Texture* King::dark = nullptr;

SDL_Texture* King::get_light(SDL_Renderer* render){
  if(light == nullptr){
    SDL_Surface* temp = SDL_LoadBMP("../media/light/king.bmp");
    if(temp == nullptr){
      ErrorLoger::LogError(std::cout, "King image loading");
      return nullptr;
    }
    SDL_Texture* light = SDL_CreateTextureFromSurface(render, temp);
    SDL_FreeSurface(temp);
  }

  return light;
}
SDL_Texture* King::get_dark(SDL_Renderer* render){
  if(dark == nullptr){
    SDL_Surface* temp = SDL_LoadBMP("../media/dark/king.bmp");
    if(temp == nullptr){
      ErrorLoger::LogError(std::cout, "King image loading");
      return nullptr;
    }
    SDL_Texture* dark = SDL_CreateTextureFromSurface(render, temp);
    SDL_FreeSurface(temp);
  }

  return dark;
} 

//PAWN-------------
SDL_Texture* Pawn::light = nullptr;
SDL_Texture* Pawn::dark = nullptr;

SDL_Texture* Pawn::get_light(SDL_Renderer* render){
  if(light == nullptr){
    SDL_Surface* temp = SDL_LoadBMP("../media/light/pawn.bmp");
    if(temp == nullptr){
      ErrorLoger::LogError(std::cout, "Pawn image loading");
      return nullptr;
    }
    SDL_Texture* light = SDL_CreateTextureFromSurface(render, temp);
    SDL_FreeSurface(temp);
  }

  return light;
}
SDL_Texture* Pawn::get_dark(SDL_Renderer* render){
  if(dark == nullptr){
    SDL_Surface* temp = SDL_LoadBMP("../media/dark/pawn.bmp");
    if(temp == nullptr){
      ErrorLoger::LogError(std::cout, "Pawn image loading");
      return nullptr;
    }
    SDL_Texture* dark = SDL_CreateTextureFromSurface(render, temp);
    SDL_FreeSurface(temp);
  }

  return dark;
} 
