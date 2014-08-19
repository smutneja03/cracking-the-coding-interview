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

struct node *new_node(int data){

	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;

	return temp;
}

void print_list(struct node *head){

	struct node *temp = head;

	while(temp!=NULL){

		printf("%d\t", temp->data);
		temp = temp->next;
	}
}

struct node *get_beginning(struct node *head){

	struct node *slow = head;
	struct node *fast = head;

	while(fast && fast->next){

		slow = slow->next;
		fast = fast->next->next;

		if(fast==slow)
			break;
	}

	slow = head;

	while(slow!=fast){
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}

int main(){

	struct node *head = NULL;

	head = new_node(1);
	head->next = new_node(2);
	head->next->next = new_node(3);
	head->next->next->next = new_node(4);
	head->next->next->next->next = new_node(5);
	head->next->next->next->next->next = new_node(6);
	head->next->next->next->next->next->next = head->next->next;

	printf("\n");

	struct node *begin = get_beginning(head);

	printf("Node at the begin %d\n", begin->data);

	return 0;
}