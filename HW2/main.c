#include <stdio.h>

int main(void){

	struct address_t{
		int octet[4];
		char alias[11];
		struct address_t *next;
	};
	struct address_t *head = NULL;
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
	return 0;
}
