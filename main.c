#include <stdio.h>
#include "sudoku.h"

int main (void){
	int grid[LENGTH_GRID][LENGTH_GRID];
	int i;

	for (i=0;i<LENGTH_GRID;i++){
		set_minus_one(grid[i],LENGTH_GRID);
	}

	for(i=0;i<LENGTH_GRID;i++){
		grid[i][0] = i;
	}

	if(verify_col_row(grid,0,COL) == 0){
		printf("OK: col is valid!\n");
	}
	else{
		printf("KO\n");
	}

	grid[3][0] = 7;

	if(verify_col_row(grid,0,COL) != 0){
		printf("OK: col is invalid!\n");
	}
	else{
		printf("KO\n");
	}

	for(i=0;i<LENGTH_GRID;i++){
		grid[1][i] = i;
	}

	if(verify_col_row(grid,1,ROW) == 0){
		printf("OK: col is valid!\n");
	}
	else{
		printf("KO\n");
	}


	return 0;
}