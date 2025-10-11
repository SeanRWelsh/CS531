#include "read_files.h"
#include <stdio.h>
struct address_t * find_address(int octet[4]){
	struct address_t *current = head;
	while(current != NULL){
		if(is_duplicate_address(current->octet, octet) == 1) return current;
		current = current->next;
	}
	return NULL;
}
