#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "utils.h"

void cadAlunos(Aluno list[], int* qtdAlunos){
    Aluno novoAluno;
    int kCont;

    if(*qtdAlunos == MAX_ALUNOS){
        printf("lista cheia.");
        return;
    }

    printf("Nome: ");
    scanf(" %s", novoAluno.nome);

    printf("Matricula: ");
    scanf("%d", &novoAluno.nMatricula);
    if(!validaMatriculaAlu(novoAluno, list, *qtdAlunos)) return;

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

    for(int kCont =0; kCont< *qtdAlunos; kCont++){
        if(list[kCont].cpf == novoAluno.cpf){
            printf("cpf ja cadastrado\n");
            return;
        }
    }

    novoAluno.ativo = 1;
    list[*qtdAlunos] = novoAluno;
    (*qtdAlunos)++;

    return;

}

void listAlunos(Aluno list[], int qtdAlunos){
    int achou = 0;

    if(qtdAlunos == 0){
        printf("Lista vazia.\n");
        return;
    }
    
    for(int alu = 0; alu < qtdAlunos; alu++){
        if(list[alu].ativo == 1){
            achou = 1;
        }
    }

    if(!achou){
        printf("Nenhum aluno cadastrado");
        return;
    }


    printf("\n"); 
    for(int alu = 0; alu < qtdAlunos; alu++){
        if(list[alu].ativo == 1){
            printf("Nome: %s\n", list[alu].nome);
            printf("Sexo: %s\n", list[alu].sexo);
            printf("Data de Nascimento: %d/%d/%d\n", list[alu].nDia, list[alu].nMes, list[alu].nAno);
            printf("Matricula: %d\n", list[alu].nMatricula);
            printf("CPF: %s\n", list[alu].cpf);
        }
        printf("\n"); 

    }
    
}

void updateAlunos(Aluno list[], int qtdAlunos){

    if(qtdAlunos == 0){
        printf("lista vazia.\n");
        return;
    }

    int matricula, jCont;
    int achouAluno = 0;
    int indice;
    printf("Matricula do professor que deseja atualizar: ");
    scanf("%d", &matricula);

    if(matricula > 0){
        for(int jCont =0; jCont< qtdAlunos; jCont++){
            if(list[jCont].nMatricula == matricula){
                achouAluno = 1;
                indice = jCont;
            }
        }
    }

    if(achouAluno == 1){
        Aluno novoAluno;
        int kCont;

        if(qtdAlunos >= MAX_ALUNOS){
            printf("lista cheia.");
            return;
        }

        printf("\n(Professor No%d)\n", qtdAlunos+1);

        printf("Novo nome: ");
        scanf(" %s", novoAluno.nome);

        printf("Nova Matricula: ");
        scanf("%d", &novoAluno.nMatricula);
        if(!validaMatriculaAlu(novoAluno, list, qtdAlunos)) return;

        printf("Novo sexo: ");
        scanf(" %s", novoAluno.sexo);
        if(!validaSexo(novoAluno.sexo)){
            printf("\nSexo invalido\n");
            return;
        }

        printf("Nova data de nascimento (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &novoAluno.nDia, &novoAluno.nMes, &novoAluno.nAno);
        if(!validaData(novoAluno.nDia, novoAluno.nMes, novoAluno.nAno)){
            printf("\ndata de nascimento invalida\n");
            return;
        }

        printf("Novo cpf: ");
        scanf(" %s", novoAluno.cpf);
        if(!validaCpf(novoAluno.cpf)){
            printf("\nCpf invalido\n");
            return;
        }

        for(int kCont =0; kCont< qtdAlunos; kCont++){
            if(list[kCont].cpf == novoAluno.cpf){
                printf("cpf ja cadastrado\n");
                return;
            }
        }

        novoAluno.ativo = 1;
        list[indice] = novoAluno;

        return;
    }

    printf("matricula invalida ou nao existe");
    return;

}

void deleteAlunos(Aluno list[], int qtdAlunos){
    int matricula;
    int achouAluno = 0, indiceAluno;

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
        list[indiceAluno].ativo = -1;
        return;
    }

    printf("matricula invalida ou nao existe");
}

int validaMatriculaAlu(Aluno novo, Aluno * listaAlunos, int qtdAlunos){
    if(novo.nMatricula <= 0){
        printf("\nmatricula invalida\n");
        return 0;
    }
    int achouMatricula = 1;
    for(int j =0; j< qtdAlunos; j++){
        if(listaAlunos[j].nMatricula == novo.nMatricula){
            achouMatricula = 0;
        }
    }
    
    return achouMatricula;
}
void listaAlunoNome(Aluno list[], int qtdAlunos){
    //
}
void listaAlunoAniversariante(Aluno list[], int qtdAlunos, int mes){
    int achouAniv = 0, iCont;

    for(iCont = 0; iCont < qtdAlunos; iCont++){
        if(list[iCont].nMes == mes){
            printf("nome: %s\n", list[iCont].nome);
            achouAniv = 1;
        }
    }
    if(!achouAniv){
        printf("sem aniversariantes");
    }
}