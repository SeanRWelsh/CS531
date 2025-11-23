#ifndef READ_FILE_H
#define READ_FILE_H
#include <stdio.h>
struct address_t{
	int octet[4];
	char alias[11];
	struct address_t *next;
};
extern struct address_t *head;

void add_address();
void look_up_address();
void update_address();
void delete_address();
void aliases_for_location();

char * get_input(FILE *file);

void read_file(void);
void write_file(void);

void display_list();
void display_list_itemf(struct address_t *item);
void print_location_list(int octet1, int octet2);

int is_valid_input(struct address_t *input);
int is_duplicate_name(char *list_item, char *input);
int is_duplicate_address(int *list_item, int *input);
int is_octet_in_range(int *input);

struct address_t * find_address(char *alias);
void add_to_list(char *input); 
void delete_list_item(struct address_t *delete);

void my_connect();
void save_db();
void read_db();
#endif
