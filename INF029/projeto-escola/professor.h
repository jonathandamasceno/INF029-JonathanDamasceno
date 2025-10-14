#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#define MAX_PROFESSORES 5

//----struct professor----//
typedef struct professor{
    char nome[100];
    int nMatricula;
    char sexo[10];
    char cpf[15];
    int ativo;
    int nDia, nMes, nAno;
} Professor;

Professor professores[MAX_PROFESSORES];
int qtd_professores;

/*padrao*/
/*------------------------------------------------------------------------*/
void cadProfessor(Professor list[], int* qtdProfessor);
void listProfessor(Professor list[], int qtdProfessor);
void updateProfessor(Professor list[], int qtdProfessor);
void deleteProfessor(Professor list[], int qtdProfessor);
int validaMatriculaPro(Professor novo, Professor list[], int qtdProfessor);
/*------------------------------------------------------------------------*/

/*relatorios (funcoes que listam de maneira especifica/ordenadas)*/
/*------------------------------------------------------------------------*/
/*code*/
/*------------------------------------------------------------------------*/