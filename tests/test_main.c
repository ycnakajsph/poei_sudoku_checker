#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include <CUnit/CUnit.h>

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
		NULL == CU_add_test(pSuite, "test_verify_col_row_ROW_ko()", test_verify_col_row_ROW_ko ) 
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
