
#include"life.h"

int main (int argc, char *argv[]) {
	int	board[SCREEN_WIDTH][SCREEN_HEIGHT], i;

	create2dtable (board);

	for (i=0; i<2; i++) {
        puts("\n");
		print (board);
		startGeneration (board);
		puts ("\n");
	}
}