#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_files.h"

void read_file(void){
	FILE *fPtr;
	char *line;
	if((fPtr = fopen("CS531_Inet.txt", "r")) == NULL){
		puts("File could not be opened");
		return;
	}
	while((line = get_input(fPtr)) != NULL){
		add_to_list(line);
	}
	fclose(fPtr);
}

void write_file(void){
	FILE *fPtr;
	char *filename;

	puts("please enter the file name you would like to save to");
	filename = get_input(stdin);
	if((fPtr = fopen(filename, "w")) == NULL){
		puts("File could not be opened");
		return;
	}
	struct address_t *current = head;
	while(current != NULL){
		char write[50], ip[16];
		snprintf(ip, sizeof(ip), "%d.%d.%d.%d", current->octet[0], current->octet[1],
				current->octet[2], current->octet[3]);
		snprintf(write, sizeof(write), "%s %s\n", ip, current->alias);

		fprintf(fPtr, write);
		current = current->next;
	}
	printf("successfully wrote to %s\n", filename);
	free(filename);
	fclose(fPtr);
}

