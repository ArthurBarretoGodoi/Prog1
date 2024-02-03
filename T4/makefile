# Makefile de exemplo (Manual do GNU Make)
     
CFLAGS = -Wall -g -Werror -Wextra # flags de compilacao
LDFLAGS = -lm


all: testa_pilha

testa_pilha: pilha.o testa_pilha.o
	$(CC) $(CFLAGS) -o $@ $^

pilha.o: pilha.c pilha.h
	$(CC) $(CFLAGS) -c pilha.c

testa_pilha.o: testa_pilha.c pilha.h
	$(CC) $(CFLAGS) -c testa_pilha.c

clean:
	rm -f *.o testa_pilha