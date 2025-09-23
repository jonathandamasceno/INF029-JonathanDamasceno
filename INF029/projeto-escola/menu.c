#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

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

//----qual sera cadastrado--//
void startCadaster(int valor);
//----qual sera listado--//
void startListing(int valor);
//----qual sera atualizado--//
void startUpdating(int valor);

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

        printf("-----------------------\n"
               "      Projeto Escola   \n"
               "-----------------------\n"
               "| 1 - Cadastro        |\n"
               "| 2 - Listar          |\n"
               "| 3 - Atualizar       |\n"
               "| 4 - Deletar         |\n"
               "| 5 - Sair            |\n"
               "-----------------------\n");
        scanf("%d", &option);


        switch (option)
        {
        //--------cadaster---------//
        case 1:
            
            while(1){
                int cadaster;
                printf("\n1 - Aluno\n"
                       "2 - Professor\n"
                       "3 - Disciplina\n"
                       " ");

                scanf("%d", &cadaster);
                printf("\n");

                if(cadaster >= 1 && cadaster <= 3){
                    printf("\ncadastrando....\n");
                    startCadaster(cadaster);
                    
                    // aqui chama a funcao de cadastro dis|alun|prof //
                    // cadastraProfessor
                    // cadastraAluno
                    // cadastraDisciplina
                    break;
                }

                printf("\nopcao invalida\n");
            }
            
            break;
        
        //--------listing---------//
        case 2:

            while(1){
                int listing;
                printf("\n1 - Aluno\n"
                        "2 - Professor\n"
                        "3 - Disciplina\n"
                        " ");

                scanf("%d", &listing);
                printf("\n");

                if(listing >= 1 && listing <= 3){
                    startListing(listing);
                    // aqui chama a funcao de listar dis|alun|prof //
                    break;
                }

                printf("\nopcao invalida\n");
            }

            break;
            
        
        //--------updating---------//
        case 3:
            
            while(1){
                int updating;
                printf("\n1 - Aluno\n"
                        "2 - Professor\n"
                        "3 - Disciplina\n"
                        " ");

                scanf("%d", &updating);
                printf("\n");

                if(updating >= 1 && updating <= 3){
                    startUpdating(updating);
                    // aqui chama a funcao de atualizar dis|alun|prof //
                    break;
                }

                printf("\nopcao invalida\n");
            }

            break;
        
        case 4:
            printf("deleta");
            printf("\n");
            break;

        //--------quit---------//
        case 5:
            printf("sai");
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
        //lista todos os alunos cadastrados//
        listAlunos(alunos, qtd_alunos);
        break;
    }
}

void startUpdating(int valor){
    int novaMatricula;
    switch (valor)
    {
    case 1:

        if(qtd_alunos == 0){
            printf("nenhum aluno cadastrado");
            break;

            // para antes se nao tem nenhum
        }

        //atualiza algum aluno especifico//
        listAlunos(alunos, qtd_alunos);
        printf("\n");
        int att;

        while(1){
            printf("Escolha o numero do aluno a ser atualizado: ");
            scanf("%d", &att);
            if(att >= 1 && att <= qtd_alunos){
                printf("%d", alunos[att-1].nMatricula);


                // só um exemplo por enquanto
                printf("Nova matricula: ");
                scanf("%d", &novaMatricula);

                //vai ter algo pra validar 
                break;
            }
            printf("invalido\n");
        }

        break;
    }
}