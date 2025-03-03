/*
This is the game logic file for my Text Teteris Game.

First step: Board Setup
Second step: Tetromino Representation
Third step: Spawning A New Piece
Fourth step: Moving The Piece
Fifth step: Collision Detection
Sixth step: Locking the Piece and Clearing Lines
Seventh step: Main Loop and Input Handling
(Bonus) step: Bonus Enhancements
*/

#include <iostream>
#include <vector>
using namespace std;

/* Board Setup:
Goal: Create a 2D “grid” to represent the playing area.
Dimensions: Traditionally, Tetris is 10 columns by 20 rows.
Method: Use a 2D vector of integers to represent the board.
*/

class Board
{

    void boardSetup()
    {
        vector<vector<int>> board(20, vector<int>(10, 0)); // 20 rows, 10 columns, initialized to 0
    }

    public:
    void testBoard (vector<vector<int>> board){
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                cout << board[i][j] << ". ";
            }
            cout << endl;
        }
    }

};