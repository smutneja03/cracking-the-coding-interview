
#include <stdio.h>
#include <stdlib.h>

struct box{
	int h;
	int w;
	int d;
};

void swap(struct box *a, struct box *b){

	struct box temp = *a;

	*a = *b;

	*b = temp;
}

int max(int a, int b){

	return (a>b)?a:b;
}

int min(int a, int b){

	return (a>b)?b:a;

}

int partition(struct box array[], int start, int end){

	int pIndex = start;
	int pivot = array[end].w * array[end].d;

	int i;

	for(i=start;i<end;i++){

		if(array[i].w * array[i].d > pivot){

			swap(&array[i], &array[pIndex]);
			pIndex++;
		}
	}

	swap(&array[pIndex], &array[end]);

	return pIndex;
}

void quick_sort(struct box array[], int start, int end){

	if(start < end){

		int p = partition(array, start, end);

		quick_sort(array, start, p-1);

		quick_sort(array, p+1, end);
	}

}

int get_height(struct box array[], int size){


	struct box rotations[3*size];

	int index = 0;
	int i;

	for(i=0;i<size;i++){

		rotations[index] = array[i];
		index++;

		rotations[index].h = array[i].w;
		rotations[index].d = max(array[i].h, array[i].d);
		rotations[index].w = min(array[i].h, array[i].d);
		index++;

		rotations[index].h = array[i].d;
		rotations[index].d = max(array[i].h, array[i].w);
		rotations[index].w = min(array[i].h, array[i].w);
		index++;

	}

	size = 3*size;

	quick_sort(rotations, 0, size-1);

	printf("Printing Boxes\n");

	for(i=0;i<size;i++){

		printf("%d %d %d\n", rotations[i].d, rotations[i].w, rotations[i].h);
	}

	int msh[size];

   	for(i = 0; i<size; i++ )
    	msh[i] = rotations[i].h;
 	
 	for(i = 1;i<size;i++){

 		for(int j = 0;j<i;j++){

 			if(rotations[i].w < rotations[j].w && rotations[i].d < rotations[j].d && msh[i] < msh[j] + rotations[i].h){

 				msh[i] = msh[j] + rotations[i].h;
 			}
 		}
 	}

 	for(i=0;i<size;i++){

 		printf("Max Height with %d on top = %d\n",i, msh[i] );
 	}

   	int max = -1;

   	for(i=0;i<size;i++){

   		if(max < msh[i])
   			max = msh[i];
   	}

   	return max;

}

int main(){

	struct box array[] = {{4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32}};

	int size = sizeof(array)/sizeof(array[0]);

	int height = get_height(array, size);

	printf("The Max possible height of stack is %d\n", height);
	return 0;
}