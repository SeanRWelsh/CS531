#include "address_t.h"
#include <string.h>

void print_input_not_added(struct address_t *input, char *reason);


/* is_octet_in_range accepts an integer array. It then loops through the array and checks to make sure
 * each index in the array is between 0 and 255
 */
int is_octet_in_range(int *input){
	for(int i = 0; i < 4; i++){
		if( input[i] > 255 || input[i] < 0){
			return 1;
		}
	}
	return 0;
}

/* is_duplicate_name accepts a pointer to two character arrays. It uses the strcasecmp
 * function to compare the two character arrays. strcasecmp was used because it ignores case. 
 * If it is found that the character arrays are the same then is_duplicate_name returns 1. If the
 * character arrays are different then is_duplicate_name returns 0 */
int is_duplicate_name(char *tree_item, char *input){
	if(strcasecmp(tree_item, input) == 0){
		return 1;
	}
	return 0;
}

/* is_duplicate_address acceppts a pointer to two integer arrays. It compares the items in 
 * each array index. If each array has the same value in each index is_duplicate_address
 * returns 1. If even 1 of the 4 indexes is different in then a duplicate was not found and 
 * is_duplicate_address returns 0 */
int is_duplicate_address(struct address_t *tree_item, int *input){
	if(tree_item == NULL) return 0;
	
	if(tree_item->octet[0] == input[0] && 
	   tree_item->octet[1] == input[1] && 
	   tree_item->octet[2] == input[2] && 
	   tree_item->octet[3] == input[3]){
		return 1;
	}
	return is_duplicate_address(tree_item->left_child, input) ||
		is_duplicate_address(tree_item->right_child, input);
}

/* print_input_not_added accepts an address_t node and a character array. It uses both of
 * these to create a custom error message to be displayed
 */
void print_input_not_added(struct address_t *input, char *reason){
	printf("entry %d.%d.%d.%d %s was not added to the tree %s\n",	input->octet[0], input->octet[1],
		input->octet[2],input->octet[3], input->alias, reason);
}
