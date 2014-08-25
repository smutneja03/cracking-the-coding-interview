
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){

	int temp = *a;
	*a = *b;
	*b = temp;
}

void selection_sort(int *array, int size){

	int i, min_index, j;
	for(i=0;i<size-1;i++){

		min_index = i;

		for(j=i+1;j<size;j++){

			if(array[min_index] > array[j])
				min_index = j;
		}

		swap(&array[min_index], &array[i]);
	}
}
int main(){

	int array[] = {3, 1, 5, 4, 7, 6, 9, 8, 2};

	int size = sizeof(array)/sizeof(array[0]);

	printf("Array is\n");
	int i;
	for(i=0;i<size;i++)
		printf("%d\t", array[i]);

	selection_sort(array, size);

	printf("\nArray is\n");

	for(i=0;i<size;i++)
		printf("%d\t", array[i]);

	printf("\n");

	return 0;

}