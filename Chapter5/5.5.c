
#include <stdio.h>

void print_bits(int n){

	if(n>1)
		print_bits(n/2);

	printf("%d", n%2);
}

int get_bits(int a, int b){

	int set_bits = 0;

	int temp = a ^ b;

	while(temp!=0){
		if(temp & 1)
			set_bits++;
		temp = temp>>1;
	}

	return set_bits;
}

int main(){

	int a = 4;
	int b = 3;

	printf("a = ");
	print_bits(a);
	printf("\n");

	printf("b = ");
	print_bits(b);
	printf("\n");	

	int bits = get_bits(a, b);

	printf("Number of bits = %d\n", bits);

	return 0;
}

