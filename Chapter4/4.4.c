
#include <stdio.h>
#include <stdlib.h>

struct tnode{
	int data;
	struct tnode *left;
	struct tnode *right;
};

struct lnode{
	int data;
	struct lnode *next;
};

struct tnode *tree_new_node(int data){

	struct tnode *temp = (struct tnode *)malloc(sizeof(struct tnode));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

void list_add_node(struct lnode **head_ref, int data){

	struct lnode *temp = (struct lnode *)malloc(sizeof(struct lnode));
	temp->data = data;
	temp->next = *head_ref;
	*head_ref = temp;
}

struct tnode *tree_add_node(struct tnode *root, int data){

	if(root==NULL)
		root = tree_new_node(data);
	else if(data > root->data)
		root->right = tree_add_node(root->right, data);
	else
		root->left = tree_add_node(root->left, data);

	return root;
}

void print_inorder(struct tnode *root){

	if(root==NULL)
		return ;
	print_inorder(root->left);
	printf("%d\t", root->data);
	print_inorder(root->right);
}

int get_depth(struct tnode *root){

	if(root==NULL)
		return 0;

	int ldepth = get_depth(root->left);
	int rdepth = get_depth(root->right);

	if(ldepth < rdepth)
		return rdepth + 1;
	else
		return ldepth + 1;
}

void form_lists(struct tnode *root, struct lnode **array, int level){

	if(root==NULL)
		return;

	form_lists(root->right, array, level+1);

	list_add_node(&array[level], root->data);

	form_lists(root->left, array, level+1);

}

void print_lists(struct lnode **array, int size){

	int i;

	for(i=0;i<size;i++){

		printf("\nPrinting Level %d\n", i);

		struct lnode *temp = array[i];

		while(temp!=NULL){

			printf("%d\t", temp->data);
			temp = temp->next;
		}

		printf("\n");
	}

}

int main(){

	struct tnode *root = NULL;

	root = tree_add_node(root, 10);
	root = tree_add_node(root, 5);
	root = tree_add_node(root, 12);
	root = tree_add_node(root, 3);
	root = tree_add_node(root, 7);
	root = tree_add_node(root, 11);
	root = tree_add_node(root, 14);
	root = tree_add_node(root, 17);

	print_inorder(root);

	int depth = get_depth(root);

	struct lnode **array = (struct lnode **)malloc(sizeof(struct lnode) * depth);

	form_lists(root, array, 0);

	print_lists(array, depth);
	return 0;
}
