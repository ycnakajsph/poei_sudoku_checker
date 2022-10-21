#ifndef SUDOKU_HEADER
#define SUDOKU_HEADER

#define LENGTH_GRID 9
#define FOUND 1
#define COL 0
#define ROW 1

void print_grid(int grid[LENGTH_GRID][LENGTH_GRID]);

void set_minus_one(int tab[], int sizetab);

int verify_cols(int grid[LENGTH_GRID][LENGTH_GRID]);
int verify_rows(int grid[LENGTH_GRID][LENGTH_GRID]);
int verify_sub_arrays(int grid[LENGTH_GRID][LENGTH_GRID]);

// verify_col_row takes 3 args: the grid, the index of the col or row to verify,
// and a variable containing COL or ROW
int verify_col_row(int grid[LENGTH_GRID][LENGTH_GRID], int index, int col_row);
int verify_sub_array(int grid[LENGTH_GRID][LENGTH_GRID],int index);

#endif