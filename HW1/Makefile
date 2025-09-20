##########################################################################################
#                             Makefile for UNIX systems                                  #
#                               using a GNU C complier                                   #
#                                                                                        #
# Compiler flags:                                                                        #
#    -g      -- Enable debugging                                                         #
#    -Wall   -- Turn on all warnings                                                     #
#    -Werror --                                                                          #
#                                                                                        #
# Using @ at the start of an action tells Make not to print this action.                 #
#   So, by using @echo instead of echo , we can see the result of echo (the variable's   #
#   value being printed) but not the echo command itself.                                #
##########################################################################################

all:
	@echo "build, run, clean"
build:
	gcc 
debug:
	gcc -g -Wall -Werror main.c  check_string.c input_strings.c sort.c
run:
	./a.out
clean:
	rm -f a.out
