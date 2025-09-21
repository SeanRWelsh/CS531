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

		/*checks to ensure the string a user input is a legal string if not
		 * a legal string the program does nothing with the string and reduces
		 * i by 1 in order to re-run this iteration of the loop until the user
		 * enters a legal string. If a legal string is entered then the users 
		 * input gets copied into the string array */
		if(checkStringLen(userInput) || checkLegalCharacters(userInput) ||
				checkDuplicate(userInput, stringsptr, i)){
			i--;
		}else{
			strcpy(*(stringsptr+i), userInput);
		}

		printf("total number of strings accepted so far  is %d \n", i+1);
		puts("please enter next string");
	}
}
