
#include <stdio.h>

void print_bits(int n){

	if(n>1)
		print_bits(n/2);

	printf("%d", n%2);
}

int shift_even_odd(int a){

	int even_set = a & 0xAAAAAAAA;

	int odd_set = a & 0xFFFFFFFF;

	even_set  = even_set >> 1;
	odd_set = odd_set << 1;

	return even_set | odd_set;
}

int main(){

	int a = 2;
	
	printf("a = ");
	print_bits(a);
	printf("\n");

	a = shift_even_odd(a);

	printf("a = ");
	print_bits(a);
	printf("\n");

	return 0;

}