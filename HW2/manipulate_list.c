#include "read_files.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct address_t *find_address(char *alias){
	struct address_t *current = head;
	while(current != NULL){
		if(is_duplicate_name(current->alias, alias) == 1) return current;
		current = current->next;
	}
	return NULL;
}

void add_to_list(char *input){
	int octet[4];
	char alias[13];
	struct address_t *tail;
	if(head == NULL){
		tail = NULL;
	}else{
		tail = head;
		while(tail->next != NULL){
			tail = tail->next;
		}
	}
	sscanf(input,"%d.%d.%d.%d %12s", &octet[0], &octet[1], &octet[2], &octet[3],
			alias);
	int len = strlen(alias)+1;
	if(len > 10){
		puts("name too long");
		return;
	}
	struct address_t *temp = (struct address_t*)malloc(sizeof(struct address_t));
	temp->octet[0] = octet[0];
	temp->octet[1] = octet[1];
	temp->octet[2] = octet[2];
	temp->octet[3] = octet[3];
	strcpy(temp->alias, alias);
	temp->next = NULL;
	if(is_valid_input(temp) == 1){
		if(tail == NULL){
			head = temp;
			tail = temp;
		}else{
			tail->next = temp;
			tail = tail->next;
		}
	}else{
		free(temp);
	}
}

void delete_list_item(struct address_t *delete){
	struct address_t *prev = NULL;
	struct address_t *current = head;

	while(strcmp(current->alias, delete->alias) != 0){
		prev=current;
		current=current->next;
	}
	if(strcmp(current->alias, head->alias) == 0){
		head = head->next;
	}else{
	prev->next = current->next;
	free(delete);
	}
}
