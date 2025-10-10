#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "utils.h"

//---cadastro aluno---//
void cadAlunos(Aluno list[], int qtdAlunos){
    int matricula, dia, mes, ano;
    char sexo[10], cpf[15];

    while(1){

        if(qtdAlunos == MAX_ALUNOS){
            printf("lista cheia.");
            break;
        }else{
            printf("\n(aluno No%d)\n", qtdAlunos+1);

            printf("Matricula: ");
            scanf("%d", &matricula);

            printf("sexo: ");
            scanf(" %s", sexo);

            printf("nascimento (dd/mm/aa): ");
            scanf("%d/%d/%d", &dia, &mes, &ano);


            if(matricula <= 0){
                printf("matricula invalida");

            }else{
                int achouMatricula = 0;
                for(int j =0; j< qtdAlunos; j++){
                    if(list[j].nMatricula == matricula){
                        achouMatricula = 1;
                    }
                }
                if(achouMatricula == 1){
                    printf("Ja existe um aluno com essa matricula");
                    break;
                }else{
                    list[qtdAlunos].nMatricula = matricula;
                }
                
            } 
            if(!validaSexo(sexo)){
                printf("Sexo invalido");
                break;
            }

            strcpy(list[qtdAlunos].sexo,  sexo);
            qtd_alunos++;
        
            break;
        }
        
    }
}

void listAlunos(Aluno list[], int qtdAlunos){
    while(1){
        if(qtdAlunos == 0){
            printf("Lista vazia.\n");
            break;
        }else{
            printf("\n"); 
            for(int alu = 0; alu < qtdAlunos; alu++){
                printf("Aluno (%d)\n", alu+1);
                printf("Sexo: %c\n", list[alu].sexo);
                // printf("Data de Nascimento (%d)\n", list[alu].dNascimento);
                printf("Matricula: %d\n", list[alu].nMatricula);
                printf("CPF: %s\n", list[alu].cpf);
            }
            printf("\n"); 
            break;
        }
        
    }
}

void updateAlunos(Aluno list[], int qtdAlunos){
    int matricula;
    int achouAluno = 0, indiceAluno;

    listAlunos(list, qtdAlunos);

    while(1){
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
            break;
        }
        printf("matricula invalida ou nao existe");
    }
}

void deleteAlunos(Aluno list[], int qtdAlunos){
    /*code*/
}