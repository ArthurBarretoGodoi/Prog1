# Makefile de exemplo (Manual do GNU Make)
     
CFLAGS = -Wall -g -Werror -Wextra # flags de compilacao
LDFLAGS = -lm

CC = gcc

# arquivos-objeto
	objects = mainSet.o Set.o 
     
all: mainSet.o Set.o
	$(CC) -o mainSet mainSet.c Set.c $(LDFLAGS)

Set.o: Set.c
	$(CC) -c $(CFLAGS) Set.c

mainSet.o: mainSet.c
	$(CC) -c $(CFLAGS) mainSet.c

clean:
	rm -f $(objects) mainSet