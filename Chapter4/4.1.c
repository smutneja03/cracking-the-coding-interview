
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

int max(int a, int b){

	if(a>b)
		return a;
	else
		return b;
}

int height_balanced(struct node *root, int *height){

	int l=0, r=0;
	int lh = 0, rh = 0;

	if(root==NULL){
		*height = 0;
		return 1;
	}

	l = height_balanced(root->left, &lh);
	r = height_balanced(root->right, &rh);

	*height = max(lh, rh) + 1;

	if( (lh-rh)>=2 || (rh-lh)>=2)
		return 0;
	else
		return l&&r;
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
	root = add_node(root, 19);

	print_inorder(root);
	printf("\n");

	int height = 0;
	
	if(height_balanced(root, &height))
		printf("HEIGHT BALANCED\n");
	else
		printf("NOT HEIGHT BALANCED\n");

	return 0;
}
