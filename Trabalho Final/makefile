# Makefile para o Trabalho Final

# Compiler
CC = gcc

CFLAGS = -Wall -g -Werror -Wextra # flags de compilacao
LDFLAGS = -lm

# Executable name
TARGET = TrabFinal

# Source files
SRCS = 90ifs.c main.c

# Rule to build the executable
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Clean rule to remove the executable
clean:
	rm -f $(TARGET)