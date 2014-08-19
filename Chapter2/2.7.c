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

void reverse(struct node **head){

	struct node *current  = *head;
	struct node *prev  =NULL;
	struct node *next;

	while(current!=NULL){

		next = current->next;
		current->next = prev;
		prev = current;
		current = next;

	}

	*head = prev;
}

int compare(struct node *a, struct node *b){

	struct node *temp1 = a;
	struct node *temp2 = b;

	while(temp1 && temp2){

		if(temp1->data!=temp2->data)
			return 0;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	if(temp1==NULL && temp2==NULL)
		return 1;
	else
		return 0;

}

int palindrome(struct node *head){

	struct node *fast = head;
	struct node *slow = head;
	struct node *prev;
	
	while(fast && fast->next){
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	if(fast!=NULL){
		//odd number of nodes
		struct node *mid = slow;
		slow = slow->next;
	}
	
	struct node *second = slow;
	prev->next = NULL;
	reverse(&second);

	int res = compare(head, second);

	return res;

}

int main(){

	struct node *head = NULL;

	add_node(&head, 1);
	add_node(&head, 9);
	add_node(&head, 6);
	add_node(&head, 6);
	add_node(&head, 9);
	add_node(&head, 1);

	print_list(head);
	printf("\n");

	if(palindrome(head))
		printf("YES PALINDROME\n");
	else
		printf("NO PALINDROME\n");

	return 0;
}
