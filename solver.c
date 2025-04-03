#include "solver.h"
#include <stdio.h>
#include <stdbool.h>

char BLANK_TILE;


int tileValue(char board[9][9], int row, int col) {
    /* get the integer value of a tile
    return -1 if the tile is empty */
    if (board[row][col] == BLANK_TILE) {
        return -1;
    } else {
      //printf("board[row][col]: %c\n", board[row][col]);
        return board[row][col] - '0';
    }
}

char intToChar(int value) {
    /* convert an integer into a sudoku number (0 -> '1', 1 -> '2', etc.)*/
    return '0' + value;
}


int colUsed(char board[9][9], int col) {
    int bits = 0;
    for (int row = 0; row < 9; row++) {  // Fixed: increment row
        int value = tileValue(board, row, col);
        if (value != -1) {
            bits |= (1 << value);
        }
    }
    return bits;
}

int rowUsed(char board[9][9], int row) {
    int bits = 0;
    for (int col = 0; col < 9; col++) {
        int value = tileValue(board, row, col);
        if (value != -1) {
            // Set the corresponding bit (0 for number 1, 1 for number 2, etc.)
            bits |= (1 << value);
        }
    }
    return bits;
}

int squareUsed(char board[9][9], int row, int col){
//get top left tile:

// x= 0,1,2 -> 0; 3,4,5 -> 1; 6,7,8 -> 2
//int top = row - (row % 3)/3; // (x/3)*3
//int left = col - (col % 3)/3;
//floor - cast

int top = (row / 3) * 3;
int left = (col / 3) * 3;


int bits = 0;

for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        int value = tileValue(board, top + i, left + j);
        if (value != -1) {
            // Set the corresponding bit (0 for number 1, 1 for number 2, etc.)
            bits |= (1 << value);
        }
    }

}
    return bits;
}


int getPossibleValues(char board[9][9], int row, int col, int possibleValuesRef[9]) {
  /** return the possible value ref array index pointer; fill the possibleValueRef array passed as param*/
    /* get all possible values for a tile */
    int possibleBits = ~(colUsed(board, col) | rowUsed(board, row) | squareUsed(board, row, col));
    //or all the bits together and invert the result to get the possible values
        //possibleValuesRef = {0}; want to reinitialize the array, to avoid errors
    int index_pointer = 0;
    for (int i = 1; i <= 9; i++) { //TODO: move this loop inside solveRecursive function, to avoid looping twice (even be it with a smaller range)
        if ((possibleBits >> i & 1) == 1) {//rightshift to move the i-th bit to the last place; AND with 1 (=0001) to
                                           // check if it is 1, in which case its a possible value
            possibleValuesRef[index_pointer++] = i;
        } else {
            //possibleValues[i] = 0;
        }
    }
    return index_pointer;
}

bool solveRecursive(char board[][9] /*looks weird with first dimension omitted*/, int row, int col){

    if (row == 9) {
        return true;
    }
    int nextrow = (col == 8 ? row + 1 : row);
    int nextcol = (col == 8 ? 0 : col + 1);

    //if the value at the current tile is not blank, skip to the next
    if(tileValue(board, row, col) != -1) {
        return solveRecursive(board, nextrow, nextcol);
    }

    //the current tile is empty:
    //try every possible value

    int possibleValues[9] = {0};
    int possibleValuesCount = getPossibleValues(board, row, col, possibleValues);
    if (possibleValuesCount == 0) {
        return false;
    }
    for (int i = 0; i < possibleValuesCount; i++) {
        int value = possibleValues[i];
        board[row][col] = intToChar(value);
        //add num value to potential square, col, row tracking arrays for performance benefits
        if (solveRecursive(board, nextrow, nextcol)) {
            return true;
        }
        //remove value from potential square, col, row
    }

    board[row][col] = BLANK_TILE;
  return false;
  }


bool solve(char board[9][9], char blankTile) {
    /* set up the recursion function and run it 
    return false if the board is unsolvable
    param: blankTile - the character that represents a blank tile
            board - an char array of 9x9 indices*/
    BLANK_TILE = blankTile;


    return solveRecursive(board, 0, 0);
}
