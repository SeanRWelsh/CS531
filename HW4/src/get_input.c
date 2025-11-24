#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* get_input takes a file type as an argument and then reads a line from that
 * file with a max character size of 100. The new line character is removed and
 * the string is then saved into a dynamically sized character array and passed
 * back to the caller
 */

char * get_input(FILE *file){
	char buffer[100];
	if(fgets(buffer, sizeof(buffer), file)==NULL){
		return NULL;
	}

	size_t len = strlen(buffer);
	if(len > 0 && buffer[len-1] == '\n')
		buffer[strlen(buffer)-1] = '\0';
	char *out = malloc(strlen(buffer) + 1);
	if(!out) return NULL;
	strcpy(out, buffer);
	return out;
}
