
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

	return 0;
}


