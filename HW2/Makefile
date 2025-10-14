##########################################################################################
#                             Makefile for UNIX systems                                  #
#                               using a GNU C complier                                   #
#                                                                                        #
# Compiler flags:                                                                        #
#    -g      -- Enable debugging                                                         #
#    -Wall   -- Turn on all warnings                                                     #
#    -Werror -- Treat warnings as errors                                                 #
#                                                                                        #
##########################################################################################
CC = gcc
CCFLAGS = -Wall -Werror -g
OBJ = main.o file_IO.o manipulate_list.o validate_input.o print.o get_input.o add_address.o look_up_address.o update_address.o delete_address.o aliases_for_location.o
TARGET = IPv4_addresses

#default command
all: build

# build the program without debug flags
build: $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

#build the program with debug flags
debug: $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o $(TARGET)

#runs the program
run: $(TARGET)
	./$(TARGET)

#delete build files
clean:
	rm -rf $(OBJ) $(TARGET)

#compiles and sets dependencies for the object files
main.o: main.c address_t.h
	$(CC) $(CCFLAGS) -c main.c

file_IO.o: file_IO.c address_t.h
	$(CC) $(CCFLAGS) -c file_IO.c

manipulate_list.o: manipulate_list.c address_t.h
	$(CC) $(CCFLAGS) -c manipulate_list.c

validate_input.o: validate_input.c address_t.h
	$(CC) $(CCFLAGS) -c validate_input.c

print.o: print.c address_t.h
	$(CC) $(CCFLAGS) -c print.c

get_input.o: get_input.c
	$(CC) $(CCFLAGS) -c get_input.c

add_address.o: add_address.c address_t.h
	$(CC) $(CCFLAGS) -c add_address.c

look_up_address.o: look_up_address.c address_t.h
	$(CC) $(CCFLAGS) -c look_up_address.c

update_address.o: update_address.c address_t.h
	$(CC) $(CCFLAGS) -c update_address.c

delete_address.o: delete_address.c address_t.h
	$(CC) $(CCFLAGS) -c delete_address.c

aliases_for_location.o: aliases_for_location.c address_t.h
	$(CC) $(CCFLAGS) -c aliases_for_location.c
