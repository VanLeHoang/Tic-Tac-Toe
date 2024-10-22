#include <iostream>
#include <string>
#include <vector>
#include "f.hpp"

//set up the board
std::vector<std::vector<char>> board = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '},
};

int main() { 
  int turn = 0;
  char mark = ' ';
  int currPos = 0;

  std::cout << "WELCOME TO THE GAME OF TIC-TAC-TOE\n"
            << "Player 1: X\n"
            << "Player 2: O\n";

  //player take turn to play up to 9 times
  while (turn < 9) {
    if (turn % 2 == 0) {
      mark = 'X';
      currPos = getPos(board, 1);
      board = setMark(board, currPos, mark);
      turn++;
      std::cout << "\n---CURRENT GAME---\n\n";
      checkBoard(board);
      if (turn >= 5) {
        if (isWinner(board, currPos)) {
          std::cout << "\n*** PLAYER 1 WON ***";
          break;
        }
      }
    } else {
      mark = 'O';
      currPos = getPos(board, 2);
      board = setMark(board, currPos, mark);
      turn++;
      std::cout << "\n---CURRENT GAME---\n\n";
      checkBoard(board);
      if (turn >= 6) {
        if (isWinner(board, currPos)) {
          std::cout << "\n*** PLAYER 2 WON ***";
          break;
        }
      }
    }
  }
  std::cout << "\n*** IT'S A DRAW ***";
}
