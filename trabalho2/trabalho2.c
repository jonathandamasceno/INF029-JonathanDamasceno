#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "trabalho2.h"
typedef struct vAux{
    int *elemento; 
    int qtdElementos;
    int tamEstrutura;
} vAux;

vAux *vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
 
    if(posicao < 1 || posicao > TAM){
        // se posição é um valor válido {entre 1 e 10}
        return POSICAO_INVALIDA;
    }

    if(tamanho < 1){
        // o tamanho nao pode ser menor que 1
        return TAMANHO_INVALIDO;
    }
    
    int posicaoReal = posicao - 1;

    if(vetorPrincipal[posicaoReal] != NULL){
        // a posicao pode já existir estrutura auxiliar
        return JA_TEM_ESTRUTURA_AUXILIAR;
    }
    
    vAux *novaEstrutura = (vAux * ) malloc(sizeof(vAux)); 
    if (novaEstrutura == NULL){
        free(novaEstrutura);
        return SEM_ESPACO_DE_MEMORIA;
    }

    novaEstrutura->elemento = malloc(tamanho * sizeof(int)); 
    // tem que alocar espaço pro campo de elemento
    if (novaEstrutura->elemento == NULL){
        free(novaEstrutura);
        return SEM_ESPACO_DE_MEMORIA;
    }

    novaEstrutura->qtdElementos = 0;
    novaEstrutura->tamEstrutura = tamanho;

    vetorPrincipal[posicaoReal] = novaEstrutura;

    // deu tudo certo, crie
    return SUCESSO;

}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
 
    if(posicao < 1 || posicao > TAM){
        return POSICAO_INVALIDA;
    }
    
    int posicaoReal = posicao - 1;

    if(vetorPrincipal[posicaoReal] == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    
    vAux *aux = vetorPrincipal[posicaoReal];
    if(aux->qtdElementos >= aux->tamEstrutura){
        return SEM_ESPACO;
    }

    aux->elemento[aux->qtdElementos] = valor;
    aux->qtdElementos++;

    return SUCESSO;

}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    
    if(posicao < 1 || posicao > TAM){
        return POSICAO_INVALIDA;
    }
    
    int posicaoReal = posicao - 1;

    if(vetorPrincipal[posicaoReal] == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }

    vAux *aux = vetorPrincipal[posicaoReal];

    if(aux->qtdElementos == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    // diminui a quantidade total da lista, mas o item ainda existe lá ( até ser alterado de novo)
    aux->qtdElementos--;

    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{

    if(posicao < 1 || posicao > TAM){
        return POSICAO_INVALIDA;
    }
    
    int posicaoReal = posicao - 1;

    if(vetorPrincipal[posicaoReal] == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }

    vAux *aux = vetorPrincipal[posicaoReal];

    if(aux->qtdElementos == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    int achou = 0;
    int iCont = 0, jCont = 0;
    // jogar o valor a ser excluido pra ultima posicao e fazer a exclusao logica
    for(iCont=0; iCont<aux->qtdElementos; iCont++){
        if(aux->elemento[iCont] == valor){
            achou = 1;
            // para no momento que acha pra guardar a posicao em que ele foi guardado
            break;
        }
    }

    if(!achou){
        return NUMERO_INEXISTENTE;
    }

    for(jCont = iCont; jCont<aux->qtdElementos; jCont++){
        aux->elemento[jCont] = aux->elemento[jCont+1];
    }

    aux->qtdElementos--;

    return SUCESSO;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int posicaoReal = posicao - 1;

    if(posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }

    if(vetorPrincipal[posicaoReal] == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }

    vAux *aux = vetorPrincipal[posicaoReal];


    for(int iCont = 0; iCont<aux->qtdElementos; iCont++){
        vetorAux[iCont] = aux->elemento[iCont];
    }

    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int posicaoReal = posicao - 1;

    if(posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }

    if(vetorPrincipal[posicaoReal] == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }

    vAux *aux = vetorPrincipal[posicaoReal];
    for(int i = 0; i<aux->qtdElementos; i++){
        vetorAux[i] = aux->elemento[i];
    }

    // ordenando usando insertion
    int jCont = 0, key;
    for(int iCont = 1; iCont<aux->qtdElementos; iCont++){
        key = vetorAux[iCont];
        jCont = iCont -1;
        while(jCont >= 0 && vetorAux[jCont] > key){
            vetorAux[jCont + 1] = vetorAux[jCont];
            jCont = jCont -1;
        }

        vetorAux[jCont+1] = key;
    }
    return SUCESSO;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int temEst = 0;

    /*testa se tem alguma estrutura com algum item*/
    for(int iCont = 0; iCont<TAM; iCont++){
        if(vetorPrincipal[iCont] != NULL && vetorPrincipal[iCont]->qtdElementos > 0){
            temEst = 1;
        }
    }
    if(!temEst){
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }

    // verifica se existe a estrutura, se existir, copia todos os valores dela
    int tamVetorAux = 0;
    for(int iCont = 0; iCont<TAM; iCont++){
        if(vetorPrincipal[iCont] != NULL && vetorPrincipal[iCont]->qtdElementos > 0){
            vAux * aux = vetorPrincipal[iCont];
            for(int kCont = 0; kCont < aux->qtdElementos; kCont++){
                vetorAux[tamVetorAux] = aux->elemento[kCont];
                tamVetorAux++;
            }
        }
    }

    
    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int temEst = 0;

    /*testa se tem alguma estrutura com algum item*/
    for(int iCont = 0; iCont<TAM; iCont++){
        if(vetorPrincipal[iCont] != NULL && vetorPrincipal[iCont]->qtdElementos > 0){
            temEst = 1;
        }
    }
    if(!temEst){
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }

    // verifica se existe a estrutura, se existir, copia todos os valores dela
    int tamVetorAux = 0;
    for(int iCont = 0; iCont<TAM; iCont++){
        if(vetorPrincipal[iCont] != NULL && vetorPrincipal[iCont]->qtdElementos > 0){
            vAux *aux = vetorPrincipal[iCont];
            for(int i = 0; i<aux->qtdElementos; i++){
                vetorAux[tamVetorAux] = aux->elemento[i];
                tamVetorAux++;
            }

            // ordenando usando insertion
            int jCont = 0, key;
            for(int iCont = 1; iCont<tamVetorAux; iCont++){
                key = vetorAux[iCont];
                jCont = iCont -1;
                while(jCont >= 0 && vetorAux[jCont] > key){
                    vetorAux[jCont + 1] = vetorAux[jCont];
                    jCont = jCont -1;
                }

                vetorAux[jCont+1] = key;
            }
        }
    }

    return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

    if(posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }

    int posicaoReal = posicao - 1;

    if(vetorPrincipal[posicaoReal] == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    // pegando o vetor e o tamanho novo 
    vAux *aux = vetorPrincipal[posicaoReal];
    int somaTamanhos = aux->tamEstrutura + novoTamanho;

    if(somaTamanhos < 1){
        return NOVO_TAMANHO_INVALIDO;
    }

    // realocando em outra variavel pra teste
    int *temp = realloc(aux->elemento, somaTamanhos * sizeof(int));

    if(temp == NULL){
        return SEM_ESPACO_DE_MEMORIA;
    }

    aux->elemento = temp;
    aux->tamEstrutura = somaTamanhos;
    if(novoTamanho < 0){
        aux->qtdElementos += novoTamanho;
    }

    return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    int qtd = 0;

    if(posicao < 1 || posicao > TAM){
        return POSICAO_INVALIDA;
    }

    int posicaoReal = posicao - 1;

    if(vetorPrincipal[posicaoReal] == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }

    vAux *aux = vetorPrincipal[posicaoReal];
    if(aux->qtdElementos == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    qtd = aux->qtdElementos;

    return qtd;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    int achou = 0;
    for(int i=0; i<TAM; i++){
        if(vetorPrincipal[i] != NULL && vetorPrincipal[i]->qtdElementos != 0){
            achou = 1;
        }
    }

    if(!achou){
        return NULL;
    }

    No *cab = malloc(sizeof(No));
    cab->prox = NULL;

    No *atual = cab;

    for(int iCont=0; iCont<TAM; iCont++){
        if(vetorPrincipal[iCont] != NULL && vetorPrincipal[iCont]->qtdElementos > 0){
            vAux *aux = vetorPrincipal[iCont];

            for(int jCont = 0; jCont < aux->qtdElementos; jCont++){
                No *novoItem = malloc(sizeof(No));

                novoItem->conteudo = aux->elemento[jCont];
                novoItem->prox = NULL;

                atual->prox = novoItem;
                atual = novoItem;
            }
        }
    }
    return cab;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{

    No *numAtual = inicio->prox;
    int cont = 0;

    while(numAtual != NULL){
        vetorAux[cont] = numAtual->conteudo;
        numAtual = numAtual->prox;
        cont++;
    }

}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    No *numAtual = *inicio;
    No *numProx;

    while(numAtual != NULL){
        numProx = numAtual->prox;
        free(numAtual);
        numAtual = numProx;
    }

    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{

    for(int i=0; i<TAM; i++){
        vetorPrincipal[i] = NULL; 
    }

}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{

    for(int i=0; i<TAM; i++){
        if(vetorPrincipal[i] != NULL){
            vAux *aux = vetorPrincipal[i];

            free(aux->elemento);
            free(aux);

            vetorPrincipal[i] = NULL;
        }
    }

}
