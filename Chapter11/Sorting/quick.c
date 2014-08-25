
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){

	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *array, int start, int end){

	int pivot = array[end];
	int pIndex = start;

	int i;

	for(i=start;i<end;i++){

		if(array[i] < pivot){

			swap(&array[i], &array[pIndex]);
			pIndex++;
		}
	}

	swap(&array[end], &array[pIndex]);

	return pIndex;
}

void quick_sort(int *array, int start, int end){

	if(start < end){

		int p = partition(array, start, end);

		quick_sort(array, start, p-1);

		quick_sort(array, p+1, end);
	}
}

int main(){

	int array[] = {3, 1, 5, 4, 7, 6, 9, 8, 2};

	int size = sizeof(array)/sizeof(array[0]);

	printf("Array is\n");

	int i;
	for(i=0;i<size;i++)
		printf("%d\t", array[i]);

	quick_sort(array, 0, size-1);

	printf("\nArray is\n");

	for(i=0;i<size;i++)
		printf("%d\t", array[i]);

	printf("\n");

	return 0;

}