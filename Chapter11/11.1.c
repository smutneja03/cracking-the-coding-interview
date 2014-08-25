
#include <stdio.h>
#include <stdlib.h>
#define SMALL 5
#define LARGE 10

void print_array(int *large){

	int i;

	for(i=0;i<LARGE;i++){
		printf("%d\n",	large[i] );
	}

}

void merge_arrays(int *small, int *large){

	int i, j, k;
	i = SMALL-1;
	j = SMALL-1;

	k = LARGE- 1;

	while(i>=0 && j>=0){

		if(small[i] > large[j])
			large[k--] = small[i--];
		else
			large[k--] = large[j--];
	}

	while(i>=0)
		large[k--] = small[i--];

	while(j>=0)
		large[k--] = large[j--];

}

int main(){

	int *small = (int *)malloc(sizeof(int) * SMALL );
	int *large = (int *)malloc(sizeof(int) * LARGE );

	small[0] = 1;
	small[1] = 2;
	small[2] = 4;
	small[3] = 6;
	small[4] = 8;

	large[0] = 3;
	large[1] = 5;
	large[2] = 7;
	large[3] = 9;
	large[4] = 11;

	merge_arrays(small, large);

	print_array(large);

	free(small);
	free(large);

	return 0;

}