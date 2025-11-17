#include <stdio.h>
#define TAM 3
// questão jogo da velha

void mostraTabuleiro(char lista[TAM][TAM]){
    // mostra o tabuleiro na tela

    // linha
    char nLinha = 'A';

    // arrumação do tabuleiro
    printf("\n ");
    for(int iCont = 0; iCont < TAM; iCont++, nLinha++){
        if(iCont == 0){
            for(int jCont = 0; jCont < TAM; jCont++){
                printf("   %d", jCont+1);
            }
        }
        printf("\n");

        for(int jCont = 0; jCont < TAM; jCont++){
            if(jCont == 0){
                printf("%c  ", nLinha);
            }
            printf(" %c", lista[iCont][jCont]);
            if(jCont < 2){
                printf(" |");
            }
        }
        printf("\n");
        if(iCont < 2){
            for(int kCont =0; kCont < 5; kCont++){
                if(kCont == 0){
                    printf("   ");
                }
                printf(" -");  
            }
        }
    }

}

int validaJogada(char letra, int num, char lista[TAM][TAM]){
    if(letra >= 'a' && letra <= 'c'){
        letra -= 32; // caso mande minuscula
    }
 
    if((letra >= 'A' && letra <= 'C') && (num >= 1 && num <= 3)){
        if(lista[letra - 'A'][num - 1] == ' '){
            return 1; // sim ✔️
        }
    }

    return 0; // nao ❌
}

int main(){


    // inicia o tabuleiro
    char cerquilha[TAM][TAM] = {{' ', ' ', ' '},
                                {' ', ' ', ' '},
                                {' ', ' ', ' '}};

    int ganhou = 0, player = 1;
    char jogadores[2] = {'X','O'};
    
    while(1){ // loop do jogo
        char letra;
        int num = 0;
        printf("jogador %d\nescolha: ", player);
        scanf(" %c %d", &letra, &num);
        if(validaJogada(letra, num, cerquilha)){
            if(letra >= 'a' && letra <= 'c'){
                letra -= 32;
            }
            cerquilha[letra - 'A'][num-1] = jogadores[player-1];
        }else{
            printf("jogada invalida\n");
        }

        // pra ficar indo e voltando o numero do jogador
        if(player % 2 == 0){
            player -= 1;
        }else{
            player += 1;
        }


        mostraTabuleiro(cerquilha);
    }
    
}