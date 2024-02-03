#include "listaDupla.h"
#include <stdio.h>
#include <stdlib.h>


/* Função que aloca memória para uma lista, atribui os ponteiros
da cabeça e cauda para nulo e retorna a lista */
struct listaDE *inicializaLDE()
{
    struct listaDE *nova_lista;

    if (!(nova_lista = malloc(sizeof(struct listaDE))))
        return NULL;

    nova_lista->cabeca = NULL;
    nova_lista->cauda = NULL;
    nova_lista->tamanho = 0;

    return nova_lista;
}


/* Função que recebe um inteiro, aloca memória para um item, atribui os
valores de próximo e anterior para nulo e retorna o item*/
struct item *criaItem(int valor)
{
    struct item *novo_item;

    if (!(novo_item = malloc(sizeof(struct item))))
        return NULL;
    
    novo_item->anterior = NULL;
    novo_item->proximo = NULL;
    novo_item->valor = valor;

    return novo_item;
}


/* Função que retorna true se a lista estiver vazia e false 
se conter pelo menos um item */
bool listaVazia(struct listaDE *l)
{
    if ((l->cabeca == NULL && l->cauda == NULL) || (l->tamanho == 0))
        return true;

    return false;
}


/* Função que faz a inserção na cabeça da lista caso esteja vazia e retorna
1 se inseriu e 0 caso contrário */
int insereCabeca(struct listaDE *l, int x)
{
    struct item *novo = criaItem(x);

    if (novo == NULL)
        return 0;

    l->cabeca = novo;
    l->cauda = novo;
    l->tamanho++;

    return 1;
}


/* Função que faz a inserção na cauda da lista e retorna 1 se inseriu e 0
caso contrário */
int insereCauda(struct listaDE *l, int x)
{
    struct item *novo = criaItem(x);

    if (novo == NULL)
        return 0;

    l->cauda->proximo = novo;
    novo->anterior = l->cauda;
    l->cauda = novo;
    l->tamanho++;

    return 1;
}


/* Função que faz a inserção de forma ordenada na lista e retorna 1 se inseriu
e 0 caso contrário*/
int insereOrdenado(struct listaDE *l, int x)
{
    struct item *aux, *novo;

    // Insere na cabeça se a lista estiver vazia //
    if (listaVazia(l)) {
        insereCabeca(l,x);
        return 1;
    }

    // Cria um novo item e verifica se a alocação foi sucedida //
    novo = criaItem(x);

    if (novo == NULL)
        return 0;

    // Insere na cabeça quando a lista não estiver vazia //
    if (novo->valor < l->cabeca->valor) {
        novo->proximo = l->cabeca;
        l->cabeca->anterior = novo;
        l->cabeca = novo;
        l->tamanho++;
        return 1;
    }

    // Percorre a lista começando pela cabeça até achar a posição certa //
    aux = l->cabeca;

    while ((aux->proximo != NULL) && (aux->valor < novo->valor)) {
        aux = aux->proximo;
    }

    /* Se o auxiliar estiver no último elemento da lista, insere no final e cria
    o item dentro de outra função, liberando o item criado nessa */
    if (aux->proximo == NULL) {
        insereCauda(l,x);
        free(novo);
        return 1;
    }

    // Se não for nenhum dos outros casos insere no meio da lista //
    novo->proximo = aux;
    novo->anterior = aux->anterior;
    aux->anterior->proximo = novo;
    aux->anterior = novo;
    l->tamanho++;

    return 1;
}


/* Função que faz a remoção caso o elemento estiver na cabeça da lista e 
imprime o valor removido */
int removeCabeca(struct listaDE *l, int *dado)
{
    struct item *aux;

    aux = l->cabeca;
    *dado = aux->valor;
    l->cabeca = aux->proximo;
    aux->proximo->anterior = l->cabeca;
    free(aux);
    l->tamanho--;

    printf("Removendo: %d ", *dado);

    return 1;
}


/* Função que faz a remoção caso o elemento estiver na cauda da lista e 
imprime o valor removido */
int removeCauda(struct listaDE *l, int *dado)
{
    struct item *aux;

    aux = l->cauda;
    *dado =aux->valor;
    l->cauda = aux->anterior;
    l->cauda->proximo = NULL;
    free (aux);
    l->tamanho--;

    printf("Removendo: %d ", *dado);

    return 1;
}


/* Função que remove um item da lista de acordo com cada situação, retorna 1 se removeu
e 0 caso contrário */
int removeItem(struct listaDE *l, int valor)
{
    struct item *aux;

    // Se a lista não estiver vazia é realizado a remoção //
    if (!listaVazia(l)) {

        // Se o valor estiver na cabeça e a lista tiver apenas 1 elemento //
        if ((l->cabeca->valor == valor) && (l->tamanho == 1)) {
            aux = l->cabeca;
            l->cabeca = NULL;
            l->cauda = NULL;
            l->tamanho--;
            free (aux);
            
            printf("Removendo: %d ", valor);

            return 1;
        }

        // Se o valor estiver na cabeça remove da cabeça //
        if (l->cabeca->valor == valor) {
            removeCabeca(l,&valor);
            return 1;
        }

        // Se o valor estiver na cauda remove da cauda //
        if (l->cauda->valor == valor) {
            removeCauda(l,&valor);
            return 1;
        }

        // Se não estiver na cabeça e nem na cauda, é procurado o valor no meio //
        aux = l->cabeca->proximo;

        while ((aux->proximo != NULL) && (aux->valor != valor)) 
            aux = aux->proximo;
        
        // Se o valor não tiver na lista retorna 0 //
        if (aux->proximo == NULL) {
            printf("O valor não está na lista\n");
            return 0;
        }

        // Aqui é feita a remoção no meio da lista //
        aux->anterior->proximo = aux->proximo;
        aux->proximo->anterior = aux->anterior;
        free(aux);
        l->tamanho--;

        printf("Removendo: %d ", valor);

        return 1;
    }
    return 0;
}


/* Função que imprime a cabeça da lista */
void imprimeCabeca(struct listaDE *l)
{
    if (listaVazia(l))
        printf("A lista não tem início\n");
    else
        printf("O início da lista é: %d\n", l->cabeca->valor);
}


/* Função que imprime a cauda da lista */
void imprimeCauda(struct listaDE *l)
{
    if (listaVazia(l))
        printf("A lista não tem final\n");
    else
        printf("O final da lista é: %d\n", l->cauda->valor);
}


/* Função que imprime a lista completa */
void imprimeLDE(struct listaDE *l)
{
    struct item *aux;

    if (listaVazia(l))
        printf("A lista não tem elementos\n");
    
    else {
        aux = l->cabeca;
        printf("A lista completa é: ");

        while (aux != NULL) {
            printf("%d ", aux->valor);
            aux = aux->proximo;
        }
        printf("\n");
    }
}


/* Função que retorna o tamanho da lista */
int tamanhoLDE(struct listaDE *l)
{
    return l->tamanho;
}


/* Função que destrói a lista, removendo todos os seus itens alocados */
void destroiLDE(struct listaDE *l)
{
    struct item *aux;

    while (l->cabeca != NULL) {
        aux = l->cabeca;
        l->cabeca = aux->proximo;
        free(aux);
    }
    free(l);
}