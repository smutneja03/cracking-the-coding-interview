
#include <stdio.h>
#include <stdlib.h>

void swap1(int *a, int *b){

	*a = *a + *b;

	*b = *a - *b;

	*a = *a - *b;
}

void swap2(int *a, int *b){

	*a = *a ^ *b;

	*b = *a ^ *b;

	*a = *a ^ *b;

}

int main(){

	int a = 13;
	int b = 7;

	printf("%d = a and %d = b\n", a, b);

	swap1(&a, &b);

	printf("%d = a and %d = b\n", a, b);

	swap2(&a, &b);

	printf("%d = a and %d = b\n", a, b);

	return 0;

}