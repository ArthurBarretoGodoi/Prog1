/*Nome: Arthur Barreto Godoi
  GRR: 20224377*/
 
#include "fila.h"

int main()
{
    struct fila *f1;
    int dado;
    f1 = inicializaFila();
    enfileira(f1,10);
    imprimeInicioDaFila(f1);
    imprimeFimDaFila(f1);
    enfileira(f1,20);
    imprimeInicioDaFila(f1);
    imprimeFimDaFila(f1);
    enfileira(f1,30);
    imprimeInicioDaFila(f1);
    imprimeFimDaFila(f1);
    desenfileira(f1,&dado);
    printf("Removendo: %d \n", dado);
    imprimeInicioDaFila(f1);
    imprimeFimDaFila(f1);
    desenfileira(f1,&dado);
    printf("Removendo: %d \n", dado);
    imprimeInicioDaFila(f1);
    imprimeFimDaFila(f1);
    desenfileira(f1,&dado);
    printf("Removendo: %d \n", dado);
    desenfileira(f1,&dado);
    destroiFila(f1);
}