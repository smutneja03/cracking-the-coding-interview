
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
	temp->left=NULL;
	temp->right=NULL;

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

int bst_check_util(struct node *root, struct node **prev){

	if(root!=NULL){	
		if(!bst_check_util(root->left, prev))
			return 0;

		if(*prev!=NULL && root->data < (*prev)->data)
			return 0;

		*prev = root;

		return bst_check_util(root->right, prev);
	}
	return 1;

}

int is_bst(struct node *root){

	if(root==NULL)
		return 1;

	struct node *prev = NULL;
	
	return bst_check_util(root, &prev);

}

int main(){

	struct node *root = NULL;

	root = add_node(root, 10);
	root = add_node(root, 5);
	root = add_node(root, 12);
	root = add_node(root, 3);
	root = add_node(root, 7);
	root = add_node(root, 11);
	root = add_node(root, 14);
	root = add_node(root, 17);
	root->left->left->left = new_node(19);

	print_inorder(root);
	printf("\n");

	if(is_bst(root))
		printf("BST\n");
	else
		printf("NOT A BST\n");

	return 0;
}
