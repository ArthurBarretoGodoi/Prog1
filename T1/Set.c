#include "Set.h"


bool isEmpty(struct set s)
{
	bool nulo;
    for (int i = 0 ; i < s.size ; i++)
        if (s.elements[i] == 0 || s.elements[i] == -1) 
            nulo = true;
        else {
            nulo = false;
            return nulo;
        }
    return nulo;
}


void printSet(struct set s) 
{
	if (isEmpty(s))
        printf("O conjunto é nulo!\n");
    else
    for (int i = 0 ; i < s.size ; i++)
        if (s.elements[i] >= 0)
            printf("%d " , s.elements[i]);
    printf("\n");
}


int size(struct set s) 
{
	return s.size;
}


void printUnion(struct set s1, struct set s2) 
{
	struct set uniao;
    uniao.size = s1.size + s2.size;
    int i , k;
    for (i = 0 ; i < s1.size ; i++)
        uniao.elements[i] = s1.elements[i];
    for (i = 0 ; i < s2.size ; i++) 
        uniao.elements[i+s1.size] = s2.elements[i];
    for (i = 0 ; i < uniao.size ; i++)
        for (k = i + 1 ; k < uniao.size ; k++) 
            if (uniao.elements[i] == uniao.elements[k]) 
                uniao.elements[k] = -1;
    printf("A união dos conjuntos 1 e 2 é:\n");    
    printSet(uniao);
}


void printIntersection(struct set s1, struct set s2) 
{
	struct set interseccao;
    int i , j;
    interseccao.size = s1.size;
    for (i = 0 ; i < interseccao.size ; i++)
        interseccao.elements[i] = -1;
    for (i = 0 ; i < s1.size ; i++)
        for (j = 0 ; j < s2.size ; j++)
            if (s1.elements[i] == s2.elements[j]) { 
                interseccao.elements[i] = s2.elements[j];
                s2.elements[j] = -1;
            }
    printf("A intersecção dos conjuntos 1 e 2 é:\n");
    printSet(interseccao);
}


void printDifference(struct set s1, struct set s2) 
{
	struct set diferenca;
    diferenca.size = s1.size;
    int i , j;
    for (i = 0 ; i < s1.size; i++)
        diferenca.elements[i] = s1.elements[i];
    for (i = 0 ; i < s1.size ; i++) 
        for (j = 0 ; j < s2.size ; j++)
            if (diferenca.elements[i] == s2.elements[j])
                diferenca.elements[i] = -1;
    printf("A diferença dos conjuntos 1 e 2 é:\n");
    printSet(diferenca);
}


bool isSubset(struct set s1 , struct set s2) 
{
	bool subconjunto;
    int i , j , k;
    k = 0;
    struct set aux;
    aux.size = s1.size;
    for (i = 0 ; i < aux.size ; i++)
        aux.elements[i] = -1;
    for (i = 0 ; i < s1.size ; i++)
        for (j = 0 ; j < s2.size ; j++)
            if (s1.elements[i] == s2.elements[j]) {
                aux.elements[i] = s2.elements[j];
                s2.elements[j] = -1;
            }
    for (i = 0 ; i < aux.size ; i++)
        if (aux.elements[i] != -1)
            k++;                  
    if (k == s1.size) {
        subconjunto = true;
        return subconjunto;
    }
    else {
        subconjunto = false;
        return subconjunto;
    }
}


bool isIn(struct set s, int x) 
{
	bool achou;
    int i = 0;
    for (i = 0 ; i < s.size ; i++)
        if (s.elements[i] == x) {
            achou = true;
            return achou;        
        }
    achou = false;
    return achou;
}


void printSort(struct set s) 
{
	int i , j , aux;
    for (i = 0 ; i < s.size ; i++) 
        for (j = i + 1 ; j < s.size ; j++) 
            if (s.elements[i] > s.elements[j]) {
                aux = s.elements[i];
                s.elements[i] = s.elements[j];
                s.elements[j] = aux;
            }
    printf("O conjunto 1 ordenado é: \n");
    printSet(s);
}