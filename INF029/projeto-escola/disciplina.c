#include <stdio.h>
#include <stdlib.h>
#include "disciplina.h"
#include "utils.h"


// só pra ser automatico
int geraCodigo(int qtdDisciplinas){
    return qtdDisciplinas++;
}


void adicionaDisciplina(Disciplina disc[], Professor professores[], int qtdProfessores, int* qtdDisciplinas){
    Disciplina novaDisciplina;
    Professor responsavel;
    int kCont, achou = 0;

    if(*qtdDisciplinas >= MAX_DISCIPLINAS){
        printf("lista cheia."); return;
    }

    printf("Nome: ");
    scanf(" %s", novaDisciplina.nome);
    novaDisciplina.codigo = geraCodigo((*qtdDisciplinas));
    printf("codigo gerado: %d", novaDisciplina.codigo);

    printf("Matricula do professor responsavel: ");
    scanf("%d", novaDisciplina.profResponsavel);

    for(int prof = 0; prof < qtdProfessores; prof++){
        if(professores[prof].ativo = 1 && (professores[prof].nMatricula == disc[prof].profResponsavel)){
            achou = 1;
            break;
        }
    }
    if(!achou){
        printf("matricula nao existe\n"); return;
    }

    printf("Semestre: (1/2)");
    scanf("%d", novaDisciplina.semestre);
    if(novaDisciplina.semestre < 1 || novaDisciplina.semestre > 2){
        printf("semestre invalido\n"); return;
    }

    novaDisciplina.qtdAlunos = 0;
    novaDisciplina.ativo = 1;
    disc[*qtdDisciplinas] = novaDisciplina;
    (*qtdDisciplinas)++;

    return;

}

void listaDisciplinas(Disciplina disc[], int qtdDisciplinas, Professor professores[], int qtdProfessores){
    int achou = 0;

    if(qtdDisciplinas == 0){
        printf("lista vazia.\n"); return;
    }
    for(int disciplinas = 0; disciplinas < qtdDisciplinas; disciplinas++){
        if(disc[disciplinas].ativo == 1){
            achou = 1;
            break;
        }
    }
    if(!achou){
        printf("Lista vazia.\n"); return;
    } 

    for(int iCont = 0; iCont < qtdDisciplinas; iCont++){
        printf("Nome: %s\n", disc[iCont].nome);
        printf("Código: %d\n", disc[iCont].codigo);
        printf("Semestre: %d\n", disc[iCont].semestre);
        printf("Quantidade de alunos: %d\n", disc[iCont].qtdAlunos);


        int temProfessor = 0;
        for(int jCont = 0; jCont < qtdProfessores; jCont++){
            if(professores[jCont].ativo = 1 && (professores[jCont].nMatricula == disc[iCont].profResponsavel)){
                printf("Professor: %s", professores[jCont].nome);
                temProfessor = 1;
                break;
            }
        }

        if(!temProfessor){
            printf("Essa disciplina ainda nao tem professor\n");
        }
    }
}
void adicionaAlunoDisciplina(Disciplina disc[], Aluno alunos[], int qtdAlunos, int qtdDisciplinas){
    int codigo, matricula;

    printf("codigo da disciplina: ");
    scanf("%d", &codigo);

    int achou = 0;
    for(int iCont = 0; iCont < qtdDisciplinas; iCont++){
        if(codigo == disc[iCont].codigo){
            if(disc[iCont].qtdAlunos >= MAX_ALUNOS_DISCIPLINA){
                printf("numero maximo de alunos alcancado\n");
                return;
            }
            achou = 1;
            break;
        }

        if(!achou){
            printf("essa disciplina nao existe\n");
            return;
        }

        printf("Matrícula do aluno: ");
        scanf("%d", &matricula);

        achou = 0;
        for(int jCont = 0; jCont < qtdAlunos; jCont++){
            if(alunos[jCont].ativo = 1 && (alunos[jCont].nMatricula == matricula)){
                achou = 1;
                break;
            }
        }
        if(!achou){
            printf("matricula nao existe\n");
            return;
        }

        for(int kCont = 0; kCont < disciplinas[iCont].qtdAlunos; kCont++) {
            if (disciplinas[iCont].alunosMatriculados[kCont] == matricula) {
                printf("Aluno já está matriculado na disciplina.\n");
                return;
            }
        }

        disciplinas[iCont].alunosMatriculados[disciplinas[iCont].qtdAlunos++] = matricula;
        printf("Aluno matriculado\n");
        return;                                
    }
}

void removeAluno(Disciplina disc[], int qtdDisciplinas, Aluno alunos[], int qtdAlunos){
    int codigo, matricula;

    printf("codigo da disciplina: ");
    scanf("%d", &codigo);

    int achou = 0;
    for(int iCont = 0; iCont < qtdDisciplinas; iCont++){
        if(codigo == disc[iCont].codigo){
            achou = 1;
            break;
        }

        if(!achou){
            printf("essa disciplina nao existe\n");
            return;
        }

        printf("Matrícula do aluno a ser removido: ");
        scanf("%d", &matricula);

        achou = 0;
        for(int jCont = 0; jCont < qtdAlunos; jCont++){
            if(alunos[jCont].ativo = 1 && (alunos[jCont].nMatricula == matricula)){
                achou = 1;
                break;
            }
        }

        if(!achou){
            printf("matricula nao existe\n");
            return;
        }

        achou = 0;
        for(int kCont = 0; kCont < disciplinas[iCont].qtdAlunos; kCont++) {
            if (disciplinas[iCont].alunosMatriculados[kCont] == matricula) {
                achou = 1;
                break;
            }
        }

        if(!achou){
            printf("aluno nao esta matriculado nesta disciplina\n");
            return;
        }

        for (int jCont = 0; jCont < disciplinas[iCont].qtdAlunos; jCont++) {
            if (disciplinas[iCont].alunosMatriculados[jCont] == matricula) {
                for (int kCont = jCont; kCont < disciplinas[iCont].qtdAlunos - 1; kCont++) {
                    disciplinas[iCont].alunosMatriculados[kCont] = disciplinas[iCont].alunosMatriculados[kCont + 1];
                }
                disciplinas[iCont].qtdAlunos--;
                printf("Aluno removido.\n");
                return;      
            }
        }
                                  
    }
}