#include "address_t.h"

/* loops through the linked list and prints out each node on its own line */
void display_list(){
	int count=0;
	struct address_t *current;
	current = head;

	if(head == NULL){
		puts("List is empty");
	}else{
		while(current != NULL){
			if(count == 0) printf("%-15s %-10s\n", "Address", "Alias");
			count++;
			display_list_itemf(current);
			current = current->next;
		}
	}
}

/* display_list_itemf accepts one address_t structure converts it to a string and then prints it out*/
void display_list_itemf(struct address_t *item){
	char return_string[50], ip[16];
	snprintf(ip, sizeof(ip), "%d.%d.%d.%d", item->octet[0], item->octet[1], item-> octet[2],
		 item->octet[3]);
	snprintf(return_string, sizeof(return_string), "%-15s %-10s\n", ip, item->alias);
	printf("%s", return_string);
}

/* print_location_list accepts integer octet1 and octet2. These octets are compared to the
 * first and second octet respectivaly to each node in the list. If both octet1 and octet2
 * match there respective nodes then the current node is printed otherwise it is skipped.
 * If no nodes print then a no address found message is displayed.
 */
void print_location_list(int octet1, int octet2){
	struct address_t *current = head;
	int count = 0;

	while(current != NULL){
		if(octet1 == current->octet[0] && octet2 == current->octet[1]){
			if(count == 0) printf("%-15s %-10s\n", "Address", "Alias");
			count++;
			display_list_itemf(current);
		}
		current = current->next;
	}
	if(count == 0){
		printf("No addresses found at the locality %d.%d\n", octet1, octet2);
	}
}			
