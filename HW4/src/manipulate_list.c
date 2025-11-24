#include "address_t.h"
#include <stdlib.h>
#include <string.h>

/* find_address accepts a node and a character array. It then recursively
 * loops through the tree and compares each nodes alias to the character array
 * passed into find_address. If a match is found find_address returns the 
 * matching node. If a match is not found find_address returns NULL
 */
struct address_t *find_address(struct address_t *node, char *alias){
	if(node == NULL) return NULL;
	int cmp =strcasecmp(node->alias, alias);
	if(cmp == 0) return node;

	if(cmp > 0){
		return find_address(node->left_child, alias);
	}else{
		return find_address(node->right_child, alias);
	}
}

/* add_to_tree accepts a character array of data to be added to the  
 * tree. It utilizes sscanf to parse the string and convert and allocate the 
 * data to its appropriate fields. It then creates a temporary address_t node 
 * and validates the data in the node. If all the data is valid it adds the 
 * node to the tree. If even one field is invalid it discards the node and 
 * informs the user that the node was not added to the tree
 */
void add_to_tree(char *input){
	int octet[4];
	char alias[13];

	//reads input and assigns to appropriate variables. if the syntax is incorrect
	//it prints an error and exits the function
	if(sscanf(input,"%d.%d.%d.%d %12s", &octet[0], &octet[1], &octet[2], &octet[3],
						alias) != 5){
		puts("invalid syntax. Nothing was added to the tree please try again");
		return;
	}

	//if the name is too long let the user know and return to caller
	int len = strlen(alias)+1;
	if(len > 10){
		puts("name too long");
		return;
	}

	//if any octet is out of range let the user know and return to caller
		if(is_octet_in_range(octet) ==1){
			char * reason = "octet out of range must be between 0 and 255";
			printf("entry %d.%d.%d.%d %s was not added to the tree %s\n", octet[0],
						 octet[1], octet[2], octet[3], alias, reason);
			return;
		}
	
//generate the node to be inserted into the tree
	struct address_t *temp = (struct address_t*)malloc(sizeof(struct address_t));
	temp->octet[0] = octet[0];
	temp->octet[1] = octet[1];
	temp->octet[2] = octet[2];
	temp->octet[3] = octet[3];
	strcpy(temp->alias, alias);
	temp->left_child = NULL;
	temp->right_child = NULL;
	
	//If there is a duplicate address inform the user and return to caller
	 if(is_duplicate_address(head, octet)){
		 char * reason = "the address is already in the tree";
     printf("entry %d.%d.%d.%d %s was not added to the tree %s\n", octet[0],
						 octet[1], octet[2], octet[3], alias, reason);
		 free(temp);
		 return;
	 }
   
	 //if tree is empty add node to head
	 if(head == NULL){
		 head = temp;
		 return;
	 }

	struct address_t *curr_node = head;
	struct address_t *prev_node = NULL;

	//traverse the tree untill a leaf node is found
	while(curr_node != NULL){
		int cmp = strcasecmp(curr_node->alias, alias); 

		//if a node with the same alias if found alert user and return to caller
		if(cmp == 0){
			char * reason = "the alias is already in the tree";
			printf("entry %d.%d.%d.%d %s was not added to the tree %s\n", octet[0],
						 octet[1], octet[2], octet[3], alias, reason);
			free(temp);
			return;
		}

		prev_node = curr_node;
		//if new alias < current node alias move to the left child node
		if(cmp >0){
			curr_node = curr_node->left_child;
			//if child node is null insert new node
			if(curr_node == NULL){
				prev_node->left_child = temp;
			}
			//if new alia > current node alias move to the right child node
		}else{
			curr_node = curr_node->right_child;
			//if child node is null insert new node
			if(curr_node == NULL){
				prev_node->right_child = temp;
			}
		}
	}
}

/* delete_tree_item accepts a address_t node. It then loops through the  tree
 * to find a node with a matching alias. Once the node is found in the tree the
 * previous nodes next value is set to point to the node to deletes left or
 * right child depending on the state of node to deletes children. Once that is
 * done the node to delete is freed.
 */
void delete_tree_item(struct address_t *delete){
	struct address_t *curr_node = head;
	struct address_t *prev_node = NULL;;
	enum Move { LEFT, RIGHT, NONE };
	enum Move last_move = NONE;
	
	//loops through the tree until the desired node is found
	while(curr_node != NULL){
		int cmp = strcasecmp(curr_node->alias, delete->alias);

		//node found break out of loop
		if(cmp ==0) break;

		prev_node = curr_node;
		//current node alias is greater than the node to finds alias move to left 
		//child node
		if(cmp > 0){
			curr_node = curr_node->left_child;
			last_move = LEFT;
		//current node alias is less than the node to finds alias move to the 
		//right child node
		}else{
			curr_node = curr_node->right_child;
			last_move = RIGHT;
		}
	}

	//node not found
	if(curr_node == NULL) return;

	//node to delete is a Leaf Node
	if(curr_node->left_child == NULL && curr_node->right_child == NULL){
		//node to delete is head node delete head
		if(last_move == NONE){
			head = NULL;
			//node to delete is a leaf so remove pointer from parant
		}else if(last_move == LEFT){
			prev_node->left_child = NULL;
		}else{
			prev_node->right_child = NULL;
		}
		//node to delete is has one child right only
		}else if(curr_node->left_child == NULL){
			//node to delete is the head update head to the right child of current
			//head
			if(last_move == NONE){
				head = curr_node->right_child;
			// node to delete is the left child of the parent node. Update parents
			// left child pointer to point to the right child of the node to delete
			}else if(last_move == LEFT){
				prev_node->left_child = curr_node->right_child;
			//node to delete is the right child of the parent node. Update parents
			//right child pointer to point to the right child of the node to delete
			}else{
				prev_node->right_child = curr_node->right_child;
			}
    //node to delete is has one child left only
		}else if(curr_node->right_child == NULL){
			//node to delete is the head update the head to be the left child of the
			//node to delete
			if(last_move == NONE){
				head = curr_node->left_child;
			//node to delete is the left child of the parent node. Update parents
			//left child node to point to the left child of the node to delete
			}else if(last_move == LEFT){
				prev_node->left_child = curr_node->left_child;
			//node to delete is the right child of the parent node. Update parents
			//right child node to point to the left child of the node to delete
			}else{
				prev_node->right_child = curr_node->left_child;
			}
		//node to delete has two child nodes
		}else{
			struct address_t *child_pointer = curr_node->right_child;
			//get the left most leaf node of the node to deletes right child
			while(child_pointer->left_child != NULL)
				child_pointer = child_pointer->left_child;
			//set the right child of the node to deletes left most leaf node to point
			//to the node to deletes left child
			child_pointer->left_child = curr_node->left_child;
			//node to delete is the head. update the head to the heads right child
			if(last_move == NONE){
				head = curr_node->right_child;
			//node to delet was a parents left child. set parents left child to the
			//node to deletes right child
			}else	if(last_move == LEFT){
				prev_node->left_child = curr_node->right_child;
			//node to delete was the parents right child. Set the parents right child
			//to the node to deletes right child
			}else{
				prev_node->right_child = curr_node->right_child;
			}
		}
	free(curr_node);
}
