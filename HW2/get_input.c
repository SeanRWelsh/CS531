#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char * get_input(FILE *file){
	char buffer[100];
	if(fgets(buffer, sizeof(buffer), file)==NULL){
		return NULL;
	}

	buffer[strlen(buffer)-1] = '\0';
	char *out = malloc(strlen(buffer) + 1);
	if(!out) return NULL;
	strcpy(out, buffer);
	return out;
}
