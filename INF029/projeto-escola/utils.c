#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
// #include "professor.h"
// #include "discilinas.h"
#include "utils.h"

void startCadaster(){
    int cadaster;
    printf("\n1 - Aluno\n"
           "2 - Professor\n"
           "3 - Disciplina\n"
           ">");

    scanf("%d", &cadaster);
    printf("\n");

    if(cadaster >= 1 && cadaster <= 3){
        printf("\ncadastrando....\n");
        switch (cadaster)
        {
        case 1: 
            cadAlunos(alunos, qtd_alunos); 
            break;
        case 2:
            //inicia cadastro professor//
            //vao ser coisas parecidas // 
            //funcoes que verificam informacoes serao unicas pros tres casos//  
            break;
        case 3:
            // inicia cadastro disciplina // 
            break;
        default:
            printf("valor invalido");
            break;
        }
    }

}

void startListing(){
    int listing;
    printf("\n1 - Aluno\n"
           "2 - Professor\n"
           "3 - Disciplina\n"
           ">");

    scanf("%d", &listing);
    printf("\n");

    if(listing >= 1 && listing <= 3){
        printf("\nlistando....\n");
        switch (listing)
        {
        case 1:
    
            //lista todos os alunos cadastrados//
            listAlunos(alunos, qtd_alunos);
            break;

        default:
            printf("valor invalido");
            break;
        }
    }

}

void startUpdating(){
    int updating;
    printf("\n1 - Aluno\n"
           "2 - Professor\n"
           "3 - Disciplina\n"
           ">");

    scanf("%d", &updating);
    printf("\n");

    if(updating >= 1 && updating <= 3){
        switch (updating)
        {
        case 1:
            //atualiza algum aluno especifico//
            updateAlunos(alunos, qtd_alunos);
            break;

        default:
            printf("valor invalido");
            break;
        }

    }
}

void startDeleting(){
    int deleting;
    printf("\n1 - Aluno\n"
           "2 - Professor\n"
           "3 - Disciplina\n"
           ">");

    scanf("%d", &deleting);
    printf("\n");

    if(deleting >= 1 && deleting <= 3){
        switch (deleting)
        {
        case 1:
            //atualiza algum aluno especifico//
            deleteAlunos(alunos, qtd_alunos);
            break;

        default:
            printf("valor invalido");
            break;
        }

    }
    /* code */
}