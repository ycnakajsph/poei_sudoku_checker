#include <stdio.h>
#include "sudoku.h"

void print_grid(int grid[LENGTH_GRID][LENGTH_GRID]){
	int i;
	int j;
	for (i=0;i<LENGTH_GRID;i++){
		for (j=0;j<LENGTH_GRID;j++){
			printf("%d |",grid[i][j]);
		}
		printf("\n");
	}
}

void set_minus_one(int tab[], int sizetab){
	int i;
	for (i=0;i<sizetab;i++){
		tab[i] = -1;
	}
}

int verify_col_row(int grid[LENGTH_GRID][LENGTH_GRID], int index, int col_row){
	int i;
	int found[LENGTH_GRID];
	set_minus_one(found,LENGTH_GRID);

	for(i=0;i<LENGTH_GRID;i++){
		if (col_row == ROW){
			found[grid[index][i]] += FOUND;
		}
		else{
			found[grid[i][index]] += FOUND;
		}
	}

	for (i=0;i<LENGTH_GRID;i++){
		if (found[i] != FOUND){
			return -1;
		}
	}
	return 0;
}


int verify_sub_array(int grid[LENGTH_GRID][LENGTH_GRID],int index){
	return 0;
}
