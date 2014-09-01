
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROW 4
#define COL 5

int kadane(int *array, int *start, int *finish, int n){

	int sum = 0;
	int max_sum = INT_MIN;
	int i;

	*finish = -1;

	int local_start = 0;

	for(i=0;i<n;i++){

		sum+= array[i];

		if(sum < 0){

			sum = 0;
			local_start = i+1;
		}

		else if(sum > max_sum){

			max_sum = sum;
			*start = local_start;
			*finish = i;
		}

	}

	if(*finish != -1){

		return max_sum;
	}

	//case when all numbers in the array are negative

	max_sum = array[0];

	*start = *finish = 0;

	for(i=1 ; i<n ; i++){

		if(array[i] > max_sum){

			max_sum = array[i];

			*start = *finish = i;
		}
	}

	return max_sum;

}

void max_sum(int matrix[4][5]){

	int max_sum = INT_MIN;
	int final_left, final_right;
	int final_top, final_bottom;

	int left, right, i;

	int temp[ROW], sum, start, finish;

	for(left=0;left<COL;left++){

		for(i = 0;i<ROW;i++)
			temp[i] = 0;

		for(right=left;right<COL;right++){

			for(i=0;i<ROW;i++){

				temp[i] += matrix[i][right];
			}

			sum = kadane(temp, &start, &finish, ROW);

			if(sum > max_sum){

				max_sum = sum;
				final_left = left;
				final_right = right;
				final_bottom = finish;
				final_top = start;
			}
		}
	}

	printf("(Top, Left) (%d, %d)\n", final_top, final_left);
    
    printf("(Bottom, Right) (%d, %d)\n", final_bottom, final_right);
    
    printf("Max sum is: %d\n", max_sum);

}

int main(){

	int matrix[4][5] = {
		{1, 2, -1, -4, -20},
		{-8, -3, 4, 2, 1},
		{3, 8, 10, 1, 3},
		{-4, -1, 1, 7, -6}
	};

	max_sum(matrix);

	return 0;
}
