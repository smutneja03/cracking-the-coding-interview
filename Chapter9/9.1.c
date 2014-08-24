
#include <stdio.h>
#include <stdlib.h>

int get_ways(int n, int counter){

	int ways[n+1];

	ways[0] = 1;//0 number of ways it can take no step
	ways[1] = 1;

	int i, j;
	for(i =2;i<=n;i++){

		ways[i] = 0;
		for(j=1;j<=counter;j++){

			if(i>=j){
				ways[i] += ways[i-j]; 
			}
		}
	}

	for(i=0;i<=n;i++)
		printf("To reach %d Stair = %d ways\n", i, ways[i]);

	return ways[n];
}
int main(){

	int ways;

	int n = 4;
	int counter = 2;//can take either 1 step or 2 steps or 3 steps

	ways = get_ways(n, counter);

	printf("Number of ways = %d\n", ways);

	return 0;
}