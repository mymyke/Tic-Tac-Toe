#include <stdio.h>

int board[3][3];
int turn;

void init() {
	turn = 1;
}

void printStartup() {
	printf("Tic Tac Toe\n");
	printf("Player %d is starting\n", turn);
}

char getBoardLetter(int value) {
	switch(value) {
	case 1:
		return 'X';
	case 2:
		return 'O';
	}
	
	return ' ';
}

void printBoard() {
	int i;

	printf("\n");

	for (i=0;i<3;i++) {
		printf("%c | %c | %c\n",
			getBoardLetter(board[i][0]),
			getBoardLetter(board[i][1]),
			getBoardLetter(board[i][2]));
			
		if (i<2)
			printf("_________\n\n");
	}
}

void getMove(int move[2]) {
	char x;
	int y;
	
	printf("\nEnter a location: ");
	scanf("%c%d", &x, &y);
	
	move[0] = ((int) x) - 65;
	move[1] = y - 1;
}

void updateBoard(int move[2]) {
	board[move[0]][move[1]] = turn;
}

int main() {
	init();
	printStartup();
	
	while (1) {
		printBoard();
		int move[2];
	
		getMove(move);
		updateBoard(move);
	}
	
	return 0;
}
