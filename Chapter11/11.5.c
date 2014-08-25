
#include <stdio.h>
#include <stdlib.h>

int compare(char *a, char *b){

	char *temp1 = a;
	char *temp2 = b;

	while(*temp1 && *temp2){

		if(*temp1 > *temp2)
			return 1;

		else if (*temp1 < *temp2)
			return -1;

		else{

			temp1++;
			temp2++;
		}

	}

	if( *(temp1)=='\0' && *(temp2)=='\0' )
		return 0;

	else if(*temp1)
		return -1;
	else
		return 1;

}

int search(char array[][5], int start, int end, char s[]){

	if(start > end)
		return -1;

	int left, right;
	int mid = (start+end)/2;
	char *empty = "";

	if( compare(array[mid], empty)==0 ){ 

		left = mid-1;
		right = mid+1;

		while(left>=start && right <=end){

			if( compare(array[left], empty)!=0 ){
				mid = left;
				break;
			}

			if(compare(array[right], empty)!=0){
				mid = right;
				break;
			}

			left--;
			right++;
		}

		while(left>=start){

			if(compare(array[left], empty)!=0 ){
				mid = left;
				break;
			}
			left--;
		}

		while(right<=end){

			if(compare(array[right], empty)!=0){
				mid = right;
				break;
			}
			right++;
		}

		if(left<start && right>end){
			return -1;
		}
	}

	if(compare(array[mid], s)==0)
		return mid;
	//compares return 1 if ex (car, ball)
	else if(compare(array[mid], s)==1){

		return search(array, start, mid-1, s);
	}

	else{
		return search(array, mid+1, end, s);
	}
}

int main(){

	char array[][5] = {"at", "", "", "", "ball", "", "", "car", "", "" , "dad", "", ""};
	
	char s[] = "ball";

	int size = 13;

	int index = search(array, 0, size-1, s);

	printf("%s is at %d index\n", s, index);

	return 0;	
}