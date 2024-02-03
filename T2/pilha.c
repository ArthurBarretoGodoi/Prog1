#include "pilha.h"


void cria_pilha(struct pilha *p)
{
    int i;
    for (i = 0 ; i < MAX ; i++)
        p->elementos[i] = 0;
    p->topo = -1;
}


int pilha_vazia(struct pilha *p)
{
    if (p->topo == -1)
        return 1;
    return 0;
}


int pilha_cheia(struct pilha *p)
{
    if (p->topo == MAX-1)
        return 1;
    return 0;
}


void imprime_pilha(struct pilha *p)
{
    int i;
    for (i = 0 ; i <= p->topo ; i++)
        printf("%d ", p->elementos[i]);
    printf("\n");
}


void push(struct pilha *p , int x)
{
    /*Se a pilha não estiver cheia o índice do topo é
    incrementado e o novo elemento é inserido neste índice*/
    if (pilha_cheia(p))
        printf("A pilha está cheia!\n");
    else {
        p->topo++;
        p->elementos[p->topo] = x;
    }
}


void pop(struct pilha *p)
{
    /*Se a pilha não estiver vazia o topo é decrementado
    removendo o elemento*/
    if (pilha_vazia(p))
        printf("A pilha está vazia!\n");
    else 
        p->topo--;
}