/*Nome: Arthur Barreto Godoi
  GRR: 20224377*/
  
#include "pilha.h"
#include "fila.h"


int main()
{
    struct pilha p1;
    struct fila f1;
    cria_pilha(&p1);
    push(&p1,10);
    imprime_pilha(&p1);
    push(&p1,20);
    imprime_pilha(&p1);
    push(&p1,30);
    imprime_pilha(&p1);
    push(&p1,40);
    imprime_pilha(&p1);
    push(&p1,50);
    imprime_pilha(&p1);
    push(&p1,60);
    pop(&p1);
    imprime_pilha(&p1);
    pop(&p1);
    imprime_pilha(&p1);
    pop(&p1);
    imprime_pilha(&p1);
    pop(&p1);
    imprime_pilha(&p1);
    pop(&p1);
    pop(&p1);

    cria_fila(&f1);
    enqueue(&f1,10);
    imprime_fila(&f1);
    enqueue(&f1,20);
    imprime_fila(&f1);
    enqueue(&f1,30);
    imprime_fila(&f1);
    enqueue(&f1,40);
    imprime_fila(&f1);
    enqueue(&f1,50);
    imprime_fila(&f1);
    enqueue(&f1,60);
    dequeue(&f1);
    imprime_fila(&f1);
    dequeue(&f1);
    imprime_fila(&f1);
    dequeue(&f1);
    imprime_fila(&f1);
    dequeue(&f1);
    imprime_fila(&f1);
    dequeue(&f1);
    dequeue(&f1);
    return 0;
}