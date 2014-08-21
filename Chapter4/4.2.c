
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct list{

	struct node *head;
};

struct graph{

	int v;
	struct list *array;
};

struct node *new_node(int data){

	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;

	return temp;
}

struct graph *create_graph(int v){

	struct graph *temp = (struct graph *)malloc(sizeof(struct graph));

	temp->v = v;

	temp->array = (struct list *)malloc(sizeof(struct list) * v);

	int i;

	for(i=0;i<v;i++){

		temp->array[i].head = NULL;
	}

	return temp;

}

void add_edge(struct graph *temp, int src, int dest){

	struct node *node = new_node(dest);

	node->next = temp->array[src].head;

	temp->array[src].head = node;
	
	// Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
	node = new_node(src);

	node->next = temp->array[dest].head;

	temp->array[dest].head = node;

}	

void print_graph(struct graph *graph){

	int v = graph->v;

	int i;

	for(i=0;i<v;i++){

		printf("Vertex :: %d\n", i);

		struct node *temp = graph->array[i].head;

		while(temp!=NULL){

			printf("%d\t", temp->data);
			temp = temp->next;
		}

		printf("\n");
	}

}

int main(){

	int v = 5;

	struct graph *graph = create_graph(v);

	add_edge(graph, 0, 1);
	add_edge(graph, 0, 4);
	add_edge(graph, 1, 2);
	add_edge(graph, 1, 3);
	add_edge(graph, 1, 4);
	add_edge(graph, 2, 3);
	add_edge(graph, 3, 4);

	print_graph(graph);

	return 0;

}

