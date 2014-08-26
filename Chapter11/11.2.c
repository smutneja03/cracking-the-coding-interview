
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Write a method to sort an array of strings so that all 
//the anagrams are next to each other.

struct word{

	char *string;
	int index;
};

struct word_array{

	struct word *array;
	int size;
};

struct word_array *duplicate(char *str[], int size){

	struct word_array *temp = (struct word_array *)malloc(sizeof(struct word_array));
	
	temp->size = size;

	temp->array = (struct word *)malloc(sizeof(struct word) * size);

	int i;
	
	for(i=0;i<size;i++){

		temp->array[i].index = i;
		temp->array[i].string = (char *)malloc(strlen(str[i] )+ 1);

		strcpy(temp->array[i].string, str[i]);
	}	

	return temp;

}

int compare_char(const void *a, const void *b){

	return *(char *)a - *(char *)b;
}

int compare_string(const void *a, const void *b){

	struct word *a1 = (struct word *)a;
	struct word *b1 = (struct word *)b;

	return strcmp(a1->string, b1->string);
}

void anagrams_together(char *words[], int size){

	struct word_array * temp = duplicate(words, size);

	int i;
	for(i=0;i<size;i++){

		qsort(temp->array[i].string, strlen(temp->array[i].string), sizeof(char), compare_char);

	}

	qsort(temp->array, size, sizeof(temp->array[0]), compare_string);

	for(i=0;i<size;i++){

		printf("%s\t", words[temp->array[i].index]);
	}
	
	printf("\n");
}

int main(){

	char *words[] = {"cat", "dog", "tac", "god", "act"};

	int size = sizeof(words)/sizeof(words[0]);

	anagrams_together(words, size);

	return 0;
}