#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "utils.h"
//#include "professor.h"
//#include "disciplina.h"

//----menu----//
void menu();

/*
//----struct professor----//
typedef struct professor{
    int nMatricula;
    // falta coisa
} Professor;

//----struct disciplina----//
typedef struct disciplina{
    int nMatricula;
    // falta coisa
} Disciplina;
*/


/*
Professor professores[MAX_PROFESSORES];
Disciplina disciplinas[MAX_DISCIPLINAS];
*/

/*
//---cadastro professor---//
void infProfessor(Professor *list, int qtdProfessores);

//---cadastro disciplina---//
void infDisciplina(Disciplina *list, int qtdDisciplinas);
*/

//--------main------//
int main(){

    menu();

    return 0;
}

int qtd_alunos=0;

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
               "| 5 - Sair            |\n"
               "-----------------------\n");
        scanf("%d", &option);
        printf("\n");

        switch (option)
        {
        //--------cadaster---------//
        case 1:
            startCadaster();
            break;
        
        //--------listing---------//
        case 2:
            startListing();
            break;
        
        //--------updating---------//
        case 3:
            
            startUpdating();
            break;
        
        //-----deleting-----//
        case 4:
            printf("deleta");
            printf("\n");
            break;

        //--------quit---------//
        case 5:
            printf("\n");
            quit = 1;
            break;
        
        default:
            printf("opcao invalida");
            printf("\n");
            break;
        }
    }
}