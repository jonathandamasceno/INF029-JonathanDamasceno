#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#define MAX_ALUNOS 5

//----struct aluno----//
typedef struct aluno{
    char nome[100];
    int nMatricula;
    char sexo[10];
    char cpf[15];
    int ativo;
    int nDia, nMes, nAno;
} Aluno;

Aluno alunos[MAX_ALUNOS];
int qtd_alunos;

/*padrao*/
/*------------------------------------------------------------------------*/
void cadAlunos(Aluno list[], int* qtdAlunos);
void listAlunos(Aluno list[], int qtdAlunos);
void updateAlunos(Aluno list[], int qtdAlunos);
void deleteAlunos(Aluno list[], int qtdAlunos);
int validaMatriculaAlu(Aluno novo, Aluno * listaAlunos, int qtdAlunos);
/*------------------------------------------------------------------------*/

/*relatorios (funcoes que listam de maneira especifica/ordenadas)*/
/*------------------------------------------------------------------------*/
void listaAlunoNome(Aluno list[], int qtdAlunos);
void listaAlunoNascimento(Aluno list[], int qtdAlunos);
void listaAlunoAniversariante(Aluno list[], int qtdAlunos, int mes);
void listaAlunoSexo(Aluno list[], int qtdAlunos);
/*------------------------------------------------------------------------*/