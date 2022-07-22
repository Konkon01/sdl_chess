#include "../headers/Renderer.h"
#include "../headers/Piece.h"
#include "../headers/ErrorLoger.hpp"
#include "../headers/Field.h"

Renderer::Renderer(SDL_Window *&w, Board *b)
{
  rend = SDL_CreateRenderer(w, -1, 0);
  board = b;
  pieces.push_back(new Pawn(rend));
  pieces.push_back(new Rook(rend));
  pieces.push_back(new Horse(rend));
  pieces.push_back(new Bishop(rend));
  pieces.push_back(new Queen(rend));
  pieces.push_back(new King(rend));
}
Renderer::~Renderer()
{
  SDL_DestroyRenderer(rend);
  for (unsigned int i = 0; i < pieces.size(); i++)
  {
    delete pieces.at(i);
  }
}

void Renderer::render_board(std::set<int> &possible_moves)
{
  SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
  SDL_RenderClear(rend);
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {

      if (is_possible_move(i * 8 + j, possible_moves))
      {
        if (i % 2 == 0)
        {
          (j % 2 == 0) ? SDL_SetRenderDrawColor(rend, 77, 191, 217, 255) : SDL_SetRenderDrawColor(rend, 30, 129, 176, 255);
        }
        else
        {
          (j % 2 == 0) ? SDL_SetRenderDrawColor(rend, 30, 129, 176, 255) : SDL_SetRenderDrawColor(rend, 77, 191, 217, 255);
        }
      }
      else
      {
        if (i % 2 == 0)
        {
          (j % 2 == 0) ? SDL_SetRenderDrawColor(rend, 238, 238, 213, 255) : SDL_SetRenderDrawColor(rend, 125, 148, 93, 255);
        }
        else
        {
          (j % 2 == 0) ? SDL_SetRenderDrawColor(rend, 125, 148, 93, 255) : SDL_SetRenderDrawColor(rend, 238, 238, 213, 255);
        }
      }
      SDL_Rect rect = {
          j * FIELD_WIDTH,
          i * FIELD_HEIGHT,
          FIELD_WIDTH,
          FIELD_HEIGHT};
      SDL_RenderFillRect(rend, &rect);

      char piece_char = board->board[i * 8 + j];
      if (piece_char != 'x')
      {
        int piece_index = get_piece_index(piece_char);
        SDL_Texture *piece_texture = //(ASCII: A-Z 65-90) piece_char < 91 => piece_char is capital letter => piece is light
            (piece_char < 91) ? pieces.at(piece_index)->get_light() : pieces.at(piece_index)->get_dark();

        SDL_RenderCopy(rend, piece_texture, NULL, &rect);
      }
    }
  }
  SDL_RenderPresent(rend);
}

int Renderer::get_piece_index(char piece_char)
{
  int res;
  if (piece_char == 'x')
  {
    res = -1;
  }
  else if (piece_char == 'P' || piece_char == 'p')
  {
    res = 0;
  }
  else if (piece_char == 'R' || piece_char == 'r')
  {
    res = 1;
  }
  else if (piece_char == 'H' || piece_char == 'h')
  {
    res = 2;
  }
  else if (piece_char == 'B' || piece_char == 'b')
  {
    res = 3;
  }
  else if (piece_char == 'Q' || piece_char == 'q')
  {
    res = 4;
  }
  else if (piece_char == 'K' || piece_char == 'k')
  {
    res = 5;
  }
  return res;
}

bool Renderer::is_possible_move(int p_ind, std::set<int> &possible_moves)
{
  for (int ind : possible_moves)
  {
    if (p_ind == ind)
      return true;
  }
  return false;
}