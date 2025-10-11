#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_files.h"
//check duplicate functions 1st thing

void read_file(void){
	FILE *fPtr;
	if((fPtr = fopen("CS531_Inet.txt", "r")) == NULL){
		puts("File could not be opened");
		return;
	}
	int octet[4];
	char alias[11];
	struct address_t *tail;

	if(head == NULL){
		tail = NULL;
	}else{
		tail = head;
		while(tail->next != NULL){
			tail = tail->next;
		}
	}

	//item to look into
	//if name has a space only reads to the space or 10 characters whichever comes first
	//this could mess up reading the rest of the items in the file
	while(fscanf(fPtr, "%d.%d.%d.%d %10s", &octet[0], &octet[1], &octet[2], &octet[3],
	      alias)==5){
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
	fclose(fPtr);
}
