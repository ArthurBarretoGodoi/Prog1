#include <stdbool.h>

struct item {
	int valor;
	struct item *anterior;
	struct item *proximo;
};

/* Lista Duplamente Encadeada */
struct listaDE {
	struct item *cabeca;
	struct item *cauda;
	int tamanho;
};
 
struct item *criaItem(int valor);

struct listaDE *inicializaLDE();

bool listaVazia(struct listaDE *l);

int insereCabeca(struct listaDE *l, int x);

int insereCauda(struct listaDE *l, int x);

int insereOrdenado(struct listaDE *l, int x);

int removeCabeca(struct listaDE *l, int *dado);

int removeCauda(struct listaDE *l, int *dado);

int removeItem(struct listaDE *l, int valor);

void imprimeCabeca(struct listaDE *l);

void imprimeCauda(struct listaDE *l);

void imprimeLDE(struct listaDE *l);

int tamanhoLDE(struct listaDE *l);

void destroiLDE(struct listaDE *l);