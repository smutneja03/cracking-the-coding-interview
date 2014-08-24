
#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

void print_board(int board[SIZE][SIZE]){

	int i, j;

	for(i=0;i<SIZE;i++){

		for(j=0;j<SIZE;j++){

			printf("%d\t", board[i][j]);
		}

		printf("\n");
	}
}

int is_safe(int board[SIZE][SIZE], int row, int col){

	//check row compatibility
	int i, j;
	for(i=0;i<col;i++)
		if(board[row][i])
			return 0;
	//checking upper diagonal Compatibility
	for(i=row,j=col;i>=0 & j >=0; i--, j--)
		if(board[i][j])
			return 0;

	//checking lower diagonal compatibilty
	for(i=row,j=col;i<SIZE & j >=0; i++, j--)
		if(board[i][j])
			return 0;

	return 1;


}

int n_queen(int board[SIZE][SIZE], int col){

	if(col>=SIZE)
		return 1;
	
	else{

		//for every col in the recursion we check the best place to fit
		//if the place is there we place the quuen
		//else we backtrack and find it the best position
		for(int i=0;i<SIZE;i++){

			if(is_safe(board, i, col)){

				board[i][col] = 1;

				if(n_queen(board, col+1))
					return 1;

				board[i][col] = 0;
			}
		}

		return 0;
	}


}

int main(){

	int board[SIZE][SIZE];

	for(int i=0;i<SIZE;i++)
		for(int j=0;j<SIZE;j++)
			board[i][j] = 0;

	if(n_queen(board, 0) == 0){

		printf("Solution doesnt exist\n");
		return 0;
	}

	print_board(board);


}