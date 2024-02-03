#include <stdio.h>
#include <stdlib.h>

#define MAX 5


struct fila {
    int elementos[MAX];
    int fim;
};

/*Função que cria a fila, zerando todos os elementos e apontando
o fim para o índice -1*/
void cria_fila(struct fila *p);

/*Função que verifica se a fila está vazia, retorna 1 se está vazia
e 0 se não*/
int fila_vazia(struct fila *f);

/*Função que verifica se a fila está cheia, retorna 1 se cheia
e 0 se não*/
int fila_cheia(struct fila *f);

/*Função para impressão da fila*/
void imprime_fila(struct fila *f);

/*Função que insere elementos na fila colocando elementos
sempre no fim da fila*/
void enqueue(struct fila *f , int x);

/*Função que remove elementos da fila, sempre removendo
o ínicio primeiro*/
void dequeue(struct fila *f);