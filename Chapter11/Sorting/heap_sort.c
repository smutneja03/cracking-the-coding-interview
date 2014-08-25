
#include <stdio.h>
#include <stdlib.h>

struct heap{
	int size;
	int *array;
};

void swap(int *a, int *b){

	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(struct heap *h, int idx){

	int largest = idx;
	int left = 2*idx + 1;
	int right = 2*idx+2;

	int size = h->size;

	if(left<size && h->array[largest] < h->array[left])
		largest = left;

	if(right<size && h->array[largest] < h->array[right])
		largest = right;

	if(largest!=idx){
		swap(&h->array[largest], &h->array[idx]);
		heapify(h, largest);
	}

}

struct heap *build_heap(int *array, int size){

	struct heap *Heap = (struct heap *)malloc(sizeof(struct heap));

	Heap->size = size;
	Heap->array = array;
	int i;

	for(i=(size-2)/2;i>=0;i--)
		heapify(Heap, i);

	return Heap;
}

void print_array(int *array, int size){

	int i;
	for(i=0;i<size;i++){

		printf("%d\t", array[i]);
	}

	printf("\n");
}

void heap_sort(int *array, int size){

	struct heap *h = build_heap(array, size);

	while(h->size>1){

		swap(&h->array[0], &h->array[h->size-1]);
		
		h->size--;

		heapify(h, 0);
	}

}

int main(){

	int array[] = {12, 11, 13, 5, 6, 7};

	int size = sizeof(array)/sizeof(array[0]);

	print_array(array, size);

	heap_sort(array, size);

	print_array(array, size);


	return 0;
}