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

            printf("\nMatricula: ");
            scanf("%d", &matricula);

            printf("\nsexo: ");
            scanf(" %c", &sx);

            if(matricula <= 0){
                printf("matricula invalida");

            }else{
                list[qtdAlunos].nMatricula = matricula;
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
    if(qtdAlunos == 0){
        printf("Lista vazia.\n");
    }else{
        for(int alu = 0; alu < qtdAlunos; alu++){
            printf("%d aluno - %d %c\n", alu+1, list[alu].nMatricula, list[alu].sexo);
        }
    }

}