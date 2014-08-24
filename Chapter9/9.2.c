
#include <stdio.h>
#include <stdlib.h>

int get_ways(int rows, int columns){

	int ways[rows][columns];

	int i, j;
	for(i=0;i<rows;i++){

		ways[i][0] = 1;
	}

	for(i=0;i<columns;i++){

		ways[0][i] = 1;
	}

	for(i=1;i<rows;i++){

		for(j=1;j<columns;j++){

			ways[i][j] = ways[i-1][j] + ways[i][j-1];
		}
	}
	return ways[rows-1][columns-1];
}


int main(){

	int rows = 3;
	int columns = 3;

	int ways = get_ways(rows, columns);

	printf("Number of ways to reach = %d\n", ways);

	return 0;
}