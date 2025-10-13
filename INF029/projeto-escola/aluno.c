#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "utils.h"

//---cadastro aluno---//
void cadAlunos(Aluno list[], int qtdAlunos){
    Aluno novoAluno;
    char sexo[10], cpf[15];

    if(qtdAlunos == MAX_ALUNOS){
        printf("lista cheia.");
        return;
    }

    printf("\n(aluno No%d)\n", qtdAlunos+1);

    printf("Nome: ");
    scanf(" %s", &novoAluno.nome);

    printf("Matricula: ");
    scanf("%d", &novoAluno.nMatricula);
    if(!validaMatricula(novoAluno, list, qtdAlunos)) return;

    printf("sexo: ");
    scanf(" %s", novoAluno.sexo);
    if(!validaSexo(novoAluno.sexo)){
        printf("\nSexo invalido\n");
        return;
    }

    printf("nascimento (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &novoAluno.nDia, &novoAluno.nMes, &novoAluno.nAno);
    if(!validaData(novoAluno.nDia, novoAluno.nMes, novoAluno.nAno)){
        printf("\ndata de nascimento invalida\n");
        return;
    }

    printf("cpf: ");
    scanf(" %s", novoAluno.cpf);
    if(!validaCpf(novoAluno.cpf)){
        printf("\nCpf invalido\n");
        return;
    }

    list[qtdAlunos] = novoAluno;
    qtd_alunos++;

    return;

}

void listAlunos(Aluno list[], int qtdAlunos){

    if(qtdAlunos == 0){
        printf("Lista vazia.\n");
        return;
    }else{
        printf("\n"); 
        for(int alu = 0; alu < qtdAlunos; alu++){
            printf("Aluno %d: %s\n", alu+1, list[alu].nome);
            printf("Sexo: %s\n", list[alu].sexo);
            printf("Data de Nascimento: %d/%d/%d\n", list[alu].nDia, list[alu].nMes, list[alu].nAno);
            printf("Matricula: %d\n", list[alu].nMatricula);
            printf("CPF: %s\n", list[alu].cpf);
        }
        printf("\n"); 
        return;
    }
    
}

void updateAlunos(Aluno list[], int qtdAlunos){
    int matricula;
    int achouAluno = 0, indiceAluno;

    listAlunos(list, qtdAlunos);
    // por enquanto só atualiza a matricula
    printf("Matricula do aluno que deseja atualizar: ");
    scanf("%d", &matricula);

    if(matricula > 0){
        for(int j =0; j< qtdAlunos; j++){
            if(list[j].nMatricula == matricula){
                achouAluno = 1;
                indiceAluno = j;
            }
        }
    }

    if(achouAluno == 1){
        cadAlunos(alunos, indiceAluno);
        return;
    }
    printf("matricula invalida ou nao existe");

}

void deleteAlunos(Aluno list[], int qtdAlunos){
    /*code*/
}