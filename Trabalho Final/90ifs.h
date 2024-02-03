#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


#define ATRIBUTOS_C 2
#define ATRIBUTOS_P 3


/* Struct para um candidato que contém um identificador, um dado que 
*  guardará o valor do d20 e um vetor de atributos de 2 índices */
struct pessoa_c {
    int id;
    int dado;
    int vet_atributos[ATRIBUTOS_C];
};


/* Struct para um pretendente que contém um identificador, um dado que 
*  guardará o valor do d20 e um vetor de atributos de 3 índices */
struct pessoa_p {
    int id;
    int dado;
    int vet_atributos[ATRIBUTOS_P];
};


/* Struct Candidato que contém uma pessoa do tipo candidato e um
*  ponteiro para o próximo (Será usado na pilha) */
struct candidato {
    struct pessoa_c novo_candidato;
    struct candidato *proximo;
};


/* Struct Pilha que contém um ponteiro para o topo e um inteiro para seu tamanho */
struct pilha {
    struct candidato *topo;
    int tamanho;
};


/* Struct Pretendente que contém uma pessoa do tipo pretendente e um
* ponteiro para o próximo (Será usado na lista circular) */
struct pretendente {
    struct pessoa_p novo_pretendente;
    struct pretendente *proximo;
};


/* Struct Lista Circular que contém ponteiros para cabeça e cauda, e um
*  inteiro para seu tamanho*/
struct lista_circular {
    struct pretendente *cabeca;
    struct pretendente *cauda;
    int tamanho;
};



//////////////// ESTRUTURAS DA PILHA ////////////////



/* Função que aloca memória para pilha, atribui seu tamanho para 0, atribui o topo
*  para NULL e retorna um nova pilha */
struct pilha *inicializaPilha();


/* Função que aloca memória para um candidato, recebe o id de um novo candidato,
*  preenche os atribuitos de forma aleatória com número de 0 a 2, atribui o próximo
*  para NULL e retorna o endereço do novo candidato */
struct candidato *cria_candidato(struct pessoa_c pe);


/* Função que retorna TRUE se o topo for NULL e FALSE caso contrário */
bool pilhaVazia(struct pilha *p);


/* Função que dada um pilha, insere um novo candidato chamando cria_candidato 
*  no topo da pilha, retorna 1 se foi inserido e 0 caso contrário */
int push(struct pilha *p, struct pessoa_c pe);


/* Função que dada um pilha, remove o candidato do topo e retorna 1 se
*  foi removido e 0 caso contrário */
int pop(struct pilha *p);


/* Destrói cada candidato da pilha e depois destroi a pilha */
void destroiPilha(struct pilha *p);


/* Imprime o candidato do topo da pilha e seus atributos */
void imprimeTopo(struct pilha *p);



//////////////// ESTRUTURAS DA LISTA CIRCULAR ////////////////



/* Função que aloca memória para uma lista, atribui a cabeça e cauda para NULL, 
*  atribui o tamanho para 0 e retorna uma nova lista */
struct lista_circular *inicializaLista();


/* Função que aloca memória para um pretendente, recebe o id de um novo pretendente,
*  preenche os atributos de forma aleatória com números de 0 a 2, atribui o próximo
*  para NULL e retorna o endereço do novo pretendente */
struct pretendente *cria_pretendente(struct pessoa_p pe);


/* Função que retorna TRUE se a cabeca e a cauda forem iguais a NULL e FALSE caso contrário*/
bool listaVazia(struct lista_circular *l);


/* Função que insere um novo pretendente na cabeça da lista caso ela estiver vazia */
void insereCabeca(struct lista_circular *l, struct pretendente *novo);


/* Dada uma lista, insere um novo pretendente chamando cria_pretendente no fim da lista
*  retorna 1 se foi inserido e 0 caso contrário */
int insereLista(struct lista_circular *l, struct pessoa_p pe);


/* Função que funciona assim como o insereLista, pórem não é criado um novo pretendente
*  apenas é usado aqueles que ja foram criados anteriormente */
int ReinsereLista(struct lista_circular *l, struct pessoa_p pe);


/* Função que remove o pretendente da cabeça da lista */
void removeCabeca(struct lista_circular *l);


/* Função que remove o pretendente da cauda da lista */
void removeCauda(struct lista_circular *l);


/* Dada um lista, remove o pretendente passado de qualquer lugar da lista,
*  retorna 1 se foi removido e 0 caso contrário */
int removeLista(struct lista_circular *l, struct pessoa_p pe);


/* Função que imprime os pretendentes da lista e seus atributos */
void imprimeLista (struct lista_circular *l);


/* Função que destrói cada pretendente da lista e destrói a lista, um contador de infelicidade
*  é incrementado para cada pretendente que foi removido e retorna a infelicidade */
int destroiLista(struct lista_circular *l);



//////////////// ESTRUTURAS DO MAIN ////////////////


/* Função que recebe uma pilha e um pretendente, os valores dos atributos do topo da pilha
*  e do pretendente são copiados para 2 vetores auxiliares onde é feita a interseccção, se
*  a intersecção for igual a 2 retorna TRUE e retorna FALSE caso contrário */
bool interseccoes(struct pilha *p, struct pretendente *pre);


/* Função que recebe uma pilha e um pretendente, é criado 2 acumuladores que recebem as vitórias
*  do candidato e do pretendente, o candidato e o pretendente rolam 1d20, se o valor do candidato
*  for maior ele ganha 1 vitória, se o do pretendente for maior ele ganha 1 vitória, isso é feito 
*  durante 90 turnos. Retorna TRUE se as vitórias do candidato forem maiores e FALSE caso contrário */  
bool encontro(struct pilha *p, struct pretendente *pre);