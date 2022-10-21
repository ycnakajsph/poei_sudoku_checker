#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "../sudoku.h"

void test_verify_col_row_COL_ok(void){

	int grid[LENGTH_GRID][LENGTH_GRID];
	int i;

	for (i=0;i<LENGTH_GRID;i++){
		set_minus_one(grid[i],LENGTH_GRID);
	}

	for(i=0;i<LENGTH_GRID;i++){
		grid[i][0] = i;
	}

	CU_ASSERT(verify_col_row(grid,0,COL) == 0);
}

void test_verify_col_row_COL_ko(void){

	int grid[LENGTH_GRID][LENGTH_GRID];
	int i;

	for (i=0;i<LENGTH_GRID;i++){
		set_minus_one(grid[i],LENGTH_GRID);
	}

	for(i=0;i<LENGTH_GRID;i++){
		grid[i][0] = i;
	}

	grid[3][0] = 7;

	CU_ASSERT(verify_col_row(grid,0,COL) != 0);
}

void test_verify_col_row_COL_ko_not_complete(void){

	int grid[LENGTH_GRID][LENGTH_GRID];
	int i;

	for (i=0;i<LENGTH_GRID-2;i++){
		set_minus_one(grid[i],LENGTH_GRID);
	}

	for(i=0;i<LENGTH_GRID-2;i++){
		grid[i][0] = i;
	}

	CU_ASSERT(verify_col_row(grid,0,COL) != 0);
}

void test_verify_col_row_ROW_ok(void){

	int grid[LENGTH_GRID][LENGTH_GRID];
	int i;

	for (i=0;i<LENGTH_GRID;i++){
		set_minus_one(grid[i],LENGTH_GRID);
	}

	for(i=0;i<LENGTH_GRID;i++){
		grid[0][i] = i;
	}

	CU_ASSERT(verify_col_row(grid,0,ROW) == 0);
}

void test_verify_col_row_ROW_ko(void){

	int grid[LENGTH_GRID][LENGTH_GRID];
	int i;

	for (i=0;i<LENGTH_GRID;i++){
		set_minus_one(grid[i],LENGTH_GRID);
	}

	for(i=0;i<LENGTH_GRID;i++){
		grid[0][i] = i;
	}

	grid[0][6]=2;

	CU_ASSERT(verify_col_row(grid,0,ROW) != 0);
}

void test_verify_col_row_ROW_ko_not_complete(void){

	int grid[LENGTH_GRID][LENGTH_GRID];
	int i;

	for (i=0;i<LENGTH_GRID;i++){
		set_minus_one(grid[i],LENGTH_GRID);
	}

	for(i=0;i<LENGTH_GRID-2;i++){
		grid[0][i] = i;
	}

	grid[0][6]=2;

	CU_ASSERT(verify_col_row(grid,0,ROW) != 0);
}

void test_verify_sub_array(void){

	int grid[LENGTH_GRID][LENGTH_GRID];
	int i,j,prev_val;

	for (i=0;i<LENGTH_GRID;i++){
		set_minus_one(grid[i],LENGTH_GRID);
	}

	prev_val=0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			grid[i][j] = prev_val++;
		}
	}

	// Filling the last grid too
	prev_val=0;
	for(i=6;i<9;i++){
		for(j=6;j<9;j++){
			grid[i][j] = prev_val++;
		}
	}

	CU_ASSERT(verify_sub_array(grid,0) == 0);
	CU_ASSERT(verify_sub_array(grid,8) == 0);
}

void test_verify_sub_array_ko(void){

	int grid[LENGTH_GRID][LENGTH_GRID];
	int i,j,prev_val;

	for (i=0;i<LENGTH_GRID;i++){
		set_minus_one(grid[i],LENGTH_GRID);
	}

	prev_val=0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			grid[i][j] = prev_val++;
		}
	}

	grid[0][0] = 7;

	CU_ASSERT(verify_sub_array(grid,0) != 0);
}

void test_verify_grid(void){
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

	CU_ASSERT(verify_grid(grid) == 0);
}

void test_verify_grid_ko(void){
	int i,j;

	int grid[LENGTH_GRID][LENGTH_GRID] = \
		{{2, 2, 3, 4, 5, 6, 7, 8, 9}, \
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

	CU_ASSERT(verify_grid(grid) != 0);
}

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

int main()
{
	CU_pSuite pSuite = NULL;

	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	/* add a suite to the registry */
	pSuite = CU_add_suite("Suite_1", init_suite, clean_suite);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* add the tests to the suite */
	if (
		NULL == CU_add_test(pSuite, "test of test_verify_col_row_ROW_ok()", test_verify_col_row_COL_ok) ||
		NULL == CU_add_test(pSuite, "test_verify_col_row_COL_ko()", test_verify_col_row_COL_ko ) ||
		NULL == CU_add_test(pSuite, "test_verify_col_row_ROW_ok()", test_verify_col_row_ROW_ok ) ||
		NULL == CU_add_test(pSuite, "test_verify_col_row_ROW_ko()", test_verify_col_row_ROW_ko ) ||
		NULL == CU_add_test(pSuite, "test_verify_col_row_COL_ko_not_complete()", test_verify_col_row_COL_ko_not_complete ) ||
		NULL == CU_add_test(pSuite, "test_verify_col_row_ROW_ko_not_complete()", test_verify_col_row_ROW_ko_not_complete ) ||
		NULL == CU_add_test(pSuite, "test_verify_sub_array()", test_verify_sub_array ) ||
		NULL == CU_add_test(pSuite, "test_verify_sub_array_ko()", test_verify_sub_array_ko ) ||
		NULL == CU_add_test(pSuite, "test_verify_grid()", test_verify_grid )  ||
		NULL == CU_add_test(pSuite, "test_verify_grid_ko()", test_verify_grid_ko )
	)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* Run all tests using the CUnit Basic interface */
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
