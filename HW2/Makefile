##########################################################################################
#                             Makefile for UNIX systems                                  #
#                               using a GNU C complier                                   #
#                                                                                        #
# Compiler flags:                                                                        #
#    -g            -- Enable debugging                                                   #
#    -Wall         -- Turn on all warnings                                               #
#    -Werror       -- Treat warnings as errors                                           #
#    -I$(INC_DIR)  -- Tells compiler to add a directory to the list of paths it searches #
#                     for header files during compilation                                #
#                                                                                        #
##########################################################################################

#ANSI Colors for compile/link messages:
BLACK := \033[0,30m
RED   := \033[0;31m
GREEN := \033[0;32m
YELLOW:= \033[0;33m
BLUE  := \033[0;34m
PURPLE:= \033[0,35m
CYAN  := \033[0,36m
GREY  := \033[0,37m
RESET := \033[0m
#************************************************************************************************

# Directories
SRC_DIR := src
OBJ_DIR := build_obj
INC_DIR := include
EXE_DIR := application

# Compiler and flags
CC := gcc
CCFLAGS := -Wall -Werror -g -I$(INC_DIR)

# Target executable name
TARGET := $(EXE_DIR)/IPv4_addresses

# Finad all .c files in SRC_DIR
SRCS := $(wildcard $(SRC_DIR)/*.c)

# Create matching .o paths in OBJ_DIR
# patsubst is a pattern substitution function $(patsubst patter, replacement, text)
# % is a wildcard placeholder
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

#default command
all: $(TARGET)

# Link step
# | enables order-only prerequisites if any .o file changes then $(TARGET) gets rebuilt
# but $(EXE_DIR) makes sure the directory exists before running the build but does not
# trigger a rebuild of $(TARGET) if only that directory changed
# @echo the @ suppresses the command echo so make doesnt print the command itself
# $@ is an automatic variable that expands to the name of the target currently being built
$(TARGET): $(OBJS) | $(EXE_DIR)
	@echo "$(RED)Linking..... teh source files to object files....$(RESET)"
	$(CC) $(OBJS) -o $@

# Compile each .c file into .o
# $< Automatic variable meaning "the first prerequisite
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(GREEN)Compiling $<.....$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

# Create build directories if they don't exist
# -p flag creates the entire path, including any missing parent directories.
#  No error if the directory already exists just does nothing
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(EXE_DIR):
	mkdir -p $(EXE_DIR)

run:
	$(TARGET)

clean:
	rm -rf $(OBJ_DIR)/*.o
	rm -rf *~
