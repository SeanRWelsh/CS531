CS 531 HW1
string sorter program
Author: Sean Welsh
G#: G01568075
Date: 09/20/2025
Platform: Linux using gcc
Last modified: 09/20/2025

DESCRIPTION
	This program sorts an array of strings alphabetically. It reads strings from the user via stdin,
	stores them in an array of strings, and based on users preference prints them in ascending or
	descending order.

FILES
	main.c               -contains the main function and overal program flow
	check_string.c       -contains functions that check to ensure the user have input
	                      a legal string
	input_strings.c      -handles user input
	sort.c               -uses a quicksort algorithm to sort the strings
	character_strings.h  -Header file for shared functions and constants
	Makefile             -provides easy to use commands for building and running the project

Requirments
	GCC
	Linux environment (tested on debian and zeus)

COMPILATION
	cd into the directory containing the program files and run either of the following commands

	make build	# builds the program
	make debug	# builds the program with debugging flags

RUNNING THE PROGRAM
	in the same directory you compiled the program in run either of the following commands

	make run	#runs the program via the make file command
	./string_sorter	#directly runs the file via a bash terminal

NOTES
	For user input the max character length allowed is 25 characters. For input buffer saftey 
	I allocated 100 bytes of space to try and clean up any excess overflow with fgets. If a user
	enters more than 100 characters the program will automatically pull from the characters left in
	the stdin buffer for the next string input attempt. I looked into using 
	while(getchar() !='/n' || EOF) but this would cause the program to hang up waiting for a user to
	enter a character if the buffer was already empty. I looked into a way to peak into the buffer
	before requesting input and that required POSIX and systems calls which seemed out of scope for this
	project. This led me to stick with the design plan to just allocate extra space in the buffer at 100 bytes
	as this should be enough to cover excess characters in this scope.

	quicksort swaps the pointers to the array of strings instead of the strings in the array themselves. I read
	this is more effecient since the system does not need to rewrite strings multiple times.
