#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "professor.h"
#include "utils.h"
//#include "disciplina.h"

//----menu----//
void menu();
/*
//----struct disciplina----//
typedef struct disciplina{
    int nMatricula;
    // falta coisa
} Disciplina;
*/

//--------main------//
int main(){
    int qtd_alunos = 0;
    int qtd_professores = 0;
    menu();

    return 0;
}

void menu(){

    //--------menu---------//
    int quit = 0, option;

    while(!quit){

        printf("\n-----------------------\n"
               "      Projeto Escola   \n"
               "-----------------------\n"
               "| 1 - Cadastro        |\n"
               "| 2 - Listar          |\n"
               "| 3 - Atualizar       |\n"
               "| 4 - Deletar         |\n"
               "| 5 - Relatorios      |\n"
               "| 6 - Sair            |\n"
               "-----------------------\n");
        scanf("%d", &option);
        printf("\n");

        switch (option)
        {
        //--------cadaster---------//
        case 1: startCadaster(); break;
        
        //--------listing---------//
        case 2: startListing(); break;
        
        //--------updating---------//
        case 3: startUpdating(); break;
        
        //-----deleting-----//
        case 4: startDeleting(); break;
        
        //-----especific----//
        case 5: printf("Relatorios\n"); break;

        //--------quit---------//
        case 6: quit = 1; break;
        
        default:
            printf("opcao invalida\n");
            break;
        }
    }
}