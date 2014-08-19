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

struct node *add_lists(struct node *n1, struct node *n2){

	int sum = 0, carry = 0;
	int data1, data2;
	struct node *result = NULL, *temp;

	while(n1 || n2){

		if(n1)
			data1 = n1->data;
		else
			data1 = 0;
		if(n2)
			data2 = n2->data;
		else
			data2 = 0;

		sum = data1 + data2 + carry;

		carry = sum/10;

		sum = sum % 10;

		if(result==NULL){
			result = new_node(sum);
			temp = result;
		}
		else{
			temp->next = new_node(sum);
			temp = temp->next;
		}

		if(n1)
			n1 = n1->next;
		if(n2)
			n2 = n2->next;
	}

	if(carry!=0)
		temp->next = new_node(carry);

	return result;

}

int main(){

	struct node *head1 = NULL;

	add_node(&head1, 4);
	add_node(&head1, 3);
	add_node(&head1, 9);
	add_node(&head1, 8);
	add_node(&head1, 7);

	print_list(head1);
	printf("\n");

	struct node *head2 = NULL;

	add_node(&head2, 7);
	add_node(&head2, 8);
	add_node(&head2, 9);

	print_list(head2);
	printf("\n");

	struct node *sum = add_lists(head1, head2);

	printf("The sum of the array is\n");

	print_list(sum);

	printf("\n");
	
	return 0;
}