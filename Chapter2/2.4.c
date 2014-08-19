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

struct node *partition(struct node *head, int k){

	struct node *temp =  head;

	struct node *less = NULL;
	struct node *greater = NULL;

	while(temp!=NULL){

		if(temp->data < k){

			add_node(&less, temp->data);
		}
		else
			add_node(&greater, temp->data);

		temp = temp->next;
	}

	printf("Check\n");
	struct node *ptr = less;

	while(ptr->next!=NULL){
		ptr = ptr->next;
	}

	ptr->next = greater;

	return less;
}

int main(){

	struct node *head = NULL;

	add_node(&head, 13);
	add_node(&head, 19);
	add_node(&head, 26);
	add_node(&head, 7);
	add_node(&head, 11);
	add_node(&head, 17);
	add_node(&head, 7);
	add_node(&head, 9);
	add_node(&head, 3);

	print_list(head);
	printf("\n");

	int k = 13;

	struct node *final_head = partition(head, k);

	printf("Printing the list after partitioning\n");
	print_list(final_head);
	printf("\n");
	
	return 0;
}