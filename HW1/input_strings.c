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



		printf("total number of strings accepted so far  is %d \n", i+1);
		puts("please enter next string");
	}
}
