
#include <stdio.h>
#include <stdlib.h>

int get_larger(int a, int b){

	return a ^ ( (a ^ b) & - (a < b) );

}

int get_smaller(int a, int b){

	return b ^ ( ( a ^ b) & -( a < b ) );

}

int main(){

	int a = 13;
	int b = 17;

	int larger = (get_larger(a, b));

	int smaller = get_smaller(a, b);

	printf("Numbers are %d and %d\n", a, b);

	printf("Larger is %d\n", larger);

	printf("Smaller is %d\n", smaller);

	return 0;
}