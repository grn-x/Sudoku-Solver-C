#include <stdio.h>
#include "solver.h"



void initBlankBoard(char board[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            board[row][col] = ':'; //* as placeholder for empty board; needs to be passed to the solver
        }
    }
}

void presetBoard(char board[9][9]) { //expect [9][9]
    // Hardcoded values
    // https://stackoverflow.com/questions/3409099/building-a-gui-for-a-sudoku-solver-complete-with-ascii-example
    /*board[0][0] = '5'; board[0][6] = '6'; board[0][8] = '1';
    board[1][0] = '6'; board[1][5] = '2'; board[1][6] = '4';
    board[2][3] = '7'; board[2][5] = '1'; board[2][8] = '2';

    board[3][2] = '4'; board[3][4] = '2'; board[3][7] = '3';
    board[4][1] = '3'; board[4][7] = '9';
    board[5][4] = '4';

    board[6][1] = '2'; board[6][3] = '1'; board[6][5] = '5'; board[6][6] = '9';
    board[7][3] = '6'; board[7][8] = '5';
    board[8][2] = '6'; board[8][4] = '3'; board[8][8] = '7';*/

    board[0][1] = '1';    board[0][3] = '2';    board[0][5] = '8';
    board[1][3] = '7';    board[1][7] = '2';     board[1][8] = '6';
    board[2][2] = '2';     board[2][3] = '1';     board[2][4] = '4';     board[2][7] = '9';

    board[3][5] = '2';     board[3][6] = '7';     board[3][8] = '1';
    //board[][] = '';
    board[5][0] = '3';     board[5][2] = '4';     board[5][3] = '8';

    board[6][1] = '3';     board[6][4] = '2';    board[6][5] = '7';     board[6][6] = '5';
    board[7][0] = '4';    board[7][1] = '8';     board[7][5] = '3';
    board[8][3] = '6';     board[8][5] = '1';     board[8][7] = '3';

}

void printBoard_loop(char board[9][9]) { //expect [9][9]
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }

}

void printBoard_utf(char board[9][9]) {
    printf("╔═══════════╤═══════════╤═══════════╗\n");
    for (int row = 0; row < 9; row++) {
        printf("║ ");
        for (int col = 0; col < 9; col++) {
            printf("%c ", board[row][col]);
            if (col % 3 == 2 && col != 8) {
                printf("│ ");
            }
        }
        printf("║\n");
        if (row % 3 == 2 && row != 8) {
            printf("╟───────────┼───────────┼───────────╢\n");
        }
    }
    printf("╚═══════════╧═══════════╧═══════════╝\n");
}


void printBoard(char board[9][9]) {
    printf("+-----------------------+\n");
    for (int row = 0; row < 9; row++) {
        printf("| ");
        for (int col = 0; col < 9; col++) {
            printf("%c ", board[row][col]);
            if (col % 3 == 2 && col != 8) {
                printf("| ");
            }
        }
        printf("|\n");
        if (row % 3 == 2 && row != 8) {
            printf("|-----------------------|\n");
        }
    }
    printf("+-----------------------+\n");
}

int main(int argc, char* argv[]) {
    char board[9][9];
    initBlankBoard(board);
    presetBoard(board);
    printBoard(board);


    if (solve(board, ':')) {
        printBoard(board);
        //waitForExit();
    } else {
        printf("ERROR: This board is not solvable!");
    }
    return 1;
}


/* int to char */
char int_to_char(const int val) {
    return 0+val;
}

