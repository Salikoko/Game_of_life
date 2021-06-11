#include"life.h"

void create2dtable (int board[][SCREEN_HEIGHT]) {
	int	i, j;
    srand(time(0));
	for (i=0; i<SCREEN_WIDTH; i++) for (j=0; j<SCREEN_HEIGHT; j++) 
		board[i][j] = rand()%2;
}



int columnCorrection (int c, int a) {  //check adjacent cell location properly
	c += a;
    //if adjacent cell goes beyond table's left edge
    //add width of table to move on the far right side of the board

	while (c < 0) c += SCREEN_WIDTH;

    //if adjacent cell goes beyond table's right edge
    //add width of table to move on the far left side of the board  

	while (c >= SCREEN_WIDTH) c -= SCREEN_WIDTH;
	return c;
}

/* add to a height index, wrapping around */

int rowCorrection (int c, int a) {
	c += a;
	while (c < 0) c += SCREEN_HEIGHT;
	while (c >= SCREEN_HEIGHT) c -= SCREEN_HEIGHT;
	return c;
}

//caclulate number of live cells around given one 

int neighbourCheck (int board[][SCREEN_HEIGHT], int i, int j) {
	int	k, l, liveCells;

	liveCells = 0;

	for (k=-1; k<=1; k++){   //move to cell's neighbours 
        for (l=-1; l<=1; l++){

		if (k!=0 || l!=0){   
			if (board[columnCorrection(i,k)][rowCorrection(j,l)]!=0) liveCells++;}}}
	return liveCells;
}

//function to check current board and create next generation
void startGeneration (int board[][SCREEN_HEIGHT]) {  

	int	i, j, f; 
    int newboard[SCREEN_WIDTH][SCREEN_HEIGHT];

	for (i=0; i<SCREEN_WIDTH; i++){ //for each sell sequentially apply rules

        for (j=0; j<SCREEN_HEIGHT; j++) {

		    f = neighbourCheck (board, i, j); //return number of live cells around chosen one 

            if (f == 3) newboard[i][j] = 1; //cell is alive in next generation
		    if (f == 2) newboard[i][j] = board[i][j]; //cell keeps same status
             if (f > 3) newboard[i][j] = 0; //cell is dead in next generation/
		    if (f < 2) newboard[i][j] = 0;  //cell is dead in next generation
		   
	}}

	
    //refresh table with new generation data 
    
	for (i=0; i<SCREEN_WIDTH; i++) for (j=0; j<SCREEN_HEIGHT; j++) {
		board[i][j] = newboard[i][j];
	}
}



void print (int board[][SCREEN_HEIGHT]) {  //print 2d table 
	int	i, j;


	for (j=0; j<SCREEN_HEIGHT; j++) {


		for (i=0; i<SCREEN_WIDTH; i++) {
            if(board[i][j]==1)
			printf (GREEN "%c" RESET,'X'); //if cell is alife, then green
            else
            printf (RED "%c" RESET,'-');   //else red 
		}

		printf ("\n");
	}
}

