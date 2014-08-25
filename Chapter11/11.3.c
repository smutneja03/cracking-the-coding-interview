
#include <stdio.h>
#include <stdlib.h>

int get_index(int *array, int start, int end, int element){

	if(start > end)
		return -1;

	int mid = (start+end)/2;

	//left side is in order
	//right side is in order
	//repetions reulting in searching in one side or both the sides

	if(array[mid]==element)
		return mid;

	if(array[mid] > array[start]){//left side is in order

		if(element >= array[start] && element <= array[mid])
			return get_index(array, start, mid-1, element);
		else
			return get_index(array, mid+1, end, element);
	}

	else if(array[mid] < array[start]){
		//right side is in reverse order

		if(element>=array[mid] && element<=array[end])
			return get_index(array, mid+1, end, element);
		else
			return get_index(array, start, mid-1, element);
	}

	else if(array[start]==array[mid]){

		//repetitions from left to mid
		if(array[mid]!=array[end])
			return get_index(array, mid+1, end, element);
		else{
			//need to check both sides
			int index = get_index(array, start, mid-1, element);

			if( index!=-1)
				return index;
			else
				return get_index(array, mid+1, end, element);
		}

	}

	return -1;

}

int main(){

	int array[] = {4, 5, 1, 2, 3};

	int size = sizeof(array)/sizeof(array[0]);

	int element = 4;

	int index = get_index(array, 0, size-1, element);

	printf("element %d is at %d index\n",element, index);

	return 0;
}