
#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 10

void print_array(int *array){
	int i;

	for(i=0;i<STACKSIZE;i++)
		printf("%d\t", array[i]);
}

void shift_left(int *array, int *first, int *last, int n){

	int diff = *last - *first;
	int new_first = *first -n;
	int temp = new_first;
	int i = 0;

	while(i<diff){

		array[new_first] = array[*first];
		new_first++;
		(*first)++;
		i++;
	}

	*last = new_first;
	*first = temp;
}

void shift_right(int *array, int *first, int *last, int n){

	int diff = *last - *first; //number of elements in middle stack

	int new_last = *last +n -1;
	int temp = new_last;
	int i=0;
	(*last)--;

	while(i<diff){

		array[new_last] = array[*last];
		new_last--;
		(*last)--;
		i++;
	}

	*first = new_last + 1;
	*last = temp+1;
}
void stack1_push(int *array, int data, int *top1, int *top2, int *top3, int *top4){

	if(( (*top1) == (*top3) && (*top4) == (*top2)+1 )){
		printf("Stack is full, Pop some elements first\n");
		return;
	}

	if( (*top1==*top3) && (*top4)-1!=(*top2)+1 ){
		//middle stack needs to be shifted to end
		int capacity = (*top2) - (*top4) + 1;
		if(capacity>=2)
			capacity = capacity/2;

		if(capacity>=1)
			shift_right(array, top3, top4, capacity);
	}

	array[*top1] = data;
	(*top1)++;
}

void stack3_push(int *array, int data, int *top1, int *top2, int *top3, int *top4){

	if(( (*top1) == (*top3) && (*top4) == (*top2)+1 )){
		printf("Stack is full, Pop some elements first\n");
		return;
	}

	if( ( (*top2)+1==*top4) && (*top1)!=(*top3) ){
		//middle stack needs to be shifted to end
		int capacity = (*top3) - (*top1);

		if(capacity>=2)
			capacity = capacity/2;

		if(capacity>=1)
			shift_left(array, top3, top4, capacity);
	}


	array[*top4] = data;
	(*top4)++;
}

void stack2_push(int *array, int data, int *top1, int *top2, int *top3, int *top4){

	if(( (*top1) == (*top3) && (*top4) == (*top2)+1 )){
		printf("Stack is full, Pop some elements first\n");
		return;
	}

	if( (*top2)+1==(*top4) && (*top1)!=(*top3) ){
		//middle stack needs to be shifted to end
		int capacity = (*top3) - (*top1);

		if(capacity>=2)
			capacity = capacity/2;

		if(capacity>=1)
			shift_left(array, top3, top4, capacity);
	}

	array[*top2] = data;
	(*top2)--;
}

int stack1_pop(int *array, int *top){

	if(*top==0){
		printf("No elements to pop\n");
		return -1;
	}
	(*top)--;
	int temp = array[*top];
	array[*top] = 0;
	return temp;
}


int stack2_pop(int *array, int *top){

	if(*top==STACKSIZE-1){
		printf("No elements to pop\n");
		return -1;
	}
	(*top)++;
	int temp = array[*top];
	array[*top] = 0;
	return temp;
}

int stack3_pop(int *array, int *first, int *last){

	if(*first==*last){
		printf("No elements to pop\n");
		return -1;
	}
	(*last)--;
	int temp = array[*last];
	array[*last] = 0;
	return temp;
}

int main(){

	int *array = (int *)malloc(sizeof(int) * STACKSIZE);

	int start = 0, end = STACKSIZE-1;
	int middle = (start+end)/2;

	int top1 = start; //for the stack at the beginning
	int top2 = end;//for the stack at the end

	int top3 = middle, top4 = middle;

	//the top of the three stacks have been defined by now

	stack1_push(array, 30, &top1, &top2, &top3, &top4);
	print_array(array);
	printf("\n");
	stack1_push(array, 27, &top1, &top2, &top3, &top4);
	print_array(array);
	printf("\n");


	stack2_push(array, 11, &top1, &top2, &top3, &top4);
	print_array(array);
	printf("\n");
	stack2_push(array, 17, &top1, &top2, &top3, &top4);
	print_array(array);
	printf("\n");


	stack3_push(array, 29, &top1, &top2, &top3, &top4);
	print_array(array);
	printf("\n");
	stack3_push(array, 89, &top1, &top2, &top3, &top4);
	print_array(array);
	printf("\n");

	stack3_push(array, 37, &top1, &top2, &top3, &top4);
	print_array(array);
	printf("\n");
	stack3_push(array, 91, &top1, &top2, &top3, &top4);
	print_array(array);
	printf("\n");
	stack3_push(array, 83, &top1, &top2, &top3, &top4);
	print_array(array);
	printf("\n");
	stack3_push(array, 26, &top1, &top2, &top3, &top4);
	print_array(array);
	printf("\n");
	stack3_push(array, 345, &top1, &top2, &top3, &top4);
	print_array(array);
	printf("\n");

	int a = stack1_pop(array, &top1);
	printf("%d is popped from array 1\n", a);
	print_array(array);
	printf("\n");

	a = stack2_pop(array, &top2);
	printf("%d is popped from array 2\n", a);
	print_array(array);
	printf("\n");

	a = stack3_pop(array, &top3, &top4);
	printf("%d is popped from array 3\n", a);
	print_array(array);
	printf("\n");

	stack1_push(array, 101, &top1, &top2, &top3, &top4);
	print_array(array);
	printf("\n");

	stack2_push(array, 107, &top1, &top2, &top3, &top4);
	print_array(array);
	printf("\n");

	stack2_push(array, 109, &top1, &top2, &top3, &top4);
	print_array(array);
	printf("\n");

	a = stack1_pop(array, &top1);
	printf("%d is popped from array 1\n", a);
	print_array(array);
	printf("\n");

	stack3_push(array, 1, &top1, &top2, &top3, &top4);
	print_array(array);
	printf("\n");

	return 0;
}