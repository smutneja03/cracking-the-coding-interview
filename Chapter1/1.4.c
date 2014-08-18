
#include <stdio.h>
#include <stdlib.h>

void replace_spaces(char *string, int length){

	int i, white_spaces=0;
	for(i=0;i<length;i++){
		if(*(string+i)==' ')
			white_spaces++;
	}

	int new_length = length + 2*white_spaces;

	string[new_length] = '\0';

	length = length-1; //will point to the last character
	
	while(length>=0){

		if(string[length]!=' '){
			string[new_length-1] = string[length];
			new_length--;
		}
		else{

			string[new_length-1] = '0';
			string[new_length-2] = '2';
			string[new_length-3] = '%';

			new_length-=3;
		}

		length--;
	}
}
int main(){

	char string[] = "My name is Sahil Mutneja        ";
	int length = 24;

	printf("String is \n%s\n", string);

	replace_spaces(string, length);

	printf("String after replacing spaces \n%s\n", string);
	return 0;
}