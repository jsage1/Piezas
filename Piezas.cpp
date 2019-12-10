#include "Piezas.h"
#include<vector>

/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
    //resizing and initializing the board
    board.resize(3);
    for(int i =0; i < (int)board.size(); i++)
    {
        board[i].resize(4);
    }

    for(int i =0; i < (int)board.size(); i++)
    {
        for(int j=0; j < (int)board[i].size();j++)
        {
            board[i][j] = Blank;
        }
    }

    //resizing and initializing the iterator for levels
    levels.resize(4);
    for(int x = 0; x < (int)levels.size(); x++)
    {
        levels[x] = 0;
    }

    //first turn = X
    turn = X;

}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
    //resizing and initializing the board
    board.resize(3);
    for(int i =0; i < (int)board.size(); i++)
    {
        board[i].resize(4);
    }

    for(int i =0; i < (int)board.size(); i++)
    {
        for(int j=0; j < (int)board[i].size();j++)
        {
            board[i][j] = Blank;
        }
    }

    //resizing and initializing the iterator for levels
    levels.resize(4);
    for(int x = 0; x < (int)levels.size(); x++)
    {
        levels[x] = 0;
    }

    //first turn = X
    turn = X;
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
    Piece current = turn;

    if(turn == X)
    {
        turn = O;
    }else
    {
        turn = X;
    }
    

    if(column > 3)
    {
        return Invalid;
    }

    if(levels[column] == 3)
    {
        return Blank;
    }

    board[levels[column]][column] = current;
    levels[column]++;

    return current;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
    if(column >= 4 || row >= 3)
    {
        return Invalid;
    }

    return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
    for(int i =0; i < (int)board.size(); i++)
    {
        for(int j=0; j < (int)board[i].size();j++)
        {
            if(board[i][j] == Blank)
            {
                return Invalid;
            }
        }
    }

    int max_x = 0;
    int current_x = 0;

    int max_y = 0;
    int current_y = 0;

    for(int i =0; i < (int)board.size(); i++)
    {
        for(int j=0; j < (int)board[i].size();j++)
        {
            if(board[i][j] == X)
            {
                current_x++;
                if(current_y > max_y)
                {
                    max_y = current_y;
                    
                }
                current_y = 0;

            }else
            {
                current_y++;
                if(current_x > max_x)
                {
                    max_x = current_x;
                    
                }
                current_x = 0;
            }
            
        }
    }   

    for(int j =0; j < (int)board[0].size(); j++)
    {
        for(int i=0; i < (int)board.size();i++)
        {
            if(board[i][j] == X)
            {
                current_x++;
                if(current_y > max_y)
                {
                    max_y = current_y;
                    
                }
                current_y = 0;
                
            }else
            {
                current_y++;
                if(current_x > max_x)
                {
                    max_x = current_x;
                    
                }
                current_x = 0;
            }
            
        }
    } 

    if(max_y == max_x)
    {
        return Blank;
    }else if(max_y >= max_x)
    {
        return O;
    }else
    {
        return X;
    }
    
    
}