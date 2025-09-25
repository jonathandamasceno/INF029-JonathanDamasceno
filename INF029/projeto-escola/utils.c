#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "utils.h"

void startCadaster(int valor){
    switch (valor)
    {
    case 1:
        //inicia cadastro aluno//
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
        break;
    }
}

void startListing(int valor){
    switch (valor)
    {
    case 1:

        if(qtd_alunos == 0){
            printf("Lista vazia.\n");
            break;
        }

        //lista todos os alunos cadastrados//
        listAlunos(alunos, qtd_alunos);
        break;
    }
}

void startUpdating(int valor){
    switch (valor)
    {
    case 1:

        if(qtd_alunos == 0){
            printf("nenhum aluno cadastrado");
            break;

            // para antes se nao tem nenhum
        }

        //atualiza algum aluno especifico//
        updateAlunos(alunos, qtd_alunos);
        break;
    }
}