
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

	else if(root->data > data)
		root->left = add_node(root->left, data);
	else
		root->right = add_node(root->right, data);

	return root;

}
void print_inorder(struct node *root){

	if(root==NULL)
		return;
	print_inorder(root->left);
	printf("%d\t", root->data);
	print_inorder(root->right);
}

void print_list(struct node *head){

	struct node *temp = head;

	while(temp!=NULL){

		printf("%d\n", temp->data);
		temp = temp->right;
	}
}

void tree_list(struct node *root, struct node **head_ref, struct node **prev){

	if(root==NULL)
		return ;

	tree_list(root->left, head_ref, prev);

	if((*prev)==NULL){

		*head_ref = root;
	}

	else{

		root->left = *prev;
		(*prev)->right = root;
	}

	*prev = root;

	tree_list(root->right, head_ref, prev);

}

int main(){

	struct node *root = NULL;

	root = add_node(root, 10);
	root = add_node(root, 8);
	root = add_node(root, 6);
	root = add_node(root, 9);
	root = add_node(root, 12);
	root = add_node(root, 14);

	print_inorder(root);
	printf("\n");

	struct node *head = NULL;

	struct node *prev = NULL;

	tree_list(root, &head, &prev);

	printf("\nPrinting in Doubly Linked List\n");
	
	print_list(head);

	return 0;
}