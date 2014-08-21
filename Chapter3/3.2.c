
#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 10

void print_stack(int *main, int *min, int first, int second){

	int i;
	printf("\nMain Stack is\n");
	for(i=0;i<first;i++)
		printf("%d\t", main[i]);

	printf("\nMin Stack is\n");
	for(i=0;i<second;i++)
		printf("%d\t", min[i]);
}

int top(int *array, int top){

	int index = top -1;
	return array[index];
}

void push(int *main, int *min, int data, int *first, int *second){

	main[ (*first)++ ] = data;

	if(*second ==0 || data <= top(min, *second) ){
		min[(*second)++] = data;
		return;
	}

}

int pop(int *main, int *min, int *first, int *second){

	if(*first==0 && *second==0){
		printf("Stack is empty\n");
		exit(0);
	}

	(*first)--;
	int index = (*first);

	int temp = main[index];

	if(temp <= top(min, *second) ){
		(*second)--;
	}

	return temp;
}

int min_element(int *array, int top){

	if(top==0)
		return -1;
	top = top-1;
	return array[top];
}

int main(){

	int *main_stack = (int *)malloc(sizeof(int) * STACKSIZE);
	int *min_stack = (int *)malloc(sizeof(int) * STACKSIZE);
	int top_main = 0;
	int top_min = 0;

	push(main_stack, min_stack, 3, &top_main, &top_min);
	push(main_stack, min_stack, 5, &top_main, &top_min);
	push(main_stack, min_stack, 1, &top_main, &top_min);
	push(main_stack, min_stack, 4, &top_main, &top_min);
	push(main_stack, min_stack, 7, &top_main, &top_min);
	push(main_stack, min_stack, 0, &top_main, &top_min);
	push(main_stack, min_stack, 3, &top_main, &top_min);
	push(main_stack, min_stack, 6, &top_main, &top_min);
	
	print_stack(main_stack, min_stack, top_main, top_min);

	printf("\nMin element = %d\n", min_element(min_stack, top_min));

	int a = pop(main_stack, min_stack, &top_main, &top_min);
	printf("\nPopped %d\n", a);

	a = pop(main_stack, min_stack, &top_main, &top_min);
	printf("\nPopped %d\n", a);

	printf("Min element = %d\n", min_element(min_stack, top_min));
	a = pop(main_stack, min_stack, &top_main, &top_min);
	printf("\nPopped %d\n", a);
	
	a = pop(main_stack, min_stack, &top_main, &top_min);
	printf("\nPopped %d\n", a);

	print_stack(main_stack, min_stack, top_main, top_min);

	printf("\nMin element = %d\n", min_element(min_stack, top_min));

	a = pop(main_stack, min_stack, &top_main, &top_min);
	printf("\nPopped %d\n", a);

	printf("Min element = %d\n", min_element(min_stack, top_min));
	a = pop(main_stack, min_stack, &top_main, &top_min);
	printf("\nPopped %d\n", a);
	
	a = pop(main_stack, min_stack, &top_main, &top_min);
	printf("\nPopped %d\n", a);

	print_stack(main_stack, min_stack, top_main, top_min);

	printf("\nMin element = %d\n", min_element(min_stack, top_min));

	a = pop(main_stack, min_stack, &top_main, &top_min);
	printf("\nPopped %d\n", a);
	a = pop(main_stack, min_stack, &top_main, &top_min);
	printf("\nPopped %d\n", a);
	
	printf("\n");

	return 0;
}




