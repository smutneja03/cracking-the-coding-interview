
#include <stdio.h>
#include <stdlib.h>

int is_permutation(char *a, char *b){

	int l1=0, l2=0;

	char *temp = a;

	while(*(temp)){
		l1++;
		temp++;
	}

	temp = b;
	while(*(temp)){
		l2++;
		temp++;
	}

	if(l1!=l2)
		return 0;

	int *count = (int *)malloc(sizeof(int) * 256);

	temp = a;

	while(*(temp)){

		count[*temp]++;
		temp++;
	}

	temp = b;

	while(*(temp)){

		if(count[*(temp)]==0)
			return 0;
		else
			count[*(temp)]--;

		temp++;
	}

	free(count);

	return 1;
}

int main(){

	char first[] = "Sahil";
	char second[] = "liSah";

	if(is_permutation(first, second))
		printf("The Strings ARE PERMUTATION\n");
	else
		printf("NOT PERMUTATION\n");

	return 0;
}