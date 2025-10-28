#include "address_t.h"
#include <stdlib.h>

void aliases_for_location(){
	int is_valid = 0; //flag to check if input is valid
	int len = 0; //flag to check string to int conversion
	char *user_input; //pointer to store user input
	int octet1, octet2; //holds user input for each octet

	while(is_valid == 0){
		puts("please enter the first address octet (0-255)");
		user_input = get_input(stdin); //collects the first octet from the user as a string
		len = sscanf(user_input, "%d", &octet1); //converts address from a string to an int. If successfull saves 1 in len
		if(len != 1 || octet1 < 0 || octet1 > 255){
			puts("invalid input please try again");
		}else{
			is_valid = 1;
		}
		free(user_input);
		len = 0;
	}

	is_valid = 0;

	while(is_valid == 0){
		puts("please enter the second address octet (0-255)");
		user_input = get_input(stdin); //collects the first octet from the user as a string
		len = sscanf(user_input, "%d", &octet2); //converts address from a string to an int. If successfull saves 1 in len
		if(len != 1 || octet2 < 0 || octet2 > 255){
			puts("invalid input please try again");
		}else{
			is_valid = 1;
		}
		free(user_input);
		len = 0;
	}
	is_valid = 0;

	print_location_list(octet1, octet2); //prints out nodes in the location specified by the user or an error message if none
}
