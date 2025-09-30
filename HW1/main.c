#include "character_strings.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void){
	char *stringsptr[MAXINPUT];      //array of pointers that point to the strings in
					 //the strings array
	char strings[MAXINPUT][MAXLEN];  //array of strings. Strings are generated from user input
	int choice;                      //stores the users choice to sort by ascending or descending
	char userInput[10];              //stores user input

	/*sets up the stringsptr pointers to point to each individual string in the strings array*/
	for(int i = 0; i<10; i++){
		*(stringsptr +i) = strings[i];
	}

	puts("Welcome to the string sorting application");
	puts("this application accepts up to ten character string between 2 and 25 characters");
	puts("each string can include any characters except");
	puts("!, @, #, $, %, ^, (, or )");

	inputString(stringsptr);

	puts("would you prefer to sort your string in Ascending order (A)");
	puts("or descending order (B)? Please enter (A,B):");

	//loop to ensure a correct input(a or b) from the user is entered
	do{
		fgets(userInput, sizeof(userInput), stdin);
		userInput[strlen(userInput)-1] = '\0';
		userInput[0] = tolower(userInput[0]);
		if(strcmp(userInput, "a") == 0 || strcmp(userInput, "b") ==0){
			choice = userInput[0];
		}else{

			puts("Incorrect entry please enter either A or B");
			choice = 0;
		}
	}while (choice != 'a' && choice != 'b');


	if(choice == 'a'){
		qsort(stringsptr, 0, MAXINPUT-1, 'a');
		puts("your strings sorted in ascending order");
	}else{
		qsort(stringsptr, 0, MAXINPUT-1, 'b');
		puts("your strings sorted in descending order");
	}
	for(int i=0; i<10; i++){
		printf("%d. %s\n",i+1, *(stringsptr+i));
	}
	return 0;
}
