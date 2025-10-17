#ifndef UTILS_H
#define UTILS_H

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

void relatorios();

//------------------------------------------------------------------
/*validações*/
int validaData(int dia, int mes, int ano);
int validaCpf(char cpf[]);
int validaSexo(char sexo[]);
void toLowerStr(char string[]);
//------------------------------------------------------------------

#endif