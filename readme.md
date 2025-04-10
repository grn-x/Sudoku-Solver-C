# Sudoku Solver

A simple Sudoku solver implemented in C, using backtracking and bitmasking techniques.

## Getting Started


### Prerequisites
- C compiler (e.g., GCC)

### Run

```shell
gcc main.c solver.c syscomm.c -o sudoku
./sudoku
```


## Overview
The project is structured three different files.
`main.c` serves as the entry point of the program, responsible for initializing the `solver.c` state and handling/delegating user input.
In case of custom board input, `main.c` manages os-specific file I/O operations through `syscomm.c`.

> [!IMPORTANT]  
> As a result of this `syscomm.c` needs to be recompiled for each OS. 

<!-- The `syscomm.c` file contains the logic for an interactive way to interface with the programm during runtime, which allows users to input Sudoku puzzles and view the solutions. -->


## Motivation

This project was born out of sheer defiance against all my classmates who wrote their Sudoku solvers in Python.
If you're gonna commit the sin of brute-forcing, at least have some honor and do it in a low-level language.


### Technical Details

This solver implementation uses a dull brute force strategy instead of the much more elegant `Dancing Links` procedure as used in `Knuth's Algorithm X`
The board is represented by a 9x9 char array. 

For filling the tiles most efficiently, possible number candidates are first calculated and then inserted, instead of iterating
over all numbers and checking if they are valid.
To achieve this, a bitmask representing the possible candidates for each tile, is used


## License
This project is published under WTFPL; for further details refer to the `license.md` file or visit <https://www.wtfpl.net/>
