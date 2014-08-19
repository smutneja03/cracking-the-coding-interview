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

struct node *merge(struct node *a, struct node *b){

	struct node *result;

	if(a==NULL)
		return b;
	if(b==NULL)
		return a;

	if(a->data < b->data){
		result = a;
		result->next = merge(a->next, b);
	}

	else{

		result = b;
		result->next = merge(a, b->next);
	}

	return result;
}

void split_list(struct node *head, struct node **a, struct node **b){

	struct node *temp = head;

	struct node *slow;
	struct node *fast;

	if(head==NULL || head->next==NULL){
		*a = head;
		*b = NULL;
	}
		
	else{
	
		slow = head;
		fast = head->next;

		while(fast!=NULL){
			fast = fast->next;
			if(fast!=NULL){
				slow = slow->next;
				fast = fast->next;
			}
		}

		*a = head;
		*b = slow->next;
		slow->next = NULL;
	}
}

void remove_duplicates(struct node *head){

	struct node *temp = head;
	struct node *next;

	while(temp && temp->next){

		next = temp->next;

		if(next->data == temp->data){

			temp->next = next->next;
			free(next);
		}
		else
			temp = temp->next;
	}
}

void merge_sort(struct node **head_ref){

	if( (*head_ref)==NULL || (*head_ref)->next==NULL)
		return;

	struct node *temp = *head_ref;
	struct node  *a;
	struct node *b;

	split_list(temp, &a, &b);

	merge_sort(&a);
	merge_sort(&b);

	*head_ref = merge(a, b);
}

int main(){

	struct node *head = NULL;

	add_node(&head, 1);
	add_node(&head, 9);
	add_node(&head, 1);
	add_node(&head, 1);
	add_node(&head, 7);
	add_node(&head, 4);
	add_node(&head, 4);
	add_node(&head, 7);
	add_node(&head, 6);

	print_list(head);
	printf("\n");

	merge_sort(&head);
	printf("List after Sorting\n");

	print_list(head);
	printf("\n");

	remove_duplicates(head);
	printf("List after removing duplicates\n");
	print_list(head);
	printf("\n");
	return 0;
}