
#include <stdio.h>
#include <stdlib.h>

void merge(int *array, int start, int mid, int end){

	int n1 = mid-start+1;
	int n2 = end-mid;

	int L[n1];
	int R[n2];

	for(i=0;i<n1;i++){
		L[i] = array[start+i];
	}

	for(i = 0;i<n2;i++){

		R[i] = array[mid + i +1];
	}

	i = 0;
	j = 0;
	k = start;

	while(i<n1 && j < n2){

		if(L[i] > R[j])
			array[k++] = R[j++];
		else
			array[k++] = L[i++]; 
	}

	while(i<n1){

		array[k++] = L[i++];
	}

	while(j<n2){
	
		array[k++] = R[j++];
	
	}
}

void merge_sort(int *array, int start, int end){

	if(start < end){

		int mid = (start+end)/2;

		merge_sort(array, start, mid);

		merge_sort(array, mid+1, end);

		merge(array, start, mid, end);
	}

}

int main(){

	int array[] = {3, 1, 5, 4, 7, 6, 9, 8, 2};

	int size = sizeof(array)/sizeof(array[0]);

	printf("Array is\n");

	int i;
	for(i=0;i<size;i++)
		printf("%d\t", array[i]);

	merge_sort(array, 0, size-1);

	printf("\nArray is\n");

	for(i=0;i<size;i++)
		printf("%d\t", array[i]);

}