#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "professor.h"
#include "utils.h"

//---cadastro professor---//
void cadProfessor(Professor list[], int* qtdProfessor){
    Professor novoProfessor;
    int kCont;

    if(*qtdProfessor >= MAX_PROFESSORES){
        printf("lista cheia.");
        return;
    }

    printf("\n(Professor No%d)\n", *qtdProfessor+1);

    printf("Nome: ");
    scanf(" %s", &novoProfessor.nome);

    printf("Matricula: ");
    scanf("%d", &novoProfessor.nMatricula);
    if(!validaMatriculaPro(novoProfessor, list, *qtdProfessor)) return;

    printf("sexo: ");
    scanf(" %s", novoProfessor.sexo);
    if(!validaSexo(novoProfessor.sexo)){
        printf("\nSexo invalido\n");
        return;
    }

    printf("nascimento (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &novoProfessor.nDia, &novoProfessor.nMes, &novoProfessor.nAno);
    if(!validaData(novoProfessor.nDia, novoProfessor.nMes, novoProfessor.nAno)){
        printf("\ndata de nascimento invalida\n");
        return;
    }

    printf("cpf: ");
    scanf(" %s", novoProfessor.cpf);
    if(!validaCpf(novoProfessor.cpf)){
        printf("\nCpf invalido\n");
        return;
    }

    for(int kCont =0; kCont< *qtdProfessor; kCont++){
        if(list[kCont].cpf == novoProfessor.cpf){
            printf("cpf ja cadastrado\n");
            return;
        }
    }

    novoProfessor.ativo = 1;
    list[*qtdProfessor] = novoProfessor;
    (*qtdProfessor)++;

    return;

}

void listProfessor(Professor list[], int qtdProfessor){
    /*tem que melhorar essa função pra caso nao tenha nenhum da lista ativo */
    if(qtdProfessor == 0){
        printf("Lista vazia.\n");
        return;
    }else{
        printf("\n"); 
        for(int prof = 0; prof < qtdProfessor; prof++){
            if(list[prof].ativo == 1){
                printf("Nome: %s\n", list[prof].nome);
                printf("Sexo: %s\n", list[prof].sexo);
                printf("Data de Nascimento: %d/%d/%d\n", list[prof].nDia, list[prof].nMes, list[prof].nAno);
                printf("Matricula: %d\n", list[prof].nMatricula);
                printf("CPF: %s\n", list[prof].cpf);
            }
            printf("\n"); 
        }
        
        return;
    }
    
}

void updateProfessor(Professor list[], int qtdProfessor){
    int matricula, jCont;
    int achouProfessor = 0;
    int* indice;
    printf("Matricula do professor que deseja atualizar: ");
    scanf("%d", &matricula);

    if(matricula > 0){
        for(int jCont =0; jCont< qtdProfessor; jCont++){
            if(list[jCont].nMatricula == matricula){
                achouProfessor = 1;
                *indice = jCont;
            }
        }
    }

    if(achouProfessor == 1){
        Professor novoProfessor;
        int kCont;

        if(qtdProfessor >= MAX_PROFESSORES){
            printf("lista cheia.");
            return;
        }

        printf("\n(Professor No%d)\n", qtdProfessor+1);

        printf("Novo nome: ");
        scanf(" %s", &novoProfessor.nome);

        printf("Nova Matricula: ");
        scanf("%d", &novoProfessor.nMatricula);
        if(!validaMatriculaPro(novoProfessor, list, qtdProfessor)) return;

        printf("Novo sexo: ");
        scanf(" %s", novoProfessor.sexo);
        if(!validaSexo(novoProfessor.sexo)){
            printf("\nSexo invalido\n");
            return;
        }

        printf("Nova data de nascimento (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &novoProfessor.nDia, &novoProfessor.nMes, &novoProfessor.nAno);
        if(!validaData(novoProfessor.nDia, novoProfessor.nMes, novoProfessor.nAno)){
            printf("\ndata de nascimento invalida\n");
            return;
        }

        printf("Novo cpf: ");
        scanf(" %s", novoProfessor.cpf);
        if(!validaCpf(novoProfessor.cpf)){
            printf("\nCpf invalido\n");
            return;
        }

        for(int kCont =0; kCont< qtdProfessor; kCont++){
            if(list[kCont].cpf == novoProfessor.cpf){
                printf("cpf ja cadastrado\n");
                return;
            }
        }

        novoProfessor.ativo = 1;
        list[qtdProfessor] = novoProfessor;
        qtdProfessor++;

        return;
    }

    printf("matricula invalida ou nao existe");
    return;

}

void deleteProfessor(Professor list[], int qtdProfessor){
    int matricula;
    int achouProfessor = 0, indiceProfessor;

    printf("Matricula do professor que deseja apagar: ");
    scanf("%d", &matricula);

    if(matricula > 0){
        for(int j =0; j< qtdProfessor; j++){
            if(list[j].nMatricula == matricula){
                achouProfessor = 1;
                indiceProfessor = j;
            }
        }
    }

    if(achouProfessor == 1){
        list[indiceProfessor].ativo = -1;
        return;
    }

    printf("matricula invalida ou nao existe");
}

int validaMatriculaPro(Professor novo, Professor list[], int qtdProfessor){
    if(novo.nMatricula <= 0){
        printf("\nmatricula invalida\n");
        return 0;
    }
    int achouMatricula = 1;
    for(int j =0; j< qtdProfessor; j++){
        if(list[j].nMatricula == novo.nMatricula){
            achouMatricula = 0;
        }
    }
    
    return achouMatricula;
}