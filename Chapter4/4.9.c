

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

int get_depth(struct node *root){

	if(root==NULL)
		return 0;

	int ldepth = get_depth(root->left);
	int rdepth = get_depth(root->right);

	if(ldepth > rdepth)
		return ldepth+1;
	else
		return rdepth+1;
}

void print_array(int *array, int start, int end){

	int i;
	for(i=start;i<=end;i++)
		printf("%d\t", array[i]);

	printf("\n");

}

void print_paths_util(struct node *root, int *path, int sum, int level){

	if(root==NULL)
		return;

	path[level] = root->data;

	int i, sum_check = 0;

	for(i=level;i>=0;i--){

		sum_check = path[i] + sum_check;

		if(sum_check==sum)
			print_array(path, i, level);
	}

	print_paths_util(root->left, path, sum, level+1);

	print_paths_util(root->right, path, sum, level+1);
}

void print_paths(struct node *root, int sum){

	int depth = get_depth(root);

	int *path = (int *)malloc(sizeof(int) * depth);

	print_paths_util(root, path, sum, 0);
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

	int sum = 22;

	print_paths(root, sum);

	return 0;
}
