#include <stdio.h>
#include "sudoku.h"

int main (void){

	int i,j;

	int grid[LENGTH_GRID][LENGTH_GRID] = \
		{{1, 2, 3, 4, 5, 6, 7, 8, 9}, \
		{4, 5, 6, 7, 8, 9, 1, 2, 3}, \
		{7, 8, 9, 1, 2, 3, 4, 5, 6}, \
		{2, 3, 4, 5, 6, 7, 8, 9, 1}, \
		{5, 6, 7, 8, 9, 1, 2, 3, 4}, \
		{8, 9, 1, 2, 3, 4, 5, 6, 7}, \
		{3, 4, 5, 6, 7, 8, 9, 1, 2}, \
		{6, 7, 8, 9, 1, 2, 3, 4, 5}, \
		{9, 1, 2, 3, 4, 5, 6, 7, 8}};

	for (i=0;i<LENGTH_GRID;i++){
		for (j=0;j<LENGTH_GRID;j++){
			grid[i][j]--;
		}
	}

	if(verify_grid(grid) == 0){
		printf("the grid provided is ok!\n");
	}
	else{
		printf("the grid provided is ko!\n");
	}

	return 0;
}