//remove from unsorted linked list

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

void add_node(struct node **head_ref, int data){

	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = *head_ref;
	*head_ref = temp;
}

void print_list(struct node *head){

	struct node *temp = head;

	while(temp!=NULL){

		printf("%d\t", temp->data);
		temp = temp->next;
	}
}

struct node *kth_last(struct node *head, int k){

	struct node *temp = head;
	int count = 0;

	while(count < k){

		temp = temp->next;
		count++;
	}

	struct node *main = head;

	while(temp){

		temp = temp->next;
		main = main->next;
	}

	return main;
}

int main(){

	struct node *head = NULL;

	add_node(&head, 1);
	add_node(&head, 9);
	add_node(&head, 6);
	add_node(&head, 4);
	add_node(&head, 7);

	print_list(head);
	printf("\n");

	int k = 3;
	struct node *temp = kth_last(head, k);

	printf("%d element from the end is %d\n",k, temp->data );

	return 0;
}