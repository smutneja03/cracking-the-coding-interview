
#include <stdio.h>
#include <stdlib.h>

int get_length(char *string){

	int len = 0;

	char *temp = string;

	while(*temp){

		len++;
		temp++;
	}

	return len;
}

void print_numeric(char *string){

	int len = get_length(string);

	if(len==0 || len>4){

		printf("Not Allowed\n");
		exit(0);
	}

	char *single_digit[] = {"zero", "one", "two", "three", "four",
                              "five", "six", "seven", "eight", "nine"};

    char *two_digit[] = {"", "ten", "eleven", "twelve", "thirteen", "fourteen",
                     "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    char *tens_multiple[] = {"", "", "twenty", "thirty", "forty", "fifty",
                             "sixty", "seventy", "eighty", "ninety"};                 

    char *tens_power[] = {"hundred", "thousand"};

    if(len==1){

    	printf("%s\n", single_digit[*string - '0']);
    	return;
    }

    while(*string){

    	if(len>=3){

    		if(*string - '0' != 0){

    			printf("%s ", single_digit[*string - '0']);

    			printf("%s ", tens_power[len - 3]);
    		}

    		(len)--;
    	}

    	else{

    		if(*string == '1'){

    			printf("%s ", two_digit[ *string -'0' + *(string+1) -'0']);
    			return;
    		}

    		else if(*string == '2' && *(string+1) == '0'){

    			printf("twenty \n");
    			return;
    		}

    		else{

    			int i = *string - '0';
    			if(i)
    				printf("%s ", tens_multiple[i]);
    			string++;

    			if(*string!='0')
    				printf("%s\n", single_digit[*string - '0']);

    		}

    	}

    	string++;
    }                         
}

int main(){

	char *number = "1234";
	printf("%s is the string\n", number );
	print_numeric(number);
	printf("\n");

	number = "1876";
	printf("%s is the string\n", number);
	print_numeric(number);
	printf("\n");

	number = "7656";
	printf("%s is the string\n", number);
	print_numeric(number);
	printf("\n");

	number = "210";
	printf("%s is the string\n", number);
	print_numeric(number);
	printf("\n");

	return 0;
}