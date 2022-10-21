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

void init_found_zero(int found[LENGTH_GRID]){
	int i;
	for (i=0;i<LENGTH_GRID;i++){
		found[i] = 0;
	}
}

int verify_all_found(int found[LENGTH_GRID]){
	int i;
	for (i=0;i<LENGTH_GRID;i++){
		if (found[i] != FOUND){
			return -1;
		}
	}
	return 0;
}

int verify_col_row(int grid[LENGTH_GRID][LENGTH_GRID], int index, int col_row){
	int i;
	int found[LENGTH_GRID];

	init_found_zero(found);

	for(i=0;i<LENGTH_GRID;i++){
		if (col_row == ROW){
			found[grid[index][i]] += FOUND;
		}
		else{
			found[grid[i][index]] += FOUND;
		}
	}

	return verify_all_found(found);
}

int verify_sub_array(int grid[LENGTH_GRID][LENGTH_GRID],int index){

	int i;
	int j;
	int starting_row = (index/3)*3;
	int starting_col = (index%3)*3;
	int found[LENGTH_GRID];

	init_found_zero(found);

	for (i=starting_row;i<starting_row+3;i++){
		for(j=starting_col;j<starting_col+3;j++){
			found[grid[i][j]] = FOUND;
		}
	}

	return verify_all_found(found);
}

int verify_grid(int grid[LENGTH_GRID][LENGTH_GRID]){
	int i;

	for (i=0;i<LENGTH_GRID;i++){

		if( verify_sub_array(grid,i) != 0 ){
			printf("sub array %d is wrong\n",i);
			return -1;
		}
		if( verify_col_row(grid,i,COL) != 0){
			printf("col %d is wrong\n",i);
			return -1;
		}
		if( verify_col_row(grid,i,ROW) != 0){
			printf("row %d is wrong\n",i);
			return -1;
		}
	}

	return 0;
}