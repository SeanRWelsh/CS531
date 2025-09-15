#include <stdio.h>
#include <string.h>
#include "character_strings.h"


void inputString(char **stringsptr){
	char userInput[100];
	printf("Please enter 10 strings. Strings will be seperated by the enter key\n");
	for(int i=0; i<10; i++){
		/* fgets automatically adds '\n\ and \'0' to the end of the string
		 * so to accept a string of 25 characters not including the manditory '\0'
		 * we need to set the fgets length to 27 in order to account for these 
		 * additional characters.*/
		fgets(userInput, sizeof(userInput), stdin);

		/*to remove the unwanted \n use strlen to find the last character '\n' and
		 * -1 to account for the 0 offset and replace with '\0' character*/
		if(checkStringLen(userInput) || checkLegalCharacters(userInput) ||
				checkDuplicate(userInput, stringsptr, i)){
			i--;
		}else{
			strcpy(*(stringsptr+i), userInput);
		}


		printf("total number of strings accepted so far  is %d \n", i);
	}
}

int checkLegalCharacters(char *string_to_check){
	for(int j = 0, char_to_check; (char_to_check = *(string_to_check+j)) != '\0'; j++){
		if(char_to_check == EOF || char_to_check == 0x21 || char_to_check == 0x40 ||
				char_to_check == 0x5E || char_to_check == 0x28 || 
				char_to_check == 0x29){
			printf("the character %c is not allowed\n", char_to_check);
			return 1;
		}else if(char_to_check >= 0x23 && char_to_check <= 0x25){
			printf("the character %c is not allowed\n", char_to_check);
			return 1;
		}

		printf("current char = %c\n", char_to_check);
	}
	return 0;
}

int checkDuplicate(char *string_to_check, char **string_array, int i){

	for(int j = 0; j<i; j++){
		if(strcmp(string_to_check, *(string_array+j)) == 0){
			printf("string \" %s \" has already been entered please try again\n",
					string_to_check);
			return 1;
		}
	}
	return 0;
}

int checkStringLen(char *string_to_check){
	int length_of_string = strlen(string_to_check);
	if(length_of_string > 26){
		puts("string entered is too long please try again");
		while(getchar() != EOF);
		return 1;
	}else if(length_of_string <= 2){
		puts("string entered is to short please try again");
		return 1;
	}

	string_to_check[strlen(string_to_check)-1] = '\0';
	return 0;
}
