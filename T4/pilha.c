#include "pilha.h"


struct item *criaItem(int valor)
{
    struct item *novo_item;
    if (!(novo_item = malloc(sizeof(struct item))))
        return NULL;
    novo_item->proximo = NULL;
    novo_item->valor = valor;
    return novo_item;
}


struct pilha *inicializaPilha()
{
    struct pilha *nova_pilha;
    if (!(nova_pilha = malloc(sizeof(struct pilha))))
        return NULL;
    nova_pilha->tamanho = 0;
    nova_pilha->topo = NULL;
    return nova_pilha;
}


bool pilhaVazia(struct pilha *p)
{
    if (p->topo == NULL)
        return true;
    return false;
}


int push(struct pilha *p, int x)
{
    struct item *novo = criaItem(x);

    if (novo == NULL)
        return 0;
    /*Aqui a inserção de um novo elemento é sempre no topo seguindo
    a política LIFO, não é necessário verificar se está vazia para inserir*/
    novo->proximo = p->topo;
    p->topo = novo; 
    p->tamanho++;
    return 1;
}


int pop(struct pilha *p, int *dado)
{
    struct item *aux;

    if (pilhaVazia(p) || p->tamanho == 0) {
        printf("A pilha está vazia!\n");
        return 0;
    }
    /* Aqui o auxiliar recebe o endereço do topo, enquanto o novo topo recebe seu próximo,
    no fim liberando o auxiliar.*/
    aux = p->topo;
    p->topo = aux->proximo;
    *dado = aux->valor;
    p->tamanho--;
    free(aux);
    return 1;
}


void imprimeTopo(struct pilha *p)
{
    printf("O topo é: %d \n", p->topo->valor);
}


int tamanhoPilha(struct pilha *p)
{
    return p->tamanho;
}


void destroiPilha(struct pilha *p)
{
    while (p->topo != NULL)
    {
        struct item *aux = p->topo;
        p->topo = aux->proximo;
        free(aux);
    }
    free(p);
}