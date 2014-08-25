
#include <stdio.h>
#include <stdlib.h>

void count_sort(char *string){

	int *count = (int *)malloc(sizeof(int) * 256);

	char *temp = string;
	int len = 0;
	while(*(temp)){

		count[(*temp)]++;
		len++;
		temp++;
	}

	int i;

	for(i=1;i<256;i++)
		count[i] +=count[i-1];

	char result[len];

	temp = string;

	while(*temp){

		int pos = count[(*temp)] - 1;

		result[pos] = (*temp);

		count[(*temp)]--;

		temp++;
	}

	i = 0;

	while(*string){

		*string = result[i++];
		string++;
	}

}

int main(){

	char string[] = "edcba";

	printf("%s is the string\n", string);

	count_sort(string);

	printf("After Sorting\n%s", string);

	printf("\n");

	return 0;
}