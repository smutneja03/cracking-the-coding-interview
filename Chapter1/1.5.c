
#include <stdio.h>
#include <stdlib.h>

char *encode_string(char *string){

	int rlen = 0;
	int length = 0;
	int i=0;

	while(*(string+i)){
		i++;length++;
	}

	int final_length = 2*length +1;
	char *final = (char *)malloc(sizeof(char) * final_length);
	char count[10];
	int final_index=0;
	i=0;
	while(*(string+i)){

		final[final_index] = *(string+i);
		i++;
		rlen = 1;
		while(*(string+i)){
			if(string[i]==final[final_index]){
				rlen++;
				i++;
			}
			else
				break;
		}

		sprintf(count, "%d", rlen);
		final_index++;
		int j = 0;
		while(*(count+j))
			final[final_index++] = count[j++];
	}

	final[final_index] = '\0';
	return final;
}

int main(){

	char string[] = "aabbcccccdddeeeeeeff";
	printf("%s\n", string);

	char *final =encode_string(string);
	
	printf("String after encoding is\n");
	printf("%s\n", final);
	return 0;
}