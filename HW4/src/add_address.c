#include "address_t.h"
#include <string.h>
#include <stdlib.h>

/* collects data from the user and attempts to add it to the tree. If it can not
 * be added the user is informed
 */
void add_address(){
	char *address, *alias;

	puts("please enter an IPV4 address with a format between 0.0.0.0 and "
			 "255.255.255.255");
	address = get_input(stdin); //collects user input for an address as a string
	puts("please enter an alias for this address no longer than 10 characters");
	alias = get_input(stdin); //collects user input for an alias as a string
	int combined_len = strlen(address) + 1 + strlen(alias) + 1; //get length for 
																															//combined string
	char *combined_string = malloc(combined_len); //allocate memory for string
	snprintf(combined_string, combined_len, "%s %s", address, alias); //load string
	add_to_tree(combined_string); //add user input data to tree if valid
	free(combined_string);
	free(address);
	free(alias);
}
