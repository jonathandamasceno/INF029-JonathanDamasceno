#include <stdio.h>
#include <stdlib.h>

/*
atividade simplificada presumindo muitas coisas

1 - ano tem que ser entre 1900 e 2025
2 - chassi com 3 digitos
3 - maximo de carros na lista = 50

obs.: não guarda os dados em nenhum arquivo (temporário)
      pode ser feito usando .txt ou .json pra guardar a lista

*/


int main(){
    int sair = 0, i=0;

    struct Carro{
        int ano;
        int chassi;
    };

    struct Carro lista[50];

    while(!sair){
        int escolha;

        printf("\n1 - Cadastrar Veiculo\n"
               "2 - Ver Veiculos\n"
               "3 - Sair\n> ");
            
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            while(1){
                int ano;
                int chassi;

                printf("ano(1900 - 2025), chassi(100 - 999)\n\n");

                printf("ano: ");
                scanf("%d", &ano);

                printf("chassi: ");
                scanf("%d", &chassi);

                if((ano < 2026 && ano >= 1900) && (chassi > 99 && chassi < 1000)){
                    if(i == 50){
                        printf("limite de carros alcancado");
                    }else{

                        struct Carro carro;
                        carro.ano = ano;
                        carro.chassi = chassi;

                        lista[i] = carro;
                        i++;
                    }

                    break;
                }
                printf("\ndados invalidos\n");
            }

            break;
        case 2:
            system("cls");
            for(int j=0; j < i; j++){
                printf("carro %d {\n", j+1);

                printf("    ano: %d\n", lista[j].ano);
                printf("    chassi: %d\n", lista[j].chassi);
                printf("}\n");
            }

            break;

        case 3:
            sair = 1;
            break;

        default:
            printf("\nopcao invalida\n");
            break;
        }

    }

}