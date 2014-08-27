
#include <stdio.h>
#include <stdlib.h>

//Kadanes Algorithm

int max(int a, int b){

	return ( a > b ) ? a : b;
}

int kadane_algorithm(int *array, int size){

	int curr_max = array[0];
	int max_sum = array[0];

	int i;

	for(i=1;i<size;i++){

		curr_max = max(0, curr_max + array[i]);

		max_sum = max(curr_max, max_sum);
	}

	return max_sum;
}

int main(){

	int array[] = { 2, -8, 3, -2, 4, -10};

	int size = sizeof(array)/sizeof(array[0]);

	int sum = kadane_algorithm(array, size);

	printf("Maximum Contiguous Sum = %d\n", sum);

	return 0;
}