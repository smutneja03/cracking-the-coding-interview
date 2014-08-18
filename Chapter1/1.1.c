
#include <stdio.h>
#include <stdlib.h>

int is_unique(char *string){

	int *count = (int *)malloc(sizeof(int) * 256);

	int index = 0;

	while( *(string+index)){

		if(count[ *(string+index) ]==0)
			count[ *(string+index) ]++;
		else
			return 0;

		index++;
	}

	
	free(count);
	
	return 1;
}

int main(){

	char string[] = "abcdef";
	printf("String is %s\n", string);
	if(is_unique(string))
		printf("All the characters are UNIQUE\n");

	else
		printf("All the characters are NOT UNIQUE\n");
	return 0;
}