#include "pilha.h"


int main()
{
    struct pilha *p1;
    int dado;
    p1 = inicializaPilha();
    push(p1,10);
    imprimeTopo(p1);
    push(p1,20);
    imprimeTopo(p1);
    push(p1,30);
    imprimeTopo(p1);
    pop(p1,&dado);
    printf("Removendo: %d \n", dado);
    imprimeTopo(p1);
    pop(p1,&dado);
    printf("Removendo: %d \n", dado);
    imprimeTopo(p1);
    pop(p1,&dado);
    printf("Removendo: %d \n", dado);
    pop(p1,&dado);
    destroiPilha(p1);
}