
/*  When a new value arrives, it is placed in the maxHeap 
if the value is less than or equal to the median, otherwise
it is placed into the minHeap.The heap sizes can be equal, 
or the maxHeap may have one extra element. This constraint 
can easily be restored by shifting an element from one
heap to the other.The median is available in constant time,
by looking at the top element(s). Updates take 0(log(n)) time.
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct heap{

	int size;
	int *array;
	int top;
};


struct heap *build_heap(){

	struct heap *temp = (struct heap *)malloc(sizeof(struct heap));

	temp->size = SIZE;

	temp->array = (int *)malloc(sizeof(int) * SIZE);

	temp->top = 0;

	return temp;

}

void swap(int *a, int *b){

	int temp = *a;

	*a = *b;

	*b = temp;
}

void max_heapify(struct heap *max, int idx){

	int largest = idx;

	int left = 2*idx +1;
	int right = 2*idx +2;

	if(left < max->top && max->array[largest] < max->array[left])
		largest = left;

	if(right < max->top && max->array[largest] < max->array[right])
		largest = right;

	if(largest!=idx){

		swap(&max->array[largest], &max->array[idx]);

		max_heapify(max, largest);
	}
} 

void min_heapify(struct heap *min, int idx){

	int smallest = idx;

	int left = 2*idx +1;
	int right = 2*idx +2;

	if(left < min->top && min->array[smallest] > min->array[left])
		smallest = left;

	if(right < min->top && min->array[smallest] > min->array[right])
		smallest = right;

	if(smallest!=idx){

		swap(&min->array[smallest], &min->array[idx]);

		min_heapify(min, smallest);
	}
} 

void add_value(struct heap *h, int value){

	int index = h->top;

	h->array[index] = value;

	(h->top)++;
}

void find_median(struct heap *max, struct heap *min, float *median, int n){

	if(max->top==0 && min->top==0){
		add_value(max, n);
		*median = n;
	}

	else{

		if(n <= *median){

			add_value(max, n);
		}

		else{

			add_value(min, n);
		}

		//need to heapify the max and the min heaps 

		while(max->top != min->top  && max->top != min->top+1){

			if(min->top > max->top){

				(min->top)--;

				int temp = min->array[0];

				swap(&min->array[0], &min->array[min->top]);

				add_value(max, temp);
			}

			else if(min->top < max->top){

				(max->top)--;

				int temp = max->array[0];

				swap(&max->array[0], &max->array[max->top]);

				add_value(min, temp);
			}
		}

		//now the elements are balanced in both the heaps
		//now need to run the heapify operations to make it resp heap

		int i;

		for(i=(max->top -2)/2;i>=0;i--){

			max_heapify(max, i);
		}

		for(i=(min->top -2)/2;i>=0;i--){

			min_heapify(min, i);
		}

		//now we need to check the size of the heaps and find median

		if(max->top == min->top + 1)
			*median = max->array[0];
		else
			*median = (max->array[0]+min->array[0])/2.0;

	}

}

void print_heaps(struct heap *max, struct heap *min){

	int i;

	printf("Max Heap  ");
	for(i=0;i<max->top;i++)
		printf("%d\t", max->array[i]);

	printf("\n");

	printf("Min Heap  ");
	for(i=0;i<min->top;i++)
		printf("%d\t", min->array[i]);

	printf("\n");
}

int main(){

	float median;

	struct heap *max = build_heap();

	struct heap *min = build_heap();

	int values[] = {4, 5, 1, 2, 9, 8, 6, 3, 7, 10, 11};

	int i;
	int size = sizeof(values)/sizeof(values[0]);

	for(i=0;i<size;i++){

		printf("\n");
		printf("Value added = %d\n", values[i]);

		find_median(max, min, &median, values[i]);

		print_heaps(max, min);

		printf("Median till now is %.2f\n", median);
		printf("\n");
	}

	return 0;
}