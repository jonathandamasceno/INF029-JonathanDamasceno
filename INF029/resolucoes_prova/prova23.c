#include <stdio.h>
#include <stdlib.h>


typedef struct Digitos
{
    
    int arrayValores[4];
    int retorno;

}Digitos;

int verificaVaretas(int var1, int var2, int var3);
int menu();
// entrada: 1-2-3-4
Digitos validaEntrada(char entrada[]);

int verificaVaretas(int var1, int var2, int var3){

    // a < b + c
    // b < a + c
    // c < a + b

    if( (var1 > var2 + var3) ||
        (var2 > var1 + var3) ||
        (var3 > var2 + var1) ){
            return 0;
        }


    return 1;

}


int menu(){

    int escolha;
    printf("1. Verificar Varetas\n2. Sair\n");
    scanf("%d", &escolha);

    system("cls");
    if(escolha > 2 || escolha < 1){
        while(1){
            printf("Tente Novamente\n\n");
            printf("1. Verificar Varetas\n2. Sair\n");
            scanf("%d", &escolha);

            if(escolha == 1 || escolha == 2){
                break;
            }
            system("cls");
        }

    }

    if(escolha == 1){
        char varetas[8];
        printf("varetas");
        scanf("%s", varetas);

        Digitos valores = validaEntrada(varetas);

        if(valores.retorno = 0){
            return 0;
        }else{

            // a b c d
            // abc - abd - bcd - cda

            int dig1 = valores.arrayValores[0];
            int dig2 = valores.arrayValores[1];
            int dig3 = valores.arrayValores[2];
            int dig4 = valores.arrayValores[3];

            if(verificaVaretas(dig1, dig2, dig3) ||
               verificaVaretas(dig1, dig2, dig4) ||
               verificaVaretas(dig2, dig3, dig4) ||
               verificaVaretas(dig3, dig4, dig1) ){

                return 1;

               }
            

            return 2;

        }

    }else{
        return 3;
    }
}

Digitos validaEntrada(char entrada[]){
    Digitos valores;
    int j = 0;
    if(entrada[0] == '-'){
        valores.retorno = 0;
        return valores;
    }

    for(int i = 0; entrada[i] != '\0'; i++){
        if(entrada[i] != '-'){
            valores.arrayValores[j] = entrada[i] + 0;
            j++;
        }

    }

    valores.retorno = 1;
    return valores;

}


int main(){
    while(1){
        int saida = menu();
        system("cls");
        if(saida == 0){
            printf("entrada invalida\n");
        }else if(saida == 1){
            printf("forma um tri\n");
        }else if(saida == 2){
            printf("entrada invalida\n");
        }else{
            printf("saindo\n");
            break;
        }

        

    }

    return 0;
}