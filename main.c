#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "solver.h"
#include "interactive.h"




void preset_one(char board[9][9], const char blank_tile) {
    // https://stackoverflow.com/questions/3409099/building-a-gui-for-a-sudoku-solver-complete-with-ascii-example
    board[0][0] = '5'; board[0][6] = '6'; board[0][8] = '1';
    board[1][0] = '6'; board[1][5] = '2'; board[1][6] = '4';
    board[2][3] = '7'; board[2][5] = '1'; board[2][8] = '2';

    board[3][2] = '4'; board[3][4] = '2'; board[3][7] = '3';
    board[4][1] = '3'; board[4][7] = '9';
    board[5][4] = '4';

    board[6][1] = '2'; board[6][3] = '1'; board[6][5] = '5'; board[6][6] = '9';
    board[7][3] = '6'; board[7][8] = '5';
    board[8][2] = '6'; board[8][4] = '3'; board[8][8] = '7';
}

void preset_two(char board[9][9], const char blank_tile) {
    board[0][1] = '1';   board[0][3] = '2';    board[0][5] = '8';
    board[1][3] = '7';    board[1][7] = '2';     board[1][8] = '6';
    board[2][2] = '2';     board[2][3] = '1';     board[2][4] = '4';     board[2][7] = '9';

    board[3][5] = '2';     board[3][6] = '7';     board[3][8] = '1';
    //board[][] = '';
    board[5][0] = '3';     board[5][2] = '4';     board[5][3] = '8';

    board[6][1] = '3';     board[6][4] = '2';    board[6][5] = '7';     board[6][6] = '5';
    board[7][0] = '4';    board[7][1] = '8';     board[7][5] = '3';
    board[8][3] = '6';     board[8][5] = '1';     board[8][7] = '3';
}

void preset_hard(char board[9][9], const char blank_tile) {
    //https://en.wikipedia.org/wiki/Sudoku_solving_algorithms
    //a field designed to work against bruteforce
    //causing a huge amount of operations during backtracking

    board[1][5] ='3'; board[1][7] ='8'; board[1][8] ='5';
    board[2][2] ='1'; board[2][4] ='2';

    board[3][3] ='5'; board[3][5] ='7';
    board[4][2] ='4'; board[4][6] ='1';
    board[5][1] ='9';

    board[6][0] ='5'; board[6][7] ='7'; board[6][8] ='3';
    board[7][2] ='2'; board[7][4] ='1';
    board[8][4] ='4'; board[8][8] ='9';


}

void preset_custom(char board[9][9], const char blank_tile) {
    char* path = get_current_directory();
    if (path == NULL) {
        printf("Failed to get current directory.\n");
        free(path);
        return;
    }
    int path_len = strlen(path);
    char* filename = "/approve.txt";
    path = realloc(path, path_len + strlen(filename) + 1); // +1 for null terminator

    strcat(path, filename);




    FILE* fp = fopen(path, "w");
    if (fp) {
        fprintf(fp, "Change Case \n");
        fclose(fp);
    }
    free(path);


}

//expects a function pointer to a preset function
void presetBoard(char board[9][9], const char blank_tile, void (*preset_func)(char[9][9], char)) {

    preset_func(board, blank_tile);

}
void initBlankBoard(char board[9][9], char blankTile) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            board[row][col] = blankTile; //* as placeholder for empty board; needs to be passed to the solver
        }
    }
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
    const char blank_tile = ':';
    char board[9][9];
    initBlankBoard(board, blank_tile);


    printf("\tUse 1 for example 1\n\tUse 2 for example 2\n\tUse 3 for the worst possible backtracking layout\n\tUse 4 for a custom board\n");

    int option;
    printf("Type a number: \n");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Preset 1\n");
            presetBoard(board, blank_tile, preset_one);
            break;
        case 2:
            printf("Preset 2\n");
            presetBoard(board,  blank_tile, preset_two);
            break;
        case 3:
            printf("Preset hardest\n");
            presetBoard(board,  blank_tile, preset_hard);
            break;
        default:
            printf("Custom board\n");
            presetBoard(board, blank_tile, preset_custom);
    }


    //presetBoard(board, preset_two); // expects a function pointer to any of the preset functions
    // TODO: add a preset function that allows for user input, or at least preset selection during runtime


    printBoard(board);

    if (solve(board, blank_tile)) {
        printBoard(board);
    } else {
        printf("Board is not solvable!");
        return 1;
    }
    return 0;
}