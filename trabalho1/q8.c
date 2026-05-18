#include <stdio.h>
#include <stdlib.h>
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

int verificaGanhou(char lista[TAM][TAM], int nJogadas){
    int achou = 0;
    int j1 = 0, j2 = 0;

    // verifica na horizontal
    for(int iCont=0; iCont < TAM; iCont++){
        j1 = 0, j2 = 0;
        for(int jCont=0; jCont < TAM; jCont++){ 
            if(lista[iCont][jCont] == 'X'){
                j1++;
            }
            if(lista[iCont][jCont] == 'O'){
                j2++;
            }
        }

        // validando se ganhou
        if(j1 == 3){
            return 1;
        }else if(j2 == 3){
            return 2;
        }
    }

    // verifica na vertical
    for(int iCont=0; iCont <TAM; iCont++){
        j1 = 0, j2 = 0;
        for(int jCont=0; jCont<TAM; jCont++){

            if(lista[jCont][iCont] == 'X'){
                j1++;
            }
            if(lista[jCont][iCont] == 'O'){
                j2++;
            }
        }
        
        
        // validando se ganhou
        if(j1 == 3){
            return 1;
        }else if(j2 == 3){
            return 2;
        }
    }

    // diagonal
    j1 = 0, j2 = 0;
    for(int iCont = 0; iCont < TAM; iCont++){
        if(lista[iCont][iCont] == 'X'){
            j1++;
        }
        if(lista[iCont][iCont] == 'O'){
            j2++;
        }
    }
    if(j1 == 3){
        return 1;
    }else if(j2 == 3){
        return 2;
    }

    // contraria
    int aux = TAM - 1;
    j1 = 0, j2 = 0;
    for(int iCont = 0; iCont < TAM; iCont++){
        if(lista[iCont][aux] == 'X'){
            j1++;
        }
        if(lista[iCont][aux] == 'O'){
            j2++;
        }
        aux--;
    }

    if(j1 == 3){
        return 1;
    }else if(j2 == 3){
        return 2;
    }

    if(nJogadas == 9){
        return 3;
    }

    return 0;
}

int main(){


    // inicia o tabuleiro
    char cerquilha[TAM][TAM] = {{' ', ' ', ' '},
                                {' ', ' ', ' '},
                                {' ', ' ', ' '}};

    int ganhou = 0, player = 1, nJogadas =0;
    char jogadores[2] = {'X','O'};
    mostraTabuleiro(cerquilha);
    while(!verificaGanhou(cerquilha, nJogadas)){ // loop do jogo
        char letra;
        int num = 0;
        printf("jogador %d\nescolha: ", player);
        scanf(" %c %d", &letra, &num);
        system("cls");
        if(validaJogada(letra, num, cerquilha)){
            // tem que mudar por aqui tambem
            if(letra >= 'a' && letra <= 'c'){
                letra -= 32;
            }
            // coloca a opção na casa
            cerquilha[letra - 'A'][num-1] = jogadores[player-1];
            nJogadas++;
            // pra ficar indo e voltando o numero do jogador
            if(player % 2 == 0){
                player -= 1;
            }else{
                player += 1;
            }
        }else{
            printf("jogada invalida, escolha novamente:\n");
        }

        mostraTabuleiro(cerquilha);
    }
    int ganhador = verificaGanhou(cerquilha, nJogadas);
    if(ganhador == 3){
        printf("Empate");
    }else{
        printf("\n--------------------\nganhador: jogador %d\n--------------------\n", ganhador);
    }
    
}