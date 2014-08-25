
#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *array, int size){

	int i, j, key;

	for(i=1;i<size;i++){

		key = array[i];
		j = i-1;

		while(j>=0 && array[j]> key){

			array[j+1] = array[j];
			j = j-1;
		}

		array[j+1] = key;
	}

}

int main(){

	int array[] = {3, 1, 5, 4, 7, 6, 9, 8, 2};

	int size = sizeof(array)/sizeof(array[0]);

	printf("Array is\n");
	int i;

	for(i=0;i<size;i++)
		printf("%d\t", array[i]);

	insertion_sort(array, size);

	printf("\nArray is\n");

	for(i=0;i<size;i++)
		printf("%d\t", array[i]);

	printf("\n");

	return 0;
}
