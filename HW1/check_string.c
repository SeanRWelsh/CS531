#include <stdio.h>
#include <string.h>
#include "character_strings.h"

/*Check legal Characters ensures the following characters are not in the string passed to it
 * !’, ’@’, ’#’, ’$’, ‘%’, ‘^’, ’(’, or ’)’. If one of these characters is found it prints to
 * stdout stating what illegal character was found and returns a 1
 * */
int checkLegalCharacters(char *string_to_check){
	for(int j = 0, char_to_check; (char_to_check = *(string_to_check+j)) != '\0'; j++){
		if(char_to_check == EOF || char_to_check == 0x21 || char_to_check == 0x40 ||
				char_to_check == 0x5E || char_to_check == 0x28 || 
				char_to_check == 0x29){
			printf("the character %c is not allowed\a\n", char_to_check);
			return 1;
		}else if(char_to_check >= 0x23 && char_to_check <= 0x25){
			printf("the character %c is not allowed\a\n", char_to_check);
			return 1;
		}
	}
	return 0;
}

/*checkDuplicate loops through the array checking if any string matches the string passed into it.
 * if no matches returns 0. If a match is found returns 1
 * */
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

/* checkStringLen takes in a string and checks if it is >= 2 characters long and < 26
 * if the string falls within these parameters returns 0 otherwise returns 1
 * */
int checkStringLen(char *string_to_check){
	int length_of_string = strlen(string_to_check);
	if(length_of_string > 26){
		puts("string entered is too long please try again");
		return 1;
	}else if(length_of_string <= 2){
		puts("string entered is to short please try again");
		return 1;
	}

	//removes '/n' character added by fgets before returning
	string_to_check[strlen(string_to_check)-1] = '\0';
	return 0;
}
