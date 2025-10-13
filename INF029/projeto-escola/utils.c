#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
}

void toLowerStr(char string[]){
    for(int iCont = 0; string[iCont] != '\0'; iCont++){
        if(string[iCont] >= 'A' && string[iCont] <= 'Z'){
            string[iCont] = string[iCont] + 32;
        }
    }
}

int validaSexo(char sexo[]){
    // faz uma copia
    char temp[10];
    int jCont;
    for(jCont = 0; sexo[jCont] != '\0'; jCont++){
        temp[jCont] = sexo[jCont];
    }
    temp[jCont] = '\0';

    // minusculo
    toLowerStr(temp);

    // retorna se algum desses é valido
    return ( 
        strcmp(temp, "m") == 0 ||
        strcmp(temp, "f") == 0 ||
        strcmp(temp, "masculino") == 0 ||
        strcmp(temp, "feminino") == 0
    );


}

int validaData(int dia, int mes, int ano){
    // algo
}

int validaCpf(char cpf[]){
    char arrAux[12];
    int iCont, jCont = 0;
    int soma=0, pDigito, sDigito;

    // tira as pontuações, se houver
    for(iCont = 0; cpf[iCont] != '\0'; iCont++){
        if(cpf[iCont] >= '0' && cpf[iCont] <= '9'){
            arrAux[jCont++] = cpf[iCont];
        }
    }

    // se nao tem numeros o suficiente
    if(jCont != 11) return 0;

    // metodo pra validar 
    for(iCont = 0, jCont = 10; iCont < 9; iCont++, jCont--){
        soma += (arrAux[iCont] - '0') * jCont;
    }

    // primeiro digito
    pDigito = (10 * soma) % 11;
    if(pDigito > 9) pDigito = 0;

    soma = 0; 
    for(iCont = 0, jCont = 11; iCont < 10; iCont++, jCont--){
        soma += (arrAux[iCont] - '0') * jCont;
    }

    // segundo digito
    sDigito = (10 * soma) % 11;
    if(sDigito > 9) sDigito = 0;

    return(arrAux[9] - '0' == pDigito && arrAux[10] - '0' == sDigito);

}