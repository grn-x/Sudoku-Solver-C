# Sudoku Solver

A simple Sudoku solver implemented in C, using backtracking and bitmasking techniques.

## Getting Started


### Prerequisites
- C compiler (e.g., GCC)
- fuck make and cmake honestly

### Run

```shell
gcc main.c solver.c -o sudoku
./sudoku
```


## Overview
The solving logic is written in the `solver.c` file.
`main.c` is an abstracted console interaction layer and serves as the entry point.

Currently only hardcoded sudoku fields can be read. (This is subject to change, should I revisit this project).
See the `main.c` preset methods


## Motivation

This project was born out of sheer defiance against all my classmates who wrote their Sudoku solvers in Python.
If you're gonna commit the sin of brute-forcing, at least have some honor and do it in a low-level language.


### Technical Details

This solver implementation uses a dull brute force strategy instead of the much more elegant `Dancing Links` procedure as used in `Knuth's Algorithm X`
The board is represented by a 9x9 char array. 

For filling the tiles most efficiently, possible number candidates are created and then inserted, instead of iterating
over all numbers and checking if they are valid.
To achieve this, a bitmask is used to represent the possible candidates for each tile.


## License
This project is published under WTFPL; for further details refer to the `license.md` file or visit <https://www.wtfpl.net/>
