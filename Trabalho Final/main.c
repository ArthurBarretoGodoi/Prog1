/* Nome: Arthur Barreto Godoi 
*  GRR: 20224377*/

/* Nome: Vinicius Eduardo Batista
*  GRR: 20206187 */

#include "90ifs.h"


int main()
{
    srand(time(NULL));

    struct pilha *pilha_candidatos;
    struct lista_circular *lista_pretendentes;
    struct pessoa_c candidatos;
    struct pessoa_p pretendentes;
    struct pretendente *aux, *aux2;
    int numero_cand, numero_pret, concorrentes, infelicidade, match, mismatch;

    infelicidade = 0;
    match = 0;
    mismatch = 0;


    pilha_candidatos = inicializaPilha();
    lista_pretendentes = inicializaLista();


    /* Aqui é feita a leitura dos candidatos e em seguida
    *  colocados em uma pilha de candidatos*/

    printf("Digite quantos candidatos quer colocar: ");
    scanf("%d", &numero_cand);
    

    for (int i = numero_cand ; i >= 1 ; i--) {
        candidatos.id = i;
        push(pilha_candidatos, candidatos);
    }


    /* Aqui é feita a leitura dos pretendentes e em seguida
    *  colocados em uma lista de pretendentes */
    printf("Digite quantos pretendentes quer colocar: ");
    scanf("%d" , &numero_pret);


    for (int i = 1 ; i <= numero_pret ; i++) {
        pretendentes.id = i;
        insereLista(lista_pretendentes, pretendentes);
    }


    /* Aqui é impresso a lista de pretendentes */
    printf("\n");
    printf("Apresentando os pretendentes: \n\n");
    imprimeLista(lista_pretendentes);


    /* Enquanto tiver candidatos na pilha o programa é rodado*/
    while (!(pilhaVazia(pilha_candidatos))) {

        /* Aqui é apresentado o candidato da vez */
        printf("O candidato da vez é: ");
        imprimeTopo(pilha_candidatos);


        /* Para cada candidato é criado uma lista de concorrentes que
        *  é destruida no final de cada laço */
        struct lista_circular *lista_concorrentes;
        lista_concorrentes = inicializaLista();


        aux = lista_pretendentes->cabeca;
        aux2 = aux->proximo;
        concorrentes = 0;

        /* Aqui é percorrida a lista de pretendentes, se a interssecção for TRUE ele
        *  se torna um concorrente e é removido da lista de pretendentes e inserido na
        *  de concorrentes */
        do {

            if (interseccoes(pilha_candidatos, aux)) {
                printf("O Pretendente %d se tornou concorrente!\n", aux->novo_pretendente.id);
                concorrentes++;
                ReinsereLista(lista_concorrentes, aux->novo_pretendente);
                removeLista(lista_pretendentes, aux->novo_pretendente);
            }

                aux = aux2;
                aux2 = aux2->proximo;   

        } while(aux != lista_pretendentes->cabeca);


        printf("\n");

        /* Se não houver nenhum concorrente o candidato sai da pilha e começa um novo laço
        *  com outro candidato */
        if (concorrentes == 0) {
            pop(pilha_candidatos);
            destroiLista(lista_concorrentes);
            infelicidade++;
            printf("O candidato foi embora solteiro e triste, que venha o próximo: \n");
        }

        else {

            /* Se houver mais de um concorrente, a lista de concorrentes é percorrida e é feito uma disputa entre 2 concorrentes,
            *  o concorrente que perder no dado é removido e reinserido na lista de pretendentes, o que vencer jogará contra um novo
            *  concorrente até sobrar apenas um concorrente na lista */
            while (concorrentes != 1) { 
                
                    aux = lista_concorrentes->cabeca;
                    aux2 = aux->proximo;

                    aux->novo_pretendente.dado = rand() % 21;
                    aux2->novo_pretendente.dado = rand() % 21;

                    printf("O concorrente %d rolou %d.\n", aux->novo_pretendente.id, aux->novo_pretendente.dado);
                    printf("O concorrente %d rolou %d.\n\n", aux2->novo_pretendente.id, aux2->novo_pretendente.dado);

                    if (aux->novo_pretendente.dado > aux2->novo_pretendente.dado) {
                        printf("O concorrente %d perdeu e voltou a ser pretendente.\n\n", aux2->novo_pretendente.id);
                        ReinsereLista(lista_pretendentes, aux2->novo_pretendente);
                        removeLista(lista_concorrentes, aux2->novo_pretendente);
                        aux2 = aux->proximo;
                    }

                    else {
                        printf("O concorrente %d perdeu e voltou a ser pretendente.\n\n", aux->novo_pretendente.id);
                        ReinsereLista(lista_pretendentes, aux->novo_pretendente);
                        removeLista(lista_concorrentes, aux->novo_pretendente);
                        aux = aux2;
                    }
                    concorrentes--;    
            }
                
            /* Se o encontro com o candidato for um sucesso o candidato sai da pilha, o concorrente
            *  sai da lista e não volta para a lista de pretendentes, um contador de match é incrementado */
            if (encontro(pilha_candidatos, lista_concorrentes->cabeca)) {
                match++;
                pop(pilha_candidatos);
                destroiLista(lista_concorrentes);
                printf("Nós temos um match\n\n");
            }

            /* Se o encontro for um fracasso o candidato sai da pilha, o concorrente volta para lista de 
            *  pretendentes, um contador de infelicidade e mismatch é incrementado */
            else {
                printf("Não foi desta vez, que venho o próximo: \n\n");
                mismatch++;
                infelicidade++;
                pop(pilha_candidatos);
                aux = lista_concorrentes->cabeca;
                ReinsereLista(lista_pretendentes,aux->novo_pretendente);
                destroiLista(lista_concorrentes);
            }    
        }
    }

    printf("Não há mais candidatos\n\n");

    /* Aqui é somado no contador de infelicidade aqueles que sobraram na lista de pretendentes*/
    destroiPilha(pilha_candidatos);
    infelicidade = infelicidade + destroiLista(lista_pretendentes);

    printf("Infelicidade: %d\n", infelicidade);
    printf("Matches: %d\n", match);
    printf("Mismatches: %d\n", mismatch);     

    return 0;
}