#include <iostream>
#include <string>
#include <vector>
#include <limits>

inline
//check the current state of the game
void checkBoard(std::vector<std::vector<char>> b) {
  for (int i = 0; i < 3; i++) {
    std::cout << b[i][0] << "|" 
         << b[i][1] << "|"
         << b[i][2] << "\n";
    if (i < 2) {
      std::cout << "_ _ _\n";
    }
  }
}

//mark player's move
std::vector<std::vector<char>> setMark(std::vector<std::vector<char>> b, int pos, char m) {
  b[(pos - 1) / 3][(pos - 1) % 3] = m;
  return b;
}

//prompt player and return their input
int getPos(std::vector<std::vector<char>> b, int player) {
  int position = 0;
  std::cout << "__________________________________\n"
            << "PLAYER " << player << " TURN\n"
            << "Select where to play (1-9)\n\n"
            << "1|2|3\n"
            << "- - -\n"
            << "4|5|6\n"
            << "- - -\n"
            << "7|8|9\n\n";
  while (true) {
    std::cout << "Your turn: ";
    std::cin >> position;
    if (std::cin.fail()) {
      // Clear the error flag
      std::cin.clear();
      // Ignore the remaining characters in the input buffer
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      std::cout << "Invalid input. Please enter an integer (1-9).\n";
    } else {  
      if (position < 1 || position > 9){
        std::cout << "Invalid input. Please enter an integer (1-9).\n";
      } else if (b[(position - 1) / 3][(position - 1) % 3] != '.') {
        std::cout << "This position is not available.\n"
                  << "---CURRENT GAME---\n";
        checkBoard(b);
      } else {
        return position;
      }
    }
  }
}

bool isWinner (std::vector<std::vector<char>> b, int p) {
  int row = (p - 1) / 3;
  int col = (p - 1) % 3;

  //check vertical
  if (b[row][0] == b[row][1] && b[row][1] == b[row][2]) {
    return true;
  }
  //check horizonal 
  if (b[0][col] == b[1][col] && b[1][col] == b[2][col]) {
    return true;
  }
  //check diagonal
  if (p == 1 || p == 5 || p == 9) {
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2]) {
      return true;
    }
  } else {
    if (b[0][2] == b[1][1] && b[1][1] == b[2][0]) {
      return true;
    }
  }
  return false;
}
