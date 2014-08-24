
#include <stdio.h>
#include <stdlib.h>

void fill_matrix(int matrix[3][4], int rows, int columns, int x, int y){

	if(x<0 || x >rows || y < 0 || y > columns)
		return;

	else{

		if(matrix[x][y]==0){

			matrix[x][y] = 1;

			fill_matrix(matrix, rows, columns, x-1, y);
			fill_matrix(matrix, rows, columns, x, y-1);
			fill_matrix(matrix, rows, columns, x+1, y);
			fill_matrix(matrix, rows, columns, x, y+1);
		}
	}

}

void print_matrix(int matrix[3][4], int rows, int columns){

	int i, j;

	for(i=0;i<rows;i++){

		for(j=0;j<columns;j++){

			printf("%d\t", matrix[i][j]);
		}

		printf("\n");
	}
}

int main(){

	int matrix[3][4] = {
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	print_matrix(matrix, 3, 4);

	fill_matrix(matrix, 3, 4, 2, 0);

	printf("\nMatrix after filling\n");
	print_matrix(matrix, 3, 4);

	return 0;
}