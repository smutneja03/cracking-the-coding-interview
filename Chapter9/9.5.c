
#include <stdio.h>

int get_factorial(int n){

	if(n==0 || n==1)
		return 1;

	return n *get_factorial(n-1);
}

void swap(char *a, char *b){

	int temp = *a;
	*a = *b;
	*b =temp;
}

void print_permutation(char *string, int start, int end, int *index){

	if(start==end)
		printf("%d  --  %s\n", (*index)++, string);
	
	int i;

	for(i=start;i<end;i++){

		swap(string+start, string + i);

		print_permutation(string, start+1, end, index);

		swap(string+start, string+i);
	}
}
int main(){

	char string[] = "Sahil";
	int len = sizeof(string)/sizeof(string[0]);

	printf("%s len is %d\n", string, len);

	int permutations = get_factorial(len-1);

	printf("Number of permutations = %d\n", permutations);

	int index = 1;
	print_permutation(string, 0, len-1, &index);

	return 0;
}