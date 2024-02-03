/*Nome: Arthur Barreto Godoi
  GRR: 20224377*/

#include "Set.h"


int main () {
    struct set conj1 , conj2;
    int x , y , k , valores1 , valores2;
    printf("Digite quantos valores quer colocar no conjunto 1: \n");
    scanf("%d" , &x);
    if (x <= MAXSIZE && x > 0) {
        conj1.size = x;
        printf("Digite os valores do conjunto 1: \n");
        int i = 0;
        while (i < x ) {
            scanf("%d" , &valores1);
            if (valores1 >= 0) {
                conj1.elements[i] = valores1;
                i++;
            }
            else
                printf("O número inserido não é natural. É fake natty! Digite novamente: \n");
        }
        printf("Digite quantos valores quer colocar no conjunto 2: \n");
        scanf("%d" , &y);
        if (y <= MAXSIZE && y > 0) {
            conj2.size = y;
            printf("Digite os valores do conjunto 2: \n");
            i = 0;
            while (i < y ) {
                scanf("%d" , &valores2);
                if (valores2 >= 0) {
                    conj2.elements[i] = valores2;
                    i++;
                }
                else
                    printf("O número inserido não é natural. É fake natty! Digite novamente:\n");
            }

        // COLOCAR AS FUNÇÕES AQUI

        printUnion(conj1,conj2);
        printIntersection(conj1,conj2);
        printDifference(conj1,conj2);
        printSort(conj1);

        if (isSubset(conj1,conj2))
            printf("O conjunto 1 é subconjunto de 2! \n");
        else
            printf("O conjunto 1 não é subconjunto de 2! \n");

        printf("Digite um valor natural para verificar se pertence ao conjunto 1 ou 2. Digite -1 sair \n");
        scanf ("%d" , &k);
        while (k >= 0) {
            if (isIn(conj1,k))
                printf("O valor %d pertence ao conjunto 1! \n", k);
            else
                printf("O valor %d não pertence ao conjunto 1! \n", k);
            if (isIn(conj2,k))
                printf("O valor %d pertence ao conjunto 2! \n", k);
            else
                printf("O valor %d não pertence ao conjunto 2! \n", k);
            scanf ("%d" , &k);
        }
        }
        else
            printf("Valor invalido!\n");
    }    
    else
        printf("Valor invalido!\n");
    return 0;
}