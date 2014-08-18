
#include <stdio.h>
#include <stdlib.h>

void swap(char *a, char *b){

	int temp = *a;
	*a = *b;
	*b = temp;
}
void reverse(char *string){

	int length = 0;
	int index = 0;

	while( *(string+index) ){

		length++;
		index++;
	}

	int start = 0;
	int end = length-1;

	while(start < end){

		swap(string+start, string+end);
		start++;
		end--;
	}
}

int main(){

	char string[] = "My name is Sahil Mutneja";

	printf("Original String is \n%s\n", string);

	reverse(string);

	printf("String after reversing is \n%s\n", string);

	reverse(string);

	printf("Final String \n%s\n", string);
	
	return 0;
}