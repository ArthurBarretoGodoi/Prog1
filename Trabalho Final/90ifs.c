#include "90ifs.h"


//////////////// ESTRUTURAS DA PILHA ////////////////


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


struct candidato *cria_candidato(struct pessoa_c pe)
{
    struct candidato *novo;
    
    if (!(novo = malloc(sizeof(struct candidato))))
        return NULL;

    novo->novo_candidato.id = pe.id;
    
    for (int i = 0 ; i < ATRIBUTOS_C ; i++) 
        novo->novo_candidato.vet_atributos[i] = rand() % 3;
    
    novo->proximo = NULL;

    return novo;
}


int push(struct pilha *p, struct pessoa_c pe)
{
    struct candidato *novo = cria_candidato(pe);

    if (novo == NULL)
        return 0;

    novo->proximo = p->topo;
    p->topo = novo; 
    p->tamanho++;

    return 1;
}


int pop(struct pilha *p)
{
    struct candidato *aux;

    if (pilhaVazia(p) || p->tamanho == 0) {
        printf("A pilha está vazia!\n");
        return 0;
    }

    aux = p->topo;
    p->topo = aux->proximo;
    p->tamanho--;
    free(aux);

    return 1;
}


void destroiPilha(struct pilha *p)
{
    while (p->topo != NULL) {
        struct candidato *aux = p->topo;
        p->topo = aux->proximo;
        free(aux);
    }
    free(p);
}


void imprimeTopo(struct pilha *p)
{
    if (pilhaVazia(p))
        printf("A pilha está vazia!\n");

    else {
        printf("Candidato %d: ", p->topo->novo_candidato.id);

        for (int i = 0 ; i < ATRIBUTOS_C ; i++) 
            printf("%d " , p->topo->novo_candidato.vet_atributos[i]);

        printf("\n\n");
    }
}


//////////////// ESTRUTURAS DA LISTA CIRCULAR ////////////////


struct lista_circular *inicializaLista()
{
    struct lista_circular *nova_lista;

    if (!(nova_lista = malloc(sizeof(struct lista_circular))))
        return NULL;
    
    nova_lista->cabeca = NULL;
    nova_lista->cauda = NULL;
    nova_lista->tamanho = 0;

    return nova_lista;
}


struct pretendente *cria_pretendente(struct pessoa_p pe)
{
    struct pretendente *novo;

    if (!(novo = malloc(sizeof(struct pretendente))))
        return NULL;
    
    novo->novo_pretendente.id = pe.id;

    for (int i = 0 ; i < ATRIBUTOS_P ; i++)
        novo->novo_pretendente.vet_atributos[i] = rand() % 3;

    novo->proximo = NULL;

    return novo;
}


bool listaVazia(struct lista_circular *l)
{
    if ((l->cabeca == NULL && l->cauda == NULL) || (l->tamanho == 0))
        return true;

    return false;
}


void insereCabeca(struct lista_circular *l, struct pretendente *novo)
{
    l->cabeca = novo;
    l->cauda = novo;
    novo->proximo = l->cabeca;
    l->tamanho++;
}


int insereLista(struct lista_circular *l, struct pessoa_p pe)
{
    struct pretendente *novo = cria_pretendente(pe);

    if (novo == NULL)
        return 0;
    
    /* Se a lista estiver vazia a inserção é feita na cabeça */
    if (listaVazia(l)) {
        insereCabeca(l,novo);
        return 1;
    }

    /* Se não estiver vazia a inserção é feita na cauda */
    l->cauda->proximo = novo;
    l->cauda = novo;
    novo->proximo = l->cabeca;
    l->tamanho++;

    return 1;
}


int ReinsereLista(struct lista_circular *l, struct pessoa_p pe)
{       
    struct pretendente *aux;

    aux = malloc(sizeof(struct pretendente));

    aux->novo_pretendente = pe;

    if (listaVazia(l)) {
        insereCabeca(l,aux);
        return 1;
    }

    l->cauda->proximo = aux;
    l->cauda = aux;
    aux->proximo = l->cabeca;
    l->tamanho++;

    return 1;
} 


void removeCabeca(struct lista_circular *l) 
{
    struct pretendente *aux;

    aux = l->cabeca;
    l->cabeca = aux->proximo;
    l->cauda->proximo = aux->proximo;
    l->tamanho--;
    free(aux);
}


void removeCauda(struct lista_circular *l)
{
    struct pretendente *aux, *aux2;

    aux = l->cabeca;

    while (aux->proximo != l->cauda)
        aux = aux->proximo;
    
    aux2 = aux->proximo;
    l->cauda = aux;
    aux->proximo = l->cabeca;
    l->tamanho--;
    free(aux2);
}


