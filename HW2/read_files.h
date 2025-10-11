#ifndef READ_FILE_H
#define READ_FILE_H
struct address_t{
	int octet[4];
	char alias[11];
	struct address_t *next;
};
extern struct address_t *head;
void read_file(void);
void display_list(struct address_t *head);
int is_valid_input(struct address_t *input);
struct address_t * find_address(int octet[4]);
int is_duplicate_address(int *list_item, int *input);
#endif
