#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <stdio.h>
#include <stdlib.h>
#include "professor.h"
#include "aluno.h"

#define MAX_ALUNOS_DISCIPLINA 50  
#define MAX_DISCIPLINAS 5

//----struct disciplina----//
typedef struct disciplina{
    char nome[50];
    int codigo;
    int semestre;
    int alunosMatriculados[MAX_ALUNOS];
    int qtdAlunos;
    int profResponsavel; 
    int ativo;

} Disciplina;

Disciplina disciplinas[MAX_DISCIPLINAS];
int qtd_disciplinas;

void adicionaDisciplina(Disciplina disc[], Professor professores[], int qtdProfessores, int* qtdDisciplinas);   
void listaDisciplinas(Disciplina disc[], int qtdDisciplinas, Professor professores[], int qtdProfessores);
void adicionaAlunoDisciplina(Disciplina disc[], Aluno alunos[], int qtdAlunos, int qtdDisciplinas);
void removeAluno(Disciplina disc[], int qtdDisciplinas, Aluno alunos[], int qtdAlunos);
int geraCodigo(int qtdDisciplinas); 

#endif