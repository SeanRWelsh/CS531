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
#endif
