
#include"life.h"

int main (int argc, char *argv[]) {
	int	board[SCREEN_WIDTH][SCREEN_HEIGHT], i, j;

	create2dtable (board);
	//read_file (board, argv[1]);

	/* play game of life 100 times */

	for (i=0; i<2; i++) {
        puts("\n");
		print (board);
		play (board);

		/* clear the screen using VT100 escape codes */

		puts ("\n");
	}
}