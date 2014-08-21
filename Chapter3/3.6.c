
#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 10

void print_stack(int *array, int size){
	int i;

	printf("array after sorting\n");
	for(i=0;i<size;i++)
		printf("%d\n", array[i]);
}

int pop(int *array, int *top){

	(*top)--;
	int temp = array[*top];
	return temp;
}

void push(int *array, int *top, int data){

	array[(*top)++] = data;
}

int top(int *array, int top){

	top = top -1;

	return array[top];
}

void sort_stack(int *main, int *temp, int *top_main, int *temp_top){

	while(*top_main!=0){

		int element = pop(main, top_main);

		if(*temp_top==0)
			push(temp, temp_top, element);
		else{

			while(*temp_top>0 && top(temp, *temp_top) > element){

				push(main, top_main, pop(temp, temp_top));
			}
			push(temp, temp_top, element);
		}
	}
}
int main(){

	int *stack = (int *)malloc(sizeof(int)* STACKSIZE );

	int top_main = 0;

	stack[top_main++] = 3;
	stack[top_main++] = 5;
	stack[top_main++] = 1;
	stack[top_main++] = 4;
	stack[top_main++] = 2;

	int *temp_stack = (int *)malloc(sizeof(int )* 5);
	int temp_top = 0;

	sort_stack(stack, temp_stack, &top_main, &temp_top);

	print_stack(temp_stack, temp_top);

	return 0;
}