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

int is_identical(struct node *n1, struct node *n2){

	if(n1==NULL && n2==NULL)
		return 1;

	if(n1==NULL || n2==NULL)
		return 0;

	return (n1->data==n2->data && is_identical(n1->left, n2->left) && is_identical(n1->right, n2->right));

}

int is_subtree(struct node *big, struct node *small){

	if(big==NULL)
		return 0;
	if(small==NULL)
		return 1;

	if(is_identical(big, small))
		return 1;

	return is_subtree(big->left, small) || is_subtree(big->right, small);
}

int main(){

	struct node *root1 = NULL;

	root1 = add_node(root1, 10);
	root1 = add_node(root1, 5);
	root1 = add_node(root1, 12);
	root1 = add_node(root1, 3);
	root1 = add_node(root1, 7);
	root1 = add_node(root1, 11);
	root1 = add_node(root1, 14);
	root1 = add_node(root1, 17);
	root1 = add_node(root1, 19);

	print_inorder(root1);
	printf("\n");

	struct node *root2 = NULL;

	root2 = add_node(root2, 12);
	root2 = add_node(root2, 11);
	root2 = add_node(root2, 14);
	root2 = add_node(root2, 17);
	root2 = add_node(root2, 19);
	//root2 = add_node(root2, 1);

	print_inorder(root2);
	printf("\n");

	if(is_subtree(root1, root2))
		printf("IS SUBTREE\n");
	else
		printf("NOT A SUBTREE\n");
	return 0;
}
