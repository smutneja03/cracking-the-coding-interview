
#include <stdio.h>
#include <stdlib.h>

void print_indexes(int array[], int size, int sum){

	int start = 0;
	int end = size-1;

	while(start < end){

		if( (array[start] + array[end]) ==sum ){

			printf("%d and %d\n", start+1, end+1);
			start++;
			end--;
		}

		else if( (array[start] + array[end]) < sum)
			start++;
		else
			end--;
	}

}
int main(){

	int array[] = {1, 2,3 ,4, 5, 6, 7, 8, 9};

	int sum = 10;

	int size = sizeof(array)/sizeof(array[0]);

	print_indexes(array, size, sum);

	return 0;
}