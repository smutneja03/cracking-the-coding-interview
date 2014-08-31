
#include <stdio.h>
#include <stdlib.h>

void rotate_image(unsigned int *pdest, unsigned int *psource, int row, int col){

	int i, j;

	for(i=0;i<row;i++){

		for(j=0;j<col;j++){

			*(pdest + j*row + (row-i-1) ) = *(psource + i * col + j);
		}
	}

}

void print_image(unsigned int const *image, int row, int col){

	int i, j;

	for(i=0;i<row;i++){

		for(j=0;j<col;j++){

			printf("%d\t", *(image + i *col + j));
		}
		printf("\n");
	}
}

void swap(unsigned int *a, int *b){

	int temp = *a;
	*a = *b;
	*b = temp;
}

void get_transpose(unsigned int *pdest, int rows, int columns){

	int size = rows*columns-1;
	int t; //holds element to be replaced
	int next;
	int cycle_begin;
	int i;

	int *visited = (int *)malloc(sizeof(int) * (size+1) );

	visited[0] = 1;
	visited[size] = 1;
	i = 1;

	while(i<size){

		cycle_begin = i;
		t = pdest[i];

		do{

			next = (i*rows) % size;
			swap(pdest + next, &t);
			visited[i] = 1;
			i = next;

		}while(i!=cycle_begin);

		for(i=1;i<size && visited[i];i++);
	}

}

int main(){

	unsigned int image[][4] = {
							{1, 2, 3, 4},
							{5, 6, 7, 8},
							{9, 10, 11, 12}
						};

	int m=3, n=4;

	unsigned int *psource = (unsigned int *)image;

	print_image(psource, m, n);

	unsigned int *pdest = (unsigned int *)malloc(sizeof(int) * m * n);

	rotate_image(pdest, psource, m, n);

	printf("Image after rotating is\n");

	print_image(pdest, n, m);

	//pdest is the matrix with the solution with n rows & m columns

	//rotation in place to be done by first getting its transpose

	get_transpose(pdest, n, m);

	print_image(pdest, m, n);

	return 0;
}


