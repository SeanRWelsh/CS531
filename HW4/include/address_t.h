#ifndef READ_FILE_H 
#define READ_FILE_H
#include <stdio.h>
struct address_t{
	int octet[4];
	char alias[11];
	struct address_t *left_child, *right_child;
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

void display_tree(struct address_t *node);
void display_tree_item(struct address_t *item);
void print_location_tree(struct address_t *node, int octet1, int octet2);

int is_valid_input(struct address_t *input);
int is_duplicate_name(char *tree_item, char *input);
int is_duplicate_address(struct address_t *tree_item, int *input);
int is_octet_in_range(int *input);
void print_input_not_added(struct address_t *input, char *reason);

struct address_t *find_address(struct address_t *node, char *alias);
void add_to_tree(char *input); 
void delete_tree_item(struct address_t *delete);
#endif
