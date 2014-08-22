
#include <stdio.h>
#include <stdlib.h>

void print_bits(int n){

	if(n>1)
		print_bits(n/2);

	printf("%d", n%2);
}

char *convert(float number, int *index){

	if(number>=1 || number<=0){

		printf("Enter a valid entry\n");
		exit(0);
	}

	float frac = 0.5;

	char *binary = (char *)malloc(sizeof(char) * 32);

	binary[(*index)++] = '.';

	while(number>0){

		if( (*index)>=32){
			printf("ERROR\n");
			exit(0);
		}
		if(number>=frac){

			binary[(*index)++] = '1';
			number = number-frac;
		}
		else{

			binary[(*index)++] = '0';
		}

		frac = frac/2;
	}

	return binary;
}

void print_binary(char *string, int top){

	char *temp = string;

	int index = 0;

	while(index < top)
		printf("%c", string[index++]);

	printf("\n");

}

int main(){

	float number = 0.37;

	int top = 0;
	
	char *s = convert(number, &top);

	print_binary(s, top);

	return 0;
}