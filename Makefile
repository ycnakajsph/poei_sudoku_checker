CC ?= gcc
CFLAGS += -Wall --pedantic -Werror

all:
	$(CC) $(LDFLAGS) -o sudoku $(CFLAGS) sudoku.c main.c

test:
	$(CC) $(LDFLAGS)  -o sudoku_tests $(CFLAGS) tests/test_main.c sudoku.c -lcunit

clean:
	rm -f *.o sudoku_tests sudoku
