#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read_files.h"


struct address_t *head = NULL;
int main(void){
	char *user_input;
	int selection;

	/*	struct address_t *head = (struct address_t*)malloc(sizeof(struct address_t));
		head-> next = NULL;*/

	read_file();

	while(1){
		puts("***********************************");
		printf("* %19s %13s\n", "Menu","*");
		printf("%s %18s\n", "* 1) Add address","*");
		printf("%s %14s\n","* 2) Look up address","*");
		printf("%s %15s\n","* 3) Update address","*");
		printf("%s %15s\n","* 4) Delete address","*");
		printf("%s %17s\n","* 5) Display list","*");
		printf("%s %1s\n","* 6) Display aliases for location","*");
		printf("%s %17s\n","* 7) Save to file","*");
		printf("%s %25s\n","* 8) Quit","*");
		puts("***********************************");

		user_input = get_input(stdin);
		if((sscanf(user_input, "%d", &selection)) != 1 || selection < 1 || selection > 8){
			puts("\n\nincorrect input please try again\n\n");
		}else{
			switch(selection){
				case 1:
					printf("%d", selection);
					break;
				case 2:
					int address[4];
					scanf("%d.%d.%d.%d", &address[0], &address[1], &address[2], 
					       &address[3]);
					struct address_t *current = NULL;
					//causes segmentation fault
					current = find_address(address);
					if(current == NULL){
						puts("not address found");
					}else{
						display_list_item(current);
					}

					break;
				case 3:
					printf("%d", selection);
					break;
				case 4:
					printf("%d", selection);
					break;
				case 5:
					display_list(head);
					break;
				case 6:
					printf("%d", selection);
					break;
				case 7:
					printf("%d", selection);
					break;
				case 8:
					printf("%d", selection);
					puts("thank you for using the program");
					exit(0);	

			}
		}
	}
	free(user_input);
	printf("%d\n", selection);
	return 0;
}
