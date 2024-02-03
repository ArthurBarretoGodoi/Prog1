#include "fila.h"


struct item *criaItem(int valor)
{
    struct item *novo_item;
    if (!(novo_item = malloc(sizeof(struct item))))
        return NULL;
    novo_item->valor = valor;
    novo_item->proximo = NULL;
    return novo_item;
}


struct fila *inicializaFila()
{
    struct fila *nova_fila;
    if (!(nova_fila = malloc(sizeof(struct fila))))
        return NULL;
    nova_fila->inicio = NULL;
    nova_fila->fim = NULL;
    nova_fila->tamanho = 0;
    return nova_fila;
}


bool filaVazia(struct fila *f)
{
    if (f->inicio == NULL && f->fim == NULL)
        return true;
    return false;
}


int enfileira(struct fila *f, int x)
{
    struct item *novo = criaItem(x);

    if (novo == NULL)
        return 0;

    if (filaVazia(f)) {
        f->inicio = novo;
        f->fim = novo;
        f->tamanho++;
    }
    else {
    /* Nesta linha está seguindo a política FIFO, inserindo sempre no FIM se
    a fila estiver 1 ou mais elementos*/
    f->fim->proximo = novo;
    f->fim = novo;
    f->tamanho++;
    }
    return 1;
}


int desenfileira(struct fila *f, int *dado)
{
    struct item *aux;
    /* Se a fila estiver vazia ou seu tamanho for 0 nada é removido*/
    if (filaVazia(f) || f->tamanho == 0) {
        printf("Fila está vazia\n");
        return 0;
    }
    /* Aqui é criado um auxiliar para receber o endereço do início
    enquanto o início recebe seu pŕoximo, liberando o aux (que seria o novo início)*/
    aux = f->inicio;
    *dado = aux->valor;
    f->inicio = aux->proximo;
    free(aux);
    f->tamanho--;
    return 1;
}


void imprimeInicioDaFila(struct fila *f)
{
    printf("Imprimindo o início da fila: %d \n", f->inicio->valor);
}


void imprimeFimDaFila(struct fila *f)
{
    printf("Imprimindo o Fim da fila: %d \n", f->fim->valor);
}


int tamanhoFila(struct fila *f)
{
    return f->tamanho;
}


void destroiFila(struct fila *f)
{
    while (f->inicio != NULL)
    {
        struct item *aux = f->inicio;
        f->inicio = aux->proximo;
        free(aux);
    }
    free(f);
}