# Makefile de exemplo (Manual do GNU Make)
     
CFLAGS = -Wall -g -Werror -Wextra # flags de compilacao
LDFLAGS = -lm

CC = gcc
TARGET = mainLista

$(TARGET): listaDupla.c main.c
	$(CC) $(CFLAGS) -o $(TARGET) listaDupla.c main.c

clean:
	rm -f $(TARGET)