/******************************************************************************************************************************
 Author:         S. M. Sainju
 File:           delete.c
 Functions:      delete_node(struct node *ptr, struct node *list)
                 first function deletes a node at the beginning, end or at the nth location.
                 second function basically deletes the entire list.
                 This function takes the entire list and the pointer to the first node and also the booliean
                 list_created which is true. Each and every node is compared with the string entered by the user. Once
                 matched nodes are deleted, function returns the pointer to the first node. If all the nodes are deleted from
                 the list, then list created is set to false because the list is empty.
           
                 2nd function is straight forward. It deletes the entire list and returns NULL. 
 Date:           October 1, 2025
 Last Updated:   October 10, 2025
*****************************************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listheader.h"

struct node * delete_node(struct node *ptr, struct node *list, bool *list_created){
  char *name_to_delete = (char *)malloc(sizeof(char)*10);
  struct node *prev;
  struct node *curr;

  bool first_node= true;        // set the first node as true and if this is the node to delete, once deleted
                                // set to to false and move on. deleting the first node is different from deleting
                                // any other node on the list. 
  bool name_found = false;      // Keep track of the matched name on the list
  bool name_found_once = false; // this will keep track if name is found at least once on the list
  prev = ptr;                   // to keep track of the previous node
  curr = ptr;                   // to keep track of the current node

  ptr = list;
  printf("\t\t\t\tEnter name to delete from the list: ");
  scanf("%s", name_to_delete);

  while(ptr !=NULL){
    /*find out if this is the first node to be deleted. deleting first node is different from deleting other nodes. 
      if the node to delete matches the first node, name found is set to true. if the node to delete matches the
      first node, name found is set to true. traversing pointer now points to the current node (2nd node or next node)
      we achieve this by making ptr the link part of the previous pointer since both prev and curr point to ptr.
    */
    if (first_node && strcmp(ptr->names, name_to_delete) ==0){   
      name_found = true;
      name_found_once = true;
      ptr= curr->link;                                           
      free(curr);                         // now we can delete the first node which is curr. 
      curr = NULL;
      list = ptr;                         // now make the head pointer in this case is our list point to the 2nd node of
                                          // the list which is now the first node after deleting the first node.
    } //  end of the first if               
    /****************************************************************************************************************
      This is for any other node except the first node to delete. there could be multiple listings of the same name.
      if the name matches, set name_found to true both prev and curr are pointing to ptr, the last compared node.
      if name matches, prev becomes curr and curr is moved to the next node. prev is the previous node, curr is now
      the next node.
      The else if part is skipped if the first node matches the string. 
    ******************************************************************************************************************/
    else if(strcmp(ptr->names, name_to_delete)==0){              
      name_found = true;                 // name is found
      name_found_once = true;            

      /*
	move curr to next node so we can delete the current node. Then previous node's link part connects to
	the link part of the current node which is a pointer to the subsequent node.

	Check if the link part is NULL to make sure it is not the last node. If that is the case, then
	move the traversing pointer otherwise, simply point the ptr to point to the previous node. In this case
	the 2nd last node points to the last node and then will stop. this way we can delete a node even if
	it is the last node.
       */
      curr = curr->link;                                                                                            
      prev->link = curr->link; 
      if (ptr->link != NULL) 
        ptr = curr->link;                  
      else 
        ptr = prev;         
      free(curr);           
      curr = NULL;
    }
    else{
      first_node = false;      // while traversing, if name does not match, set the first node to false, name_found to false
      name_found = false;
    }// end of the else if
    curr = ptr;                // always make curr and prev point to the traversing pointer ptr.
    prev = ptr;

    // move traversing pointer to the next node only if name_found is false otherwise our initial head pointer
    // in this case list should point to the traversing pointer (because this is the first node).
    // if the first node matches the string, the first node is deleted and ptr, the traversing pointer
    // now points to the beginning of the list which is list. If string does not match, keep moving on the list.
    
    if(!name_found)                                              
      ptr = ptr->link;                                           
    else
      if(first_node)
	ptr = list;
  } // end of first while
  if(!name_found_once)    // this tells us the string is not found on the list 
    printf("\t\t\t\t{No matching name found on the list..Nothing to delete.....}\n");
  else
    printf("\t\t\t\t{Node deleted......, Press 2 to view the list}\n");
  // set the list created to false if the list is completely empty.
  if(list == NULL)
    *list_created = false;
  
  return (list);
}
/************** This function deletes the entire list one node at a time and returns NULL *************/
struct node *delete_entirelist(struct node *ptr){
  struct node * tmp = ptr;
   while(ptr!= NULL){    // delete each node one at a time using a tmp node 
    ptr = ptr->link;
    free(tmp);
    tmp = ptr;
  }
  return NULL;
}
