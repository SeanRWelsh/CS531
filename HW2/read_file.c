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
