# Simple generic makefile (Makefile or makefile are both found by gcc)
# Prof. Frank Emanuel (2022)

# Note that a generic makefile like this will attempt to compile
# and link ALL of the .c and .h files in the directory. This is 
# not likely what you want to do in your lab folder. Instead do 
# each lab project in its own folder and copy this makefile into 
# that folder for running. 

# Variables 
# Note: = is assign; := is expand before assigning; += is append;
# ?= is only assign if not already defined; != expands and runs the command
# shell assigning the results to the variable.

SRC := *.c 
OBJ := $(SRC:.c=.o)
BIN := output
CFLAGS += -ansi -pedantic -Wall 

# Recipes
# Recipes follow this pattern:
# target: dependencies
# <tab>recipe
# <tab>recipe...
# Note that makefiles are highly whitespace sensitive (think python)
#

$(BIN): $(OBJ)
	gcc $^ -o $(BIN)

%.o: %.c %.h
	gcc -c $^ $(CFLAGS)

clean:
	rm *.o $(BIN)
