# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Source files and object files
SRC =  memory-test.c meimory.c
OBJ = $(SRC:.c=.o)

# Target executable
TARGET = memory-test

# Makefile targets
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
