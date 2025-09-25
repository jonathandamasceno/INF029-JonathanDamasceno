#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

//---cadastro aluno---//
void cadAlunos(Aluno *list, int qtdAlunos){
    int matricula;
    char sx;

    while(1){

        if(qtdAlunos == MAX_ALUNOS){
            printf("lista cheia.");
            break;
        }else{
            printf("\n(aluno No%d)\n", qtdAlunos+1);

            printf("Matricula: ");
            scanf("%d", &matricula);

            printf("sexo: ");
            scanf(" %c", &sx);

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

            // converte pra minusculo caso tenha colocado maiusculo
            if(sx == 'F' || sx == 'M'){
                sx = sx - 'A' + 'a';

            }else if(sx != 'f' && sx != 'm'){
                printf("opcao invalida");
                break;
            }   
            
            list[qtdAlunos].sexo = sx;
            qtd_alunos++;
        
            break;
        }
        
    }
}

void listAlunos(Aluno *list, int qtdAlunos){
    printf("\n"); 
    for(int alu = 0; alu < qtdAlunos; alu++){
        printf("%d aluno - %d %c\n", alu+1, list[alu].nMatricula, list[alu].sexo);
    }

}

void updateAlunos(Aluno *list, int qtdAlunos){
    int matricula;
    int achouAluno = 0, indiceAluno;

    // melhorar visualmente a lista de alunos
    listAlunos(list, qtdAlunos);

    while(1){
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
            break;
        }
        printf("matricula invalida ou nao existe");
    }

    // aqui vao ser colocados os novos dados

}