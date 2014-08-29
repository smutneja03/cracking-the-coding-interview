

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct node{

	int data;
	struct node *left;
	struct node *right;
};

struct node *new_node(int data){

	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data =data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

struct node *add_node(struct node *root, int data){

	if(root==NULL)
		root = new_node(data);

	else if(root->data < data)
		root->right = add_node(root->right, data);
	else
		root->left = add_node(root->left, data);

	return root;
}

struct node **create_stack(int *top){

	struct node **stack = (struct node **)malloc(sizeof(struct node *) * SIZE);

	*top = 0;

	return stack;
}

void push(struct node **stack, struct node *current, int *top){

	stack[*top] = current;

	(*top)++;

}

struct node *pop(struct node **stack, int *top){

	
	*top = *top-1;

	return stack[*top];

}

void preorder(struct node *root){

	int top;

	struct node **stack = create_stack(&top);

	struct node *current = root;

	push(stack, current, &top);

	while(top!=0){

		struct node *temp = pop(stack, &top);

		printf("%d\n", temp->data);

		if(temp->right)
			push(stack, temp->right, &top);

		if(temp->left)
			push(stack, temp->left, &top);
	}
}

int main(){

	struct node *root = NULL;

	root = add_node(root, 10);
	root = add_node(root, 8);
	root = add_node(root, 12);
	root = add_node(root, 4);
	root = add_node(root, 9);
	root = add_node(root, 7);
	root = add_node(root, 11);
	root = add_node(root, 14);

	preorder(root);

	return 0;

}

