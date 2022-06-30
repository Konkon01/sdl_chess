#ifndef PIECE_H
#define PIECE_H
#include <SDL2/SDL.h>

class Piece {
protected:
  SDL_Texture* light;
  SDL_Texture* dark;
  Piece(const char* light_path, const char* dark_path, SDL_Renderer* &renderer);

public:
  virtual ~Piece();

  SDL_Texture* &get_light();
  SDL_Texture* &get_dark();
};

class Rook : public Piece{
public:
  Rook(SDL_Renderer* &renderer)
    : Piece("./media/light/l_rook.bmp","./media/dark/d_rook.bmp",renderer){}
};

class Horse : public Piece{
public:
  Horse(SDL_Renderer* &renderer)
    : Piece("./media/light/l_horse.bmp","./media/dark/d_horse.bmp",renderer){}
};

class Bishop : public Piece{
public:
  Bishop(SDL_Renderer* &renderer)
    : Piece("./media/light/l_bishop.bmp","./media/dark/d_bishop.bmp",renderer){}
};

class Queen : public Piece{
public:
  Queen(SDL_Renderer* &renderer)
    : Piece("./media/light/l_queen.bmp","./media/dark/d_queen.bmp",renderer){}
};

class King : public Piece{
public:
  King(SDL_Renderer* &renderer)
    : Piece("./media/light/l_king.bmp","./media/dark/d_king.bmp",renderer){}
};

class Pawn : public Piece{
public:
  Pawn(SDL_Renderer* &renderer)
    : Piece("./media/light/l_pawn.bmp","./media/dark/d_pawn.bmp",renderer){}
};

#endif