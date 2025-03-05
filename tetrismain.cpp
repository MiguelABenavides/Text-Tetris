#include "gamelogic.h"
#include <iostream>

using namespace std;

int main() {

    cout << "Welcome to Text Tetris!" << endl;
    Board board;   // Create a board object
    vector<vector<int> > testBoard(20, vector<int>(10, 0)); // Create a test board
    board.testBoard(testBoard); // Test the board
}
