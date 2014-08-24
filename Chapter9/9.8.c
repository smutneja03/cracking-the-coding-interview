
#include <stdio.h>
#include <stdlib.h>

int change_ways(int coins[], int sum, int size){
	//number of ways you can get a change for a given sum using 
	//all the coins listed	
	int x, y;
	int i, j;
	int ways[sum+1][size];

	for(i=0;i<size;i++)
		ways[0][i] = 1;

	for(i=1;i<=sum;i++){

		for(j = 0;j<size;j++){

			if(i>=coins[j])
				x = ways[i-coins[j]][j];
			else
				x = 0;

			if(j>=1)
				y = ways[i][j-1];
			else
				y = 0;

			ways[i][j] = x + y;

			printf("Ways to get %d sum using %d coins = %d\n", i, j+1, ways[i][j]);
		}
	}

	return ways[sum][size-1];

}

int main(){

	int coins[] = {1, 2, 3};

	int size = sizeof(coins)/sizeof(coins[0]);

	int sum = 4;

	int ways = change_ways(coins, sum, size);

	printf("Number of ways to get sum %d is %d\n", sum, ways);

	return 0;
}