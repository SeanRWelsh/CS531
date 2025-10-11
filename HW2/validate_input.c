#include "read_files.h"
#include <stdio.h>
#include <string.h>

int is_duplicate_name(struct address_t *list_item, struct address_t *input);
int is_octet_in_range(struct address_t *input);
void print_input_not_added(struct address_t *input);

int is_valid_input(struct address_t *input){
	struct address_t *current = head;
	if(is_octet_in_range(input) == 1) return 0;
	while(current != NULL){
		if(is_duplicate_name(current, input) == 1 || 
		   is_duplicate_address(current->octet, input->octet) == 1 ||
		   is_octet_in_range(input) == 1){
			return 0;
		}
		current = current->next;
	}
	return 1;
}

int is_octet_in_range(struct address_t *input){
	for(int i = 0; i < 4; i++){
		if( input->octet[i] > 255 || input->octet[i] < 0){
			puts("address has an octet out of range must be between 0 and 255");
			print_input_not_added(input);
			return 1;
		}
	}
	return 0;
}

/* is_duplicate_name accepts a pointer to two address_t structures. It uses the strcasecmp
 * function to compare each structures alias field. strcasecmp was used because it ignores case. 
 * If it is found that the aliases are the same then is_duplicate_name informs the user by printing
 * the duplicate and informing them it was not added to the list and returns 1. If the names are
 * different then is_duplicate_name returns 0 */
int is_duplicate_name(struct address_t *list_item, struct address_t *input){
	if(strcasecmp(list_item->alias, input->alias) == 0){
		printf("The name %s is already in the list\n", input->alias);
		print_input_not_added(input);
		return 1;
	}
	return 0;
}

/* is_duplicate_address acceppts a pointer to two address_t structures. It compares the items in the
 * octet array fields for each structure. If each structure has the same 4 octet indexes 
 * is_duplicate_address informs the user and prints out the duplicate then returns 1. If even 1 of
 * the 4 octet indexes is different in the structure then a duplicate was not found and 
 * is_duplicate_address returns 0 */
int is_duplicate_address(int *list_item, int *input){
	if(list_item[0] == input[0] && 
	   list_item[1] == input[1] && 
	   list_item[2] == input[2] && 
	   list_item[3] == input[3]){
		printf("The address %d.%d.%d.%d is already in the list\n", input[0], input[1],
			input[2],input[3]);
	//	print_input_not_added(input);
		return 1;
	}
	return 0;
}

void print_input_not_added(struct address_t *input){
	printf("entry %d.%d.%d.%d %10s was not added to the list \n", input->octet[0], 
		input->octet[1], input->octet[2],input->octet[3], 
		input->alias);
}
