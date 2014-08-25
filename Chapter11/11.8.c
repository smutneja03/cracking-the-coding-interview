
#include <stdio.h>
#include <stdlib.h>

struct node{

	int data;
	struct node *left;
	struct node *right;
};

struct node *new_node(int data){

	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

struct node *add_node(struct node *root, int data){

	if(root==NULL)
		root = new_node(data);

	else if(data > root->data)
		root->right = add_node(root->right, data);
	else
		root->left = add_node(root->left, data);

	return root;
}

void print_inorder(struct node *root){

	if(root==NULL)
		return;

	print_inorder(root->left);
	printf("%d\t", root->data);
	print_inorder(root->right);

}

int left_size(struct node *root){

	if(root==NULL)
		return 0;

	return left_size(root->left) + 1 + left_size(root->right);
}

int get_rank(struct node *root, int data){

	if(root==NULL)
		return 0;

	if(root->data == data){

		return left_size(root->left);
	}

	if(data < root->data){

		return get_rank(root->left, data);
	}

	if(data > root->data){

		return left_size(root->left) + 1 + get_rank(root->right, data);
	}

	return 0;
}

int main(){

	struct node *root = NULL;

	root = add_node(root, 20);
	root = add_node(root, 15);
	root = add_node(root, 25);
	root = add_node(root, 10);
	root = add_node(root, 23);
	root = add_node(root, 5);
	root = add_node(root, 13);
	root = add_node(root, 24);

	print_inorder(root);

	printf("\n");

	printf("%d is the rank of 20\n", get_rank(root, 20));

	printf("%d is the rank of 10\n", get_rank(root, 10));

	printf("%d is the rank of 5\n", get_rank(root, 5));

	printf("%d is the rank of 24\n", get_rank(root, 24));

	printf("%d is the rank of 25\n", get_rank(root, 25));

	return 0;
}
