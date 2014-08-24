//return subsets of a set

#include <stdio.h>
#include <stdlib.h>

int power(int a, int b){

	if(b==0)
		return 1;

	return a * power(a, b-1);

}

void print_subsets(int *array, int size){

	int i, j;

	int subsets = power(size, 2);

	printf("Number of subsets = %d\n", subsets);

	for(i=0;i<subsets;i++){

		printf("%d -->", i+1);
		for(j=0;j<size;j++){

			if(i & 1<<j)
				printf("%d ", array[j]);
		}

		printf("\n");
	}

}

int main(){

	int array[] = {0, 1, 2, 3};
	int size = sizeof(array)/sizeof(array[0]);

	print_subsets(array, size);

	return 0;
}