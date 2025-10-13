#include <stdlib.h>
#include "read_files.h"

/* read_file uses fopen to open CS531_Inet.txt and stores that file in fPtr. it then utilizes
 * get_input by passing in fPtr to read each line in the file one by one and add it to the linked list
 * after the last line is read the file is closed
 */
void read_file(void){
	FILE *fPtr;
	char *line;
	if((fPtr = fopen("CS531_Inet.txt", "r")) == NULL){
		puts("File could not be opened");
		return;
	}
	while((line = get_input(fPtr)) != NULL){
		add_to_list(line);
		free(line);
	}
	fclose(fPtr);
}

/* write_file asks the user for a filename to save the file to. it then uses fopen to open that file
 * in write mode. The linked list is then traversed node by node until the last node is reached. during
 * the traversal each node is individually processed into a string format and then written to the file
 * with fprintf. Upon writing completion the file is closed and a success message is printed to the screen
 */
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

