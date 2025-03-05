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

The Board class represents the playing area of the Tetris game.
It contains methods to set up the board and manage its state.
*/

class Board
{
    vector<vector<int> > board; // Member variable to store the board

    public:
    void boardSetup()
    {
        board = vector<vector<int> >(20, vector<int>(10, 0)); // 20 rows, 10 columns, initialized to 0
    }

    void printBoard()
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
};

/* Tetromino Representation:
Goal: 
To represent each shape (e.g., I, O, T, L, J, S, Z) in a flexible way.
Dimensions: Typically each shape is stored within a 4×4 space
Method: Use a 2D vector of integers to represent each shape.
*/

class Tetromino
{
    vector<vector<int> > I =        // straight line of 4 blocks
    {
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    vector<vector<int> > O =        // square piece (2×2).
    {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    vector<vector<int> > T =        // T-shaped piece (three blocks in a row plus one block centered).
    {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    
    vector<vector<int> > S =        // The zig-zag piece, leans to the right at the top (when horizontal).
    {
        {0, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 0}
    };

    vector<vector<int> > Z =        // The zig-zag piece, leans to the left at the top (when horizontal).
    {
        {0, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0}
    };

    vector<vector<int> > J =        // backwards L shaped piece.
    {
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    vector<vector<int> > L =        // L shaped piece

    {
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };
};

/* Spawning A New Piece:
Goal: To spawn a random new Tetromino piece at the top of the board.
Method: Choose a random Tetromino shape and place it at the top center of the board.
*/

