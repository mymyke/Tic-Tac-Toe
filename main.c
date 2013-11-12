#include <stdio.h>

int board[3][3];

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

int getMove(int *move, int change) { /* 0 = good input, 1 = bad input */
	char x;
	int y;
	
	if (change == 0)
		printf("\nEnter a location: ");
	else
		printf("Enter a valid location: ");
	
	scanf(" %c%d", &x, &y);
	
	if (((int) x) - 65 >= 0 && ((int) x) - 65 <= 2)
		move[0] = ((int) x) - 65;
	else
		return 1;
	
	if (y - 1 >= 0 && y - 1 <= 2)
		move[1] = y - 1;
	else
		return 1;
	
	if (board[move[0]][move[1]] != 0)
		return 1;
	
	return 0;
}

void updateBoard(int *move, int turn) {
	board[move[0]][move[1]] = turn + 1;
}

int main() {
	int move[2];
	int attempts;
	int turn;

	turn = 0;
        
	while (1) {
		printf("Player %d's turn\n", turn + 1);
		printBoard();
		
		attempts = 0;
        while (getMove(move, attempts) == 1) {attempts++;}
        
		updateBoard(move, turn);
		turn = !turn;
	}
	 
	return 0;
}
