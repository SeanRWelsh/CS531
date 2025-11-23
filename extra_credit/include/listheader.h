/*******************************************************************************************************
  Author:            S. M. Sainju
  Files:             listheader.h
  Purpose:           This file is a header file and has all the prototypes and nodes are declared.
  Date:              September 10, 2025
  Last Modified:     October 10, 2025
********************************************************************************************************/

#ifndef LISTHEADER_H
#define LISTHEADER_H
#include <stdbool.h>
#define MAX 100
#define N_MAX 20

/* This is the main node used through out the program */
struct node {
  char names[N_MAX];
  struct node * link;
};

/* This second node is used to create a new list which will have all the names and its
   number of occurence. It also sorts by the number of occurence and prints it. 
 */
struct newnode{
  char names[N_MAX];
  int data;
  struct newnode *link;
};

struct node *insert_names(struct node *);      // this is to insert names
void print_names(struct node *);               // displays the names 
void sort_names(struct node *);                // for sorting the names
void sort_data(struct newnode *);              // sort the list based on data for the newly created node
int menu();                                    // shows menu
struct node *reverse(struct node *);           // this function reverses the list
void print_names(struct node *);               // this function does a linear search on the list
void search_list(struct node *);
struct node *delete_node(struct node *, struct node *, bool *);
                                               // this function deletes a node from any position
                                               // checks the 1st or last or any nth position based on randomly
                                               // generated number as the position between the 1st and the last node
struct node *insert_anywhere(struct node *);   // if the list is created, this function will allow to insert a node
                                               // at the 1st or last or nth position based on randomly
                                               // generated number as the position between the 1st and the last node
int find_num_nodes(struct node *);             // this function is to find out how many nodes are there on the list
struct node *delete_entirelist(struct node *); // this allows to delete the entire list
void namecountdisplay(struct node *);          // this function displays all the names with its number of occurence
                                               // in sorted order.
#endif
