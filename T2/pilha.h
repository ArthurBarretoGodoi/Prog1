#include <stdio.h>
#include <stdlib.h>

#define MAX 5


struct pilha {
    int elementos[MAX];
    int topo;
};

/*Função que cria a pilha, zerando todos os elementos e 
apontando o topo para o índice -1*/
void cria_pilha(struct pilha *p);

/*Função que verifica se a pilha está vazia, retorna 1 se vazia
e 0 se não*/
int pilha_vazia(struct pilha *p);

/*Função que verifica se a pilha está cheia, retorna 1 se cheia
e 0 se não*/
int pilha_cheia(struct pilha *p);

/*Função para impressão da pilha*/
void imprime_pilha(struct pilha *p);

/*Função para inserir elementos na pilha, sempre inserindo
no topo*/
void push(struct pilha *p , int x);

/*Função para remover elementos da pilha, sempre removendo
do topo*/
void pop(struct pilha *p);