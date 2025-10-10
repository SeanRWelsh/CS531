#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_files.h"
//check duplicate functions 1st thing
int is_duplicate_address(struct address_t *list_item, struct address_t *item_to_add);
int is_duplicate_name(struct address_t *list_item, struct address_t *item_to_add);
int is_duplicate(struct address_t *to_check);

void read_file(void){
	FILE *fPtr;
	if((fPtr = fopen("CS531_Inet.txt", "r")) == NULL){
		puts("File could not be opened");
	}else{
		int octet[4];
		char alias[11];
		struct address_t *tail = (struct address_t*)malloc(sizeof(struct address_t));
		if(head ==NULL){
			tail = NULL;
		}else{
			tail = head;
			while(tail->next != NULL){
				tail = tail->next;
			}
		}
		while(!feof(fPtr)){
			if(fscanf(fPtr, "%d.%d.%d.%d %10s", &octet[0], &octet[1], &octet[2], &octet[3], alias)==5){

				struct address_t *temp = (struct address_t*)malloc(sizeof(struct address_t));
				temp->octet[0] = octet[0];
				temp->octet[1] = octet[1];
				temp->octet[2] = octet[2];
				temp->octet[3] = octet[3];
				strcpy(temp->alias, alias);
				temp->next = NULL;
				if(is_duplicate(temp) ==1){
					free(temp);
					continue;
				}

				if(tail ==NULL){
					head = temp;
					tail = temp;
				}else{
					tail->next = temp;
					tail= tail->next;
				}
				printf("%d.%d.%d.%d %10s\n", tail->octet[0], tail->octet[1], tail->octet[2],tail->octet[3], tail->alias);
			}
		}
		fclose(fPtr);
	}
}

int is_duplicate(struct address_t *to_check){
	struct address_t *current = head;
	while(current!=NULL){
		if(is_duplicate_name(to_check, current) == 1 || is_duplicate_address(to_check, current) == 1){
			return 1;
		}
		current = current->next;
	}

	return 0;
}

int is_duplicate_name(struct address_t *list_item, struct address_t *item_to_add){
	if(strcasecmp(list_item->alias, item_to_add->alias) == 0){
		printf("The name %s is already in the list\n", item_to_add->alias);
		printf("entry %d.%d.%d.%d %10s was not added to the list ", item_to_add->octet[0], item_to_add->octet[1], item_to_add->octet[2],item_to_add->octet[3], item_to_add->alias);
		return 1;
	}
	return 0;
}

int is_duplicate_address(struct address_t *list_item, struct address_t *item_to_add){
	if(list_item->octet[0] == item_to_add->octet[0] && list_item->octet[1] == item_to_add->octet[1] && list_item->octet[2] == item_to_add->octet[2] && list_item->octet[3] == item_to_add->octet[3]){
		printf("The address %d.%d.%d.%d is already in the list\n", item_to_add->octet[0], item_to_add->octet[1], item_to_add->octet[2],item_to_add->octet[3]);
		printf("entry %d.%d.%d.%d %10s was not added to the list ", item_to_add->octet[0], item_to_add->octet[1], item_to_add->octet[2],item_to_add->octet[3], item_to_add->alias);
		return 1;
	}
	return 0;
}
