
#include"life.h"

int main (int argc, char *argv[]) {
	int	board[SCREEN_WIDTH][SCREEN_HEIGHT], i;

	create2dtable (board);
	print (board);
	for (i=0; i<10; i++) {
        puts("\n");
		startGeneration (board);
		sleep(4);
		print(board);
		puts ("\n");
	}
}