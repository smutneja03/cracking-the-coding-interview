
#include <stdio.h>
#include <stdlib.h>

void search(int matrix[3][4], int rows, int column, int *r, int *c, int n){

	while(1){
		if(*r >=rows || *c < 0){
			printf("NO SOL\n");
			break;
		}

		if(matrix[*r][*c] == n)
			break;

		else if(matrix[*r][*c] < n)
			(*r)++;
		else
			(*c)--;
	}
}

int main(){

	int matrix[3][4] = {
		{1, 2, 3 ,4},
		{5, 6, 7 ,8},
		{9, 10, 11, 12}
	};

	int element = 7;

	int row = 0;
	int col = 3;//top right

	search(matrix, 3, 4, &row, &col, element);

	printf("Row = %d and Col = %d\n", row+1, col+1);

	return 0;
}