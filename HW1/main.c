#include "character_strings.h"
#include <stdio.h>
#include <ctype.h>

int checkBuffer(); 

int main(void){
	char *stringsptr[10];
	char strings[10][MAXLEN];
	for(int i = 0; i<10; i++){
		*(stringsptr +i) = strings[i];
	}

	int choice;
	puts("Welcome to the string sorting application");
	puts("this application accepts up to ten character string");
	puts("each string can include any characters except");
	puts("!, @, #, $, %, ^, (, or )");
	
	inputString(stringsptr);

	puts("would you prefer to sort your string in Ascending order (A)");
	puts("or decending order (B)? Please enter (A,B):");


	do{
		choice = getchar();
		if(choice == EOF) return 0;
		if(checkBuffer()){
			choice = tolower(choice);
		}else{
			puts("Incorrect entry please enter either A or B");
			choice = 0;
		}
	}while (choice != 'a' && choice != 'b');
	puts("please enter 10 unique character strings");

	return 0;
}

/*checks buffer. If the next character is a new line or EOF returns 1 for
   the buffer only containing 1 character. otherwise clears the buffer and returns
   a 0 */
int checkBuffer(){
	int c;

	if((c=getchar()) == '\n' || c == EOF) return 1;
	while((c=getchar()) != '\n' && c != EOF);
	return 0;
}

