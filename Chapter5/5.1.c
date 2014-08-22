
#include <stdio.h>

void print_bits(int n){

	if(n>1)
		print_bits(n/2);

	printf("%d", n%2);
}

int insert_bits(int a, int b, int start, int end){

	//uset the bits in a from start to end

	//create a left and right int and perform or between them
	//after that and with the original to get it cleared

	int all_ones = ~0;
	int left = all_ones << (start+end);
	int right = (1 << start) -1;

	int mask = left | right; //bits from strt to end are 0

	int a_cleared = mask & a;

	int b_new = b << start;

	return a_cleared | b_new;

}

int main(){

	int a = 1024;
	int b = 19;

	printf("a = ");
	print_bits(a);
	printf("\n");

	printf("b = ");
	print_bits(b);
	printf("\n");	
	
	int start = 2;
	int end = 6;
	a = insert_bits(a, b, start, end);

	printf("Bits after inserting, a = ");
	print_bits(a);
	printf("\n");

	return 0;
}

