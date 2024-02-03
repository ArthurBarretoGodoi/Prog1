// Nome: Arthur Barreto Godoi //
// GRR: 20224377 //

#include "listaDupla.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
    struct listaDE *l1;
    int tamanho, valores;

    l1 = inicializaLDE();

    // Código para realizar inserção na lista e sua impressão //

    printf("Digite quantos valores quer colocar na lista: ");
    scanf("%d", &tamanho);

    printf("\n");

    printf("Digite os valores da lista: ");

    for (int i = 0 ; i < tamanho ; i++) {
        scanf("%d", &valores);
        insereOrdenado(l1,valores);
    }

    printf("\n");

    imprimeLDE(l1);
    imprimeCabeca(l1);
    imprimeCauda(l1);
    printf("O tamanho da lista é: %d\n", tamanhoLDE(l1));

    printf("\n");

    // Código para realizar a remoção e a impressão da nova lista //

    printf("Digite quantos valores quer remover da lista: ");
    scanf("%d", &tamanho);
    
    printf("\n");

    printf("Digite os valores que quer remover: ");

    for (int i = 0 ; i < tamanho ; i++) {
        scanf("%d", &valores);
        removeItem(l1,valores);
        printf("\n");
    }

    printf("\n");

    imprimeLDE(l1);
    imprimeCabeca(l1);
    imprimeCauda(l1);
    printf("O tamanho da lista é: %d\n", tamanhoLDE(l1));

    destroiLDE(l1);
    return 0;
}