int removeLista(struct lista_circular *l, struct pessoa_p pe)
{
    struct pretendente *aux, *aux2;

    /* Se a lista esiver vazia não é feita remoção */
    if (listaVazia(l) || l->tamanho == 0) {
        printf("A lista está vazia\n");
        return 0;
    }

    /* Se o elemento estiver na cabeça, é removido chamando a 
    *  função removeCabeca */
    if (l->cabeca->novo_pretendente.id == pe.id) {
        removeCabeca(l);
        return 1;
    }

    /* Se o elemento estiver na cauda, é removido chamando a 
    *  função removeCauda */
    if (l->cauda->novo_pretendente.id == pe.id) {
        removeCauda(l);
        return 1;
    }

    /* Se não for nenhum dos casos o elemento é procurado no meio da lista
    *  e removido */
    aux = l->cabeca;
    aux2 = aux->proximo;

    while (aux2->novo_pretendente.id != pe.id) {
        aux2 = aux2->proximo;
        aux = aux->proximo;
    }
    
    aux->proximo = aux2->proximo;
    l->tamanho--;
    free(aux2);

    return 1;
}


void imprimeLista(struct lista_circular *l)
{
    struct pretendente *aux;

    if (listaVazia(l))
        printf("A lista não tem elementos\n");

    else {

        aux = l->cabeca;

        do {

            printf("Pretendente %d: ", aux->novo_pretendente.id);

            for (int i = 0; i < ATRIBUTOS_P; i++)
                printf("%d ", aux->novo_pretendente.vet_atributos[i]);

            printf("\n");
            aux = aux->proximo;

        } while (aux != l->cabeca);

        printf("\n");
    }
}


int destroiLista(struct lista_circular *l)
{
    struct pretendente *atual, *proximo;

    int infelicidade = 0;

    if (listaVazia(l))
        free(l);
    
    else {

        atual = l->cabeca;
        l->cauda->proximo = NULL;

        while (atual != NULL) {
            infelicidade++;
            proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
        free(l);
    }
    return infelicidade;
}



//////////////// ESTRUTURAS DO MAIN ////////////////



bool interseccoes(struct pilha *p , struct pretendente *pre)
{
    struct pessoa_c aux;
    struct pessoa_p aux2;
    int interseccoes = 0;

    /* Aqui é feita a cópia dos atributos do candidato do topo para um vetor auxiliar */
    for (int i = 0 ; i < ATRIBUTOS_C ; i++)
        aux.vet_atributos[i] = p->topo->novo_candidato.vet_atributos[i];
    
    /* Aqui é feita a cópia dos atributos do pretendente para um segundo vetor auxiliar*/
    for (int i = 0 ; i < ATRIBUTOS_P; i++)
        aux2.vet_atributos[i] = pre->novo_pretendente.vet_atributos[i];
    
    /* Aqui é feita a intersecção dos atributos, como estão em auxiliares é possível mudar
    *  seus valores sem alterar os atributos dos originais em si, facilitando o algoritmo de
    *  intersecção */
    for (int i = 0 ; i < ATRIBUTOS_C ; i++) {
        for (int j = 0 ; j < ATRIBUTOS_P; j++) {
            if (aux.vet_atributos[i] == aux2.vet_atributos[j]) {
                interseccoes++;
                aux.vet_atributos[i] = -1;
                aux2.vet_atributos[j] = -2;
            }
        }
    }
    
    if (interseccoes == 2)
        return true;

    return false;
}


bool encontro(struct pilha *p, struct pretendente *pre)
{
    int vitorias_c = 0;
    int vitorias_p = 0;

    /* Durante 90 turnos o candidato e o pretendente rolam d20s e acumulam
    *  vitórias*/
    for (int i = 0 ; i < 90 ; i++) {

        p->topo->novo_candidato.dado = rand() % 21;
        pre->novo_pretendente.dado = rand() % 21;

        if (p->topo->novo_candidato.dado > pre->novo_pretendente.dado)
            vitorias_c++;
            
        if (p->topo->novo_candidato.dado < pre->novo_pretendente.dado)
            vitorias_p++;
    }

    printf("O candidato %d conseguiu %d vitórias!\n", p->topo->novo_candidato.id, vitorias_c);
    printf("O concorrente %d conseguiu %d vitórias!\n", pre->novo_pretendente.id, vitorias_p);

    if (vitorias_c > vitorias_p)
        return true;

    return false;
}