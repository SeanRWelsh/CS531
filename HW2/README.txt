CS 531 HW3
IPv4 address list
Author: Sean Welsh
G#: G01568075
Date: 11/04/2025
Platform: Linux using gcc
Last modified: 11/04/2025

DESCRIPTION
	This program loads a default list from a MySQL database upon opening. It then displays a list menu
	giving the user the option to add and address to the list, look up an address in the list, update an address
	in the list, delete and address from the list, display the whole list, display aliases for a location of the 
	users choosing, save the update list to the database, and finally exit the program. The default
	behavior of the program is to return to the menu after any task has been completed unless there is a database issue.
	If there is an issue with any database interaction the program prints the error and exits

FILES
	main.c                 -contains the main function and overal program flow
	add_address.c          -asks user to input information for a new address validates that information and if the input
			        is valid adds it to the list. If not valid informs the user and does not add anything
	aliases_for_location.c -gets user input for the location they would like to look into. If any computers are in that
				location prints them to the screen. Otherwise displays a message stating that no computers
				are in that location
	delete_address.c       -asks user for a list item to delete. If an item exists removes it from the list. Otherwise
				lets the user know that it could not find that item and nothing was done.
	db_IO.c	               -handles reading from the database, and generating a list from that information.
				Also handles writing the current list to the database.
	get_input.c	       -handles getting user input from whatever file is passed into it. Cleans the data and returns a string to the caller.
	look_up_address.c      -asks for a user to enter an address to look up. If address is found prints address information. If no address is found
				lets the user know that no address was found.
	manipulate_list.c      -handles adding items to the list, deleting items from the list and searching for items in the list.
	print.c                -formats list items to be printed to the screen
	update_address.c       -asks user for an alias to update the address. If an address is found asks user for a new address. If no address is found
				or the new address is invalid prints out an error report.
	validate_input.c       -functionality for testing user input before adding items to the list(duplicate name, duplicate address, address out of range)
				and displays an error message if any errors are found
	Makefile               -provides easy to use commands for building and running the project

Requirments
	GCC
	Linux environment (tested on debian and zeus)

COMPILATION
	cd into the directory containing the program files and run either of the following commands

	make     	# builds the program

RUNNING THE PROGRAM
	in the same directory you compiled the program in run either of the following commands

	make run	              #runs the program via the make file command
	./application/IPv4_addresses  #directly runs the file via a bash terminal

NOTES
	For input the max character length allowed is 100 characters. If a user
	enters more than 100 characters the program will automatically pull from the characters left in
	the stdin buffer for the next string input attempt. For the use of this program 100 characters should be plenty of buffer space.
	If a user puts in more than that will just display error messages from the leftover garbage being read.

	sscanf stops reading a string at white space so no spaces are allowed for the alias names. If you enter a alias name like "bobs comp"
	only bobs will be saved into the alias name

	If there is an error with the database the error is printed and the program exits. This choice was implemented because if an error occured
	it could result in a missaligment in what is in the database and what is in the linked list which could result in undefined behavior later if
	the program was still running. This program is a proof of concept for working with databases. In a more full fledged program you would want to
	ensure the linked list and database are insync after each add or delete to ensure correct data at all times. This would also help with database
	connection issues as you wouldnt be dropping the table and deleting data before attempting to write to the database(a process that could fail resulting
	in no longer having your old data or potential your new data as well).

