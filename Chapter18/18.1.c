
#include <stdio.h>
#include <stdlib.h>

int sum_numbers(int a, int b){

	int carry;

	while(b!=0){

		carry = a & b;

		a = a ^ b;

		b = carry << 1;

	}

	return a;

}

int main(){

	int a = 9876;

	int b = 1234;

	int sum = sum_numbers(a, b);

	printf("Sum of %d and %d is %d\n", a, b, sum);

	return 0;
}