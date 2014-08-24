
#include <stdio.h>
#include <stdlib.h>

int get_index(int *array, int start, int end){

	if(start > end)
		return -1;	
	
	else{

		int mid = (start+end)/2;

		if(array[mid]==mid)
			return mid;

		else if (array[mid] > mid)
			return get_index(array, start, mid-1);
		else
			return get_index(array, mid+1, end);
	}

}

int main(){

	int array[] = {-10, -8, 2, 10, 20, 23, 24};

	int size = sizeof(array)/sizeof(array[0]);

	int index = get_index(array, 0, size-1);

	if(index!=-1)
		printf("Magic Index = %d\n", index);
	else
		printf("Does not exist\n");
	return 0;
}