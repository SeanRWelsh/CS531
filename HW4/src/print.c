#include "address_t.h"

/* recursively loops through the tree with Inorder traversal and prints out 
	*each node on its own line */
void display_tree(struct address_t *node){
	if(node == NULL) return;
	display_tree(node->left_child);
	display_tree_item(node);
	display_tree(node->right_child);
}

/*display_tree_item accepts one address_t structure converts it to a string 
 * and then prints it out
 */
void display_tree_item(struct address_t *item){
	char return_string[50], ip[16];
	snprintf(ip, sizeof(ip), "%d.%d.%d.%d", item->octet[0], item->octet[1], 
					 item-> octet[2], item->octet[3]);

	snprintf(return_string, sizeof(return_string), "%-15s %-10s\n", ip, 
					 item->alias);

	printf("%s", return_string);
}

/* print_location_tree accepts a node and an integer octet1 and octet2. These 
 * octets are compared to the first and second octet respectivaly to each node
 * in the tree. If both octet1 and octet2 match there respective nodes then the
 * current node is printed otherwise it is skipped. If no nodes print then a no
 * address found message is displayed.
 */
void print_location_tree(struct address_t *node, int octet1, int octet2){
  if(node == NULL) return;
	
	print_location_tree(node->left_child, octet1, octet2);
	if(octet1 == node->octet[0] && octet2 == node->octet[1])
			display_tree_item(node);
	print_location_tree(node->right_child, octet1, octet2);
}			
