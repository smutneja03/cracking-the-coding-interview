
#include <stdio.h>
#include <stdlib.h>

void print_bits(int n){

	if(n>1)
		print_bits(n/2);

	printf("%d", n%2);
}

int higher(int a){

	int c = (a & -a);

	int r = a + c;

	return ( ( ( ( r ^ a) >> 2) / c )| r );

}

int smaller(int y){

	int t = y + 1;
	int u = t ^ y;
	int v = t & y;
	int x = v - (v & -v) / (u + 1);
	return x;
}

int main(){

	int a = 23;

	int next_highest, next_smallest;

	printf("%d = ", a);
	print_bits(a);
	printf("\n");

	next_highest = higher(a);
	printf("Next Highest Number is %d\n", next_highest);
	printf("%d = ", next_highest);
	print_bits(next_highest);
	printf("\n");

	next_smallest = smaller(a);
	printf("Next Smallest Number is %d\n", next_smallest);
	printf("%d = ", next_smallest);
	print_bits(next_smallest);
	printf("\n");

	return 0;
}
