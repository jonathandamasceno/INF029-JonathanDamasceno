#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disciplina.h"
#include "aluno.h"
#include "professor.h"
#include "utils.h"

void startCadaster(){
    int cadaster;
    printf("\n---------------\n"
           "1 - Aluno\n"
           "2 - Professor\n"
           "3 - Disciplina"
           "\n---------------\n"
           ">");

    scanf("%d", &cadaster);

    if(cadaster >= 1 && cadaster <= 3){
        switch (cadaster)
        {
        case 1: cadAlunos(alunos, &qtd_alunos); break;
        case 2: cadProfessor(professores, &qtd_professores); break;
        case 3: {
            int opc;
            printf("\n--------------------------------\n"
                    "1 - Cadastrar disciplina\n"
                    "2 - Cadastrar aluno em disciplina"
                    "\n-------------------------------\n"
                    ">");
            scanf("%d", &opc);
            if(opc == 1){
                adicionaDisciplina(disciplinas, professores, qtd_professores, &qtd_disciplinas); break;
            }else if(opc == 2){
                adicionaAlunoDisciplina(disciplinas, alunos, qtd_alunos, qtd_disciplinas); break;
            }
            printf("opcao invalida"); break;
        }
        default: printf("valor invalido"); break;
        }
    }

}

void startListing(){
    int listing;
    printf("\n---------------\n"
           "1 - Aluno\n"
           "2 - Professor\n"
           "3 - Disciplina"
           "\n---------------\n"
           ">");

    scanf("%d", &listing);

    if(listing >= 1 && listing <= 3){
        switch (listing)
        {
        case 1: listAlunos(alunos, qtd_alunos); break;
        case 2: listProfessor(professores, qtd_professores); break;
        case 3: listaDisciplinas(disciplinas, qtd_disciplinas, professores, qtd_professores); break;
        default: printf("valor invalido"); break;
        }
    }

}

void startUpdating(){
    int updating;
    printf("\n---------------\n"
           "1 - Aluno\n"
           "2 - Professor"
           "\n---------------\n"
           ">");

    scanf("%d", &updating);

    if(updating >= 1 && updating <= 3){
        switch (updating)
        {
        case 1: updateAlunos(alunos, qtd_alunos); break;
        case 2: updateProfessor(professores, qtd_professores); break;
        default: printf("valor invalido"); break;
        }

    }
}

void startDeleting(){
    int deleting;
    printf("\n---------------\n"
           "1 - Aluno\n"
           "2 - Professor\n"
           "3 - Disciplina"
           "\n---------------\n"
           ">");

    scanf("%d", &deleting);

    if(deleting >= 1 && deleting <= 3){
        switch (deleting)
        {
        case 1: deleteAlunos(alunos, qtd_alunos); break;
        case 2: deleteProfessor(professores, qtd_professores); break;
        case 3:{
            printf("\n---------------------------\n"
                   "remove aluno da disciplina"
                   "\n---------------------------\n");
            removeAluno(disciplinas, qtd_disciplinas, alunos, qtd_alunos); break;
        }
        default: printf("valor invalido"); break;
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
    int diaCadaMes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(mes < 1 || mes > 12) return 0;
    if(ano < 1900 || ano > 2025) return 0;

    // se o ano for bissexto -> fev tem 29 dias
    if(mes == 2 && ((ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0))){
        return (dia >= 1 && dia <= 29);
    }

    return (dia <= diaCadaMes[mes - 1] && dia >= 1);

}

int validaCpf(char cpf[]){
    char arrAux[12];
    int iCont, jCont = 0;
    int soma=0, pDigito, sDigito;

    // verifica se todos os numeros sao iguais
    for(iCont = 1; cpf[iCont] != '\0'; iCont++){
        if(cpf[iCont] != cpf[0]) break;
    }
    if(iCont == 11 ) return 0;

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

void relatorios(){
    /*code*/
}