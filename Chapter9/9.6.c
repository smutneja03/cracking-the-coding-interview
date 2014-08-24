
#include <stdio.h>
#include <stdlib.h>

void print_array(char *array, int pos){

	int i;
	for(i=0;i<pos;i++){
		printf("%c", array[i]);
	}
	printf("\n");
}
void print_util(int pos, int n, int open, int close, char *array){

	if(close==n){
		print_array(array, pos);
		return;
	}
	else{

		if(open < n){

			array[pos] = '{';
			print_util(pos+1, n, open+1, close, array);
		}
		if(close < open){
			array[pos] = '}';
			print_util(pos+1, n, open, close+1, array);
		}
	}

}

void print_parenthesis(int n){

	char *array = (char *)malloc(sizeof(char ) * 10);

	print_util(0, n, 0, 0, array);

	free(array);

}

int main(){

	int n = 3;

	print_parenthesis(n);

	return 0;
}