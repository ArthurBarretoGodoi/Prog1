# Makefile de exemplo (Manual do GNU Make)
     
CFLAGS = -Wall -g -Werror -Wextra # flags de compilacao
LDFLAGS = -lm

CC = gcc

all: mainPilhaFila

mainPilhaFila: pilha.o fila.o main.o
	$(CC) $(CFLAGS) -o mainPilhaFila pilha.o fila.o main.o

pilha.o: pilha.c pilha.h
	$(CC) $(CFLAGS) -c pilha.c

fila.o: fila.c fila.h
	$(CC) $(CFLAGS) -c fila.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f mainPilhaFila *.o