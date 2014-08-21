//also takes care if the keys are not present

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

int find(struct node *temp, int key){

	if(temp==NULL)
		return 0;
	else
		return temp->data==key || find(temp->left, key) || find(temp->right, key);

}

struct node *lca_util(struct node *root, int n1, int n2, int *a, int *b){

	if(root==NULL)
		return NULL;

	if(root->data==n1){
		*a = 1;
		return root;
	}

	if(root->data==n2){
		*b = 1;
		return root;
	}

	struct node *left_lca = lca_util(root->left, n1, n2, a, b);
	struct node *right_lca =  lca_util(root->right, n1, n2, a, b);

	if(left_lca && right_lca)
		return root;
	else
		if(left_lca)
			return left_lca;
		else
			return right_lca;
}

struct node *get_lca(struct node *root, int n1, int n2){

	int a = 0, b=0;

	struct node *lca = lca_util(root, n1, n2, &a, &b);

	if( (a&&b) || (a && find(lca, n2)) || (b && find(lca, n1)) )
		return lca;
	else
		return NULL;

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

	int n1 = 7;
	int n2 = 11;

	struct node *lca = get_lca(root, n1, n2);

	printf("%d is the LCA of %d and %d\n", lca->data, n1, n2);

	n1 = 11;
	n2 = 1;

	lca = get_lca(root, n1, n2);
	
	if(lca!=NULL)
		printf("%d is the LCA of %d and %d\n", lca->data, n1, n2);
	else
		printf("Keys are not present\n");
	return 0;
}
