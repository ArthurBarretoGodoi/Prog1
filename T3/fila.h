#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct item {
	int valor;
	struct item *proximo;
};

struct fila {
	struct item *inicio;
	struct item *fim;
	int tamanho;
};

// Recebe inteiro, aloca memoria para um item, atribui o valor e retorna o item
struct item *criaItem(int valor);

// Aloca memoria para uma fila e atribui os ponteiros inicio e fim para NULO
struct fila *inicializaFila();

// Retorna true para fila vazia e false para fila com ao menos um item
bool filaVazia(struct fila *f);

// Dada uma fila F, insere item com valor x chamando criaItem no fim da fila; 
// retorna 1 se x foi enfileirado com sucesso, 0 se x não foi enfileirado.
int enfileira(struct fila *f, int x);

// Dada uma fila F, remove elemento do inicio, caso a fila não esteja vazia; 
// retorna 1 se o elemento foi removido ou 0 se o elemento não foi removido.
int desenfileira(struct fila *f, int *dado);

// Imprime o inicio da fila
void imprimeInicioDaFila(struct fila *f);

// Imprime o fim da fila
void imprimeFimDaFila(struct fila *f);

// Retorna o tamanho da fila
int tamanhoFila(struct fila *f);

// Destroi cada item da fila (se não vazia) e destroi a fila
void destroiFila(struct fila *f);