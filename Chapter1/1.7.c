
#include <stdio.h>
#include <stdlib.h>

void print_matrix(int matrix[][4], int row, int col){

	int i, j;

	for(i=0;i<row;i++){

		for(j=0;j<col;j++){

			printf("%d\t", matrix[i][j]);
		}

		printf("\n");
	}
}

void tranform_matrix(int matrix[][4], int row, int col){

	int *rows_check = (int *)malloc(sizeof(int) * row);
	int *cols_check = (int *)malloc(sizeof(int) * col);
	int i, j;

	for(i=0;i<row;i++){

		for(j=0;j<col;j++){

			if(matrix[i][j]==0){
				rows_check[i] = 1;
				cols_check[j] = 1;
			}
		}
	}

	for(i=0;i<row;i++){

		for(j=0;j<col;j++){

			if(rows_check[i]==1 || cols_check[j]==1){
				
				matrix[i][j] = 0;
			}
		}
	}

	free(rows_check);
	free(cols_check);
}

int main(){

	int matrix[3][4] = {
		{1, 2, 0 , 4},
		{5, 6, 7, 8},
		{9, 10, 11, 0}
	};

	int m = 3;
	int n = 4;
	print_matrix(matrix, m, n);

	tranform_matrix(matrix, m, n);

	printf("Printing after converting\n");
	print_matrix(matrix, m, n);

	return 0;
}