#include <stdio.h>
#include <stdlib.h>
#define MAX_ALUNOS 2

//----struct aluno----//
typedef struct aluno{
    int nMatricula;
    char sexo;
    // falta coisa
} Aluno;
Aluno alunos[MAX_ALUNOS];
int qtd_alunos;

//cadastra//
void cadAlunos(Aluno *list, int qtdAlunos);
//lista//
void listAlunos(Aluno *list, int qtdAlunos);