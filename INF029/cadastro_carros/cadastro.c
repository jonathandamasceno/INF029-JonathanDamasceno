#include <stdio.h>
#include <stdlib.h>
#define MAX 3

/*

obs2.: não guarda os dados em nenhum arquivo (temporário)
      pode ser feito usando .txt ou .json pra guardar a lista

*/

int main(){
    int sair = 0, qtdCarros=0;

    struct Carro{
        int ano;
        int chassi;
    };

    struct Carro lista[MAX];

    while(!sair){
        int escolha;

        printf("\n1 - Cadastrar Veiculo\n"
               "2 - Ver Veiculos\n"
               "3 - Atualizar\n"
               "4 - Deletar\n"
               "5 - Sair\n> ");
            
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            while(1){
                int ano;
                int chassi;

                printf("ano: ");
                scanf("%d", &ano);

                printf("chassi: ");
                scanf("%d", &chassi);

                
                if(qtdCarros == MAX){
                    printf("limite de carros alcancado");
                }else{

                    struct Carro carro;
                    carro.ano = ano;
                    carro.chassi = chassi;

                    lista[qtdCarros] = carro;
                    qtdCarros++;
                }

                break;
            }
            
            break;

        case 2:

            for(int j=0; j < qtdCarros; j++){
                printf("carro %d {\n", j+1);

                printf("    ano: %d\n", lista[j].ano);
                printf("    chassi: %d\n", lista[j].chassi);
                printf("}\n");
            }

            break;

        case 3:
            for(int j=0; j < qtdCarros; j++){
                printf("carro %d: {\n", j+1);

                printf("    ano: %d\n", lista[j].ano);
                printf("    chassi: %d\n", lista[j].chassi);
                printf("}\n");
            }

            while(1){
                int carroEscolhido;
                printf("escolha o carro para ser modificado\n\n");
                scanf("%d", &carroEscolhido);

                if(carroEscolhido <= qtdCarros || carroEscolhido >= 1){
                    printf("ano: ");
                    scanf("%d", &lista[carroEscolhido -1].ano);

                    printf("chassi: ");
                    scanf("%d", &lista[carroEscolhido -1].chassi);

                    break;
                }
                printf("opcao invalida\n\n");

            }
            break;
        
        case 4:
            if(qtdCarros == 0){
                printf("Sem carros cadastrados");
                break;
            } 
            qtdCarros--;
            break;
        
        case 5:
            sair = 1;
            break;
        
        default:
            printf("\nopcao invalida\n");
            break;
        }

    }

}