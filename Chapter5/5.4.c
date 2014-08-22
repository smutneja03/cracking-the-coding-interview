
#include <stdio.h>

int is_power(int a){

	if(a && ( ( a & (a-1) )==0) )
		return 1;
	else
		return 0;

	//number should be a power of 2 to return true else will return 0
	//will return false for 0 and true for 1
}

int main(){

	int array[] = {37, 23, 2, 0, 64, 46, 1024};

	for(int i=0;i<sizeof(array)/sizeof(array[0]);i++){
		printf("%d --> ", array[i] );
		if(is_power(array[i]))
			printf("YES");
		else
			printf("NO");
		printf("\n");
	}

	return 0;

}