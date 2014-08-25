
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){

	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int array[], int size){

	int i, j, swap = 0;

	for(i=0;i<size;i++){

		for(j=0;j<size-i-1;j++){

			if(array[j] > array[j+1]){
				swap = 1;
				swap(&array[j], &array[j+1]);
			}
		}

		if(swap==0)
			break;
	}
}

int main(){

	int array[] = {3, 1, 5, 4, 7, 6, 9, 8, 2};

	int size = sizeof(array)/sizeof(array[0]);

	printf("Array is\n");
	int i;

	for(i=0;i<size;i++)
		printf("%d\t", array[i]);

	bubble_sort(array, size);

	printf("\nArray is\n");

	for(i=0;i<size;i++)
		printf("%d\t", array[i]);

	printf("\n");

	return 0;

}