#include <stdio.h>
#include "read_files.h"
#include <stdlib.h>
#include <string.h>
void display_list(){
	struct address_t *current;
	current = head;
	if(head == NULL){
		puts("List is empty");
	}else{
		while(current != NULL){
			display_list_item(current);
			current = current->next;
		}
	}
}

void display_list_item(struct address_t *item){
	char return_string[50], ip[16];
	snprintf(ip, sizeof(ip), "%d.%d.%d.%d", item->octet[0], item->octet[1], item-> octet[2],
		 item->octet[3]);
	snprintf(return_string, sizeof(return_string), "%-15s %-10s\n", ip, item->alias);
	printf("%s", return_string);
}

void print_location_list(int octet1, int octet2){
	struct address_t *current = head;
	int count = 0;

	while(current != NULL){
		if(octet1 == current->octet[0] && octet2 == current->octet[1]){
			if(count == 0) printf("%-15s %-10s\n", "Address", "Alias");
			count++;
			display_list_item(current);
		}
		current = current->next;
	}
	if(count == 0){
		printf("No addresses found at the locality %d.%d\n", octet1, octet2);
	}
}
			
