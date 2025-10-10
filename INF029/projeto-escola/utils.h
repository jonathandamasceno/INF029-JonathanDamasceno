#include <stdio.h>
#include <stdlib.h>

//----qual sera cadastrado--//
void startCadaster();
//----qual sera listado--//
void startListing();
//----qual sera atualizado--//
void startUpdating();
//----qual sera deletado--//
void startDeleting();

/*VALIDAR DATA DE NASCIMENTO*/
int validaData(int dia, int mes, int ano);

/*VALIDAR CPF*/
int validaCpf(char cpf[]);

/*VALIDAR SEXO*/
int validaSexo(char sexo[]);

/**/
void toLowerStr(char string[]);

// tem que fazer as funções ainda