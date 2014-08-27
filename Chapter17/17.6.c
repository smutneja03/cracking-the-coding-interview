
#include <stdio.h>
#include <stdlib.h>

void get_indexes(int *array, int size, int *start, int *end){

	int i;

	for(i=0;i<=size-1;i++){

		if(array[i] > array[i+1])
			break;
	}

	if(i==size){
		printf("Entire array is sorted\n");
		exit(0);
	}

	*start = i;

	for(i=size;i>0;i--){

		if(array[i] < array[i-1])
			break;
	}

	*end = i;

	int max = array[(*start)];
	int min = array[(*start)];

	for(i=(*start)+1;i<=(*end);i++){

		if(array[i] > max)
			max = array[i];
		if(array[i] < min)
			min = array[i];
	}

	for(i=0;i<(*start);i++){

		if(array[i] > min)
			*start = i;
	}

	for(i=size;i>=(*end)+1;i--){

		if(array[i] < max)
			*end = i;
	}

	return;

}

int main(){

	int array[] = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};

	int size = sizeof(array)/sizeof(array[0]);

	int start, end;

	get_indexes(array, size-1, &start, &end);

	printf("%d and %d are the start and the end indexes\n", start, end);

	return 0;
}

