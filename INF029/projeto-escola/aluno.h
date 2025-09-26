#include <stdio.h>
#include <stdlib.h>
#define MAX_ALUNOS 2

//----struct aluno----//
typedef struct aluno{
    char nome[100];
    int nMatricula;
    char sexo;
    char cpf[15];
    /*falta data de nascimento*/
} Aluno;

Aluno alunos[MAX_ALUNOS];
int qtd_alunos;

//cadastra//
void cadAlunos(Aluno list[], int qtdAlunos);
//lista//
void listAlunos(Aluno list[], int qtdAlunos);
//atualiza//
void updateAlunos(Aluno list[], int qtdAlunos);
//deleta//
void deleteAlunos(Aluno list[], int qtdAlunos);