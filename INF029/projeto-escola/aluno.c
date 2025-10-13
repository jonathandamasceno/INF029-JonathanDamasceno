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

    printf("sexo: ");
    scanf(" %s", novoAluno.sexo);

    printf("nascimento (dd/mm/aa): ");
    scanf("%d/%d/%d", &novoAluno.nDia, &novoAluno.nMes, &novoAluno.nAno);

    printf("cpf: ");
    scanf(" %s", novoAluno.cpf);

    if(!validaSexo(novoAluno.sexo)){
        printf("\nSexo invalido\n");
        return;
    }

    if(novoAluno.nMatricula <= 0){
        printf("\nmatricula invalida\n");
        return;
    }
    int achouMatricula = 0;
    for(int j =0; j< qtdAlunos; j++){
        if(list[j].nMatricula == novoAluno.nMatricula){
            achouMatricula = 1;
        }
    }
    if(achouMatricula == 1){
        printf("\nJa existe um aluno com essa matricula\n");
        return;   
    } 

    if(!validaData(novoAluno.nDia, novoAluno.nMes, novoAluno.nAno)){
        printf("\ndata de nascimento inválida\n");
        return;
    }
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
            printf("Aluno: %s\n", list[alu].nome);
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

    // chamando a função de cadastro com o 
    // indice do aluno pra refazer o cadastro

    if(achouAluno == 1){
        cadAlunos(alunos, indiceAluno);
        return;
    }
    printf("matricula invalida ou nao existe");

}

void deleteAlunos(Aluno list[], int qtdAlunos){
    /*code*/
}