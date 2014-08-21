
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

struct node *min_node(struct node *n){

	struct node *temp = n;

	while(temp->left!=NULL){
		temp = temp->left;
	}

	return temp;
}

struct node *successor(struct node *root, struct node *n){

	if(n->right!=NULL)
		return min_node(n->right);

	struct node *temp = root;
	struct node *succ = NULL;

	while(temp!=NULL){

		if(temp->data > n->data){

			succ = temp;
			temp = temp->left;
		}
		else if(temp->data < n->data)
			temp = temp->right;
		else
			break;
	}

	return succ;
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

	print_inorder(root);
	printf("\n");

	struct node *n1 = root->left->right;
	struct node *n2 = root->right->right;

	struct node *n1_succ = successor(root, n1);
	struct node *n2_succ = successor(root, n2);
	if(n1_succ!=NULL)
		printf("Inorder succ of %d is %d\n", n1->data, n1_succ->data);
	else
		printf("No Successor\n");

	if(n2_succ!=NULL)
		printf("Inorder succ of %d is %d\n", n2->data, n2_succ->data);
	else
		printf("No Successor\n");
	return 0;
}
