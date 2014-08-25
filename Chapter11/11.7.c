
#include <stdio.h>
#include <stdlib.h>

struct pair{
	int h;
	int w;
};

int chain_length(struct pair array[], int size){

	int *mcl = (int *)malloc(sizeof(int) * size);
	int i, j;

	for(i=0;i<size;i++){

		mcl[i] = 1;
	}

	for(i=1;i<size;i++){

		for(j=0;j<i;j++){

			if(array[i].h > array[j].w && mcl[i] < mcl[j] +1){
				//considering the case when the first argument 
				//of second pair will be less than of the first
				mcl[i] = mcl[j] + 1;
			}
		}
	}

	int max =mcl[0];

	for(i=1;i<size;i++){

		if(mcl[i] > max){

			max = mcl[i];
		}
	}

	return max;

}

void swap(struct pair *a, struct pair *b){

	struct pair temp = *a;
	*a = *b;
	*b = temp;
}

int partition(struct pair array[], int start, int end){

	int pivot = array[end].h;
	int pIndex = start;

	int i;

	for(i=start;i<end;i++){

		if(array[i].h < pivot){

			swap(&array[i], &array[pIndex]);
			pIndex++;
		}
	}

	swap(&array[end], &array[pIndex]);
	return pIndex;
}

void quick_sort(struct pair array[], int start, int end){

	if(start < end){

		int p = partition(array, start, end);

		quick_sort(array, start, p-1);

		quick_sort(array, p+1, end);
	}
}

int main(){

	struct pair array[] = { { 15, 25}, {5, 24},
                          {27, 40}, {50, 60}  };

    int size = sizeof(array)/sizeof(array[0]);

    quick_sort(array, 0, size-1);

    printf("Structure after sorting\n");

    int i;
    
    for(i=0;i<size;i++){

    	printf("%d %d\n", array[i].h, array[i].w);
    }

    int len = chain_length(array, size);

    printf("Max Chain Length = %d\n", len);

    return 0;
}

