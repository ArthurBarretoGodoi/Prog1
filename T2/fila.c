#include "fila.h"


void cria_fila(struct fila *f)
{
    int i;
    for (i = 0 ; i < MAX ; i++)
        f->elementos[i] = 0;
    f->fim = -1;
}


int fila_vazia(struct fila *f)
{
    if (f->fim == -1)
        return 1;
    return 0;
}


int fila_cheia(struct fila *f)
{
    if (f->fim == MAX-1)
        return 1;
    return 0;
}


void imprime_fila(struct fila *f)
{
    int i;
    for (i = 0 ; i <= f->fim ; i++)
        printf("%d ", f->elementos[i]);
    printf("\n");
}


void enqueue(struct fila *f , int x)
{
    /*Se a fila não estiver cheia o fim é incrementado para
    adicionar um novo elemento*/
    if (fila_cheia(f))
        printf("A fila está cheia!\n");
    else {
        f->fim++;
        f->elementos[f->fim] = x;
    }
}


void dequeue(struct fila *f)
{
    /*Se a fila não estiver vazia os elementos da fila são
    copiados um índice para trás, removendo o primeiro elemento*/
    if (fila_vazia(f))
        printf("A fila está vazia!\n");
    else {
        for (int i = 0 ; i < f->fim ; i++)
            f->elementos[i] = f->elementos[i+1];
        f->fim--;
    }
}