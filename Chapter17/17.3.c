
#include <stdio.h>
#include <stdlib.h>

int get_zeros(int number){

	int zeros = 0;
	int factor = 5;

	while( (number/factor) > 0){

		zeros += number/factor;

		factor*=5;
	}

	return zeros;
}

int main(){

	int number = 100;

	int zeros = get_zeros(number);

	printf("Number of zeros in %d factorial = %d\n", number, zeros);

	return 0;
}