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
CFLAGS = -Wall -Werror -g
OBJ = main.o check_string.o input_strings.o sort.o
TARGET = string_sorter

#default command
all: build

# build the program without debug flags
build: $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# build the program with debug flags
debug: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

#runs the program
run: $(TARGET)
	./$(TARGET)

#delete build files
clean:
	rm -rf $(OBJ) $(TARGET)

#compiles and sets dependencies for the object files
main.o: main.c character_strings.h
	$(CC) -c main.c

check_string.o: check_string.c character_strings.h
	$(CC) -c check_string.c

input_strings.o: input_strings.c character_strings.h
	$(CC) -c input_strings.c

sort.o: sort.c character_strings.h
	$(CC) -c sort.c
