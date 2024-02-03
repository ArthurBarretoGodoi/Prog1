# Makefile de exemplo (Manual do GNU Make)
     
CFLAGS = -Wall -g -Werror -Wextra # flags de compilacao
LDFLAGS = -lm

CC = gcc

all: testa_fila

testa_fila: fila.o testa_fila.o
	$(CC) $(CFLAGS) -o $@ $^

fila.o: fila.c fila.h
	$(CC) $(CFLAGS) -c fila.c

testa_fila.o: testa_fila.c fila.h
	$(CC) $(CFLAGS) -c testa_fila.c

clean:
	rm -f *.o testa_fila