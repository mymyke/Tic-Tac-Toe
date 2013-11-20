#include <stdio.h>

char getBoardLetter(int value) {
	switch(value) {
	case 1:
		return 'X';
	case 2:
		return 'O';
	}
	
	return ' ';
}

void printBoard(int **board) {
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

void getMove(int **board, int *move, int *rows, int turn) { /* 0 = good input, 1 = bad input */
	char input[2];
	int x, y, attempts = 0;

	while (1) {
		if (attempts == 0)
			printf("\nEnter a location: ");
		else
			printf("Enter a valid location: ");
	
		fgets(input, 4, stdin);
		x = (int) input[0] - 65;
		y = (int) input[1] - 49;
		
		if (x >= 0 && x <= 2) {
			move[0] = x;
		} else {
			attempts++;
			continue;
		}
	
		if (y >= 0 && y <= 2) {
			move[1] = y;
		} else {
			attempts++;
			continue;
		}
	
		if (board[move[0]][move[1]] != 0) {
			attempts++;
			continue;
		}
			
		break;
	}
	
	if (turn == 0) {
		rows[x]++;
		rows[y+3]++;
		if (x==y && !(2-y==x))
			rows[6]++;
		else if (2-y==x)
			rows[7]++;
	} else {
		rows[x] -= 1;
		rows[y+3]--;
		if (x==y && !(2-y==x))
			rows[6]--;
		else if (2-y==x)
			rows[7]--;
	}
}

void removeNewLine(char *line) {
	int end = strlen(line);
	if (line[end] == "\n")
		line[end] = "\0";
}

int isFinished(int *rows, int turns, int *state) {
	int i;
	if (turns >= 9) {
		*state = 3;
	}
	
	for (i=0;i<8;i++) {
		if (rows[i] >= 3) {
			*state = 1;
			break;
		} else if (rows[i] <= -3) {
			*state = 2;
			break;
		}
	}
}

int main() {
	int **board, *rows, move[2],
		turn = 0, turns = 0, i, state = 0;

	rows = malloc(8 * sizeof(int));
	board = malloc(3 * sizeof(int *));
	for (i=0;i<3;i++) {
		board[i] = malloc(3 * sizeof(int));
	}

	while (state == 0) {
		printf("Player %d's turn\n", turn + 1);
		printBoard(board);
		
        getMove(board, move, rows, turn);
        
		board[move[0]][move[1]] = turn + 1;
		turn = !turn;
		turns++;
		isFinished(rows, turns, &state);
	}
	
	switch(state) {
	case 1:
		printf("Player 1 is the winner!\n");
		break;
	case 2:
		printf("Player 2 is the winner!\n");
		break;
	case 3:
		printf("There was a tie!\n");
		break;
	}
	
	return 0;
}
