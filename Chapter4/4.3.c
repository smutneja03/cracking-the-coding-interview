
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
		return ;
	
	print_inorder(root->left);
	printf("%d\t", root->data);
	print_inorder(root->right);

}

struct node *construct_bst(int *array, int start, int end){

	if(start<end){

		int mid =(start+end)/2;
		struct node *root = new_node(array[mid]);

		root->left = construct_bst(array, start, mid-1);
		root->right = construct_bst(array, mid+1, end);

		return root;
	}

	return NULL;
}

int main(){

	int array[] = {2, 4, 5, 7, 9, 10, 11, 17, 21, 25, 31, 37};

	int size = sizeof(array)/sizeof(array[0]);

	struct node *root = construct_bst(array, 0, size-1);

	printf("Printing the Inorder Traversal\n");
	print_inorder(root);
	printf("\n");

	return 0;
}
