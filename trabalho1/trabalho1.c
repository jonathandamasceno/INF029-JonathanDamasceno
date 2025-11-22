// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Jonathan Damasceno de Araujo
//  email: contato.jonathandamasceno@gmail.com
//  Matrícula: 20251160031
//  Semestre: 2025.2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 21/11/2025

// #################################################

#include <stdio.h>
#include "trabalho1.h" 
#include <stdlib.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */

int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
   int datavalida = 1;

   int iDia = quebraData(data).iDia;
   int iMes = quebraData(data).iMes;
   int iAno = quebraData(data).iAno;

   //quebrar a string data em strings sDia, sMes, sAno
   int diaCadaMes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

   if(iDia < 1 || iDia > 31) return 0;
   if(iMes < 1 || iMes > 12) return 0;
   if(iAno < 1900 || iAno > 2025) return 0;

   // se o ano for bissexto -> fev tem 29 dias
   if(iMes == 2 && ((iAno % 400 == 0) || (iAno % 4 == 0 && iAno % 100 != 0))){
         return (iDia >= 1 && iDia <= 29);
   }

   datavalida = iDia <= diaCadaMes[iMes - 1] && iDia >= 1;

   return datavalida;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

   //calcule os dados e armazene nas três variáveis a seguir
   DiasMesesAnos dma;

   if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
   }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
   }else{
      //verifique se a data final não é menor que a data inicial

      DataQuebrada ini = quebraData(datainicial);
      //
      DataQuebrada fim = quebraData(datafinal);

      if(ini.iAno > fim.iAno){
         dma.retorno = 4;
         return dma;
      }else if(ini.iAno == fim.iAno){
         if((ini.iMes > fim.iMes) || ((ini.iMes == fim.iMes) && ini.iDia > fim.iDia)){
            dma.retorno = 4;
            return dma;
         }
      }

      //calcule a distancia entre as datas
      int diaCadaMes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
      dma.qtdAnos = fim.iAno - ini.iAno;
      dma.qtdMeses = fim.iMes - ini.iMes;
      dma.qtdDias = fim.iDia - ini.iDia;

      // printf("(%d - %d - %d)\n", dma.qtdDias, dma.qtdMeses, dma.qtdAnos);
      // se tudo der certo
      dma.retorno = 1;
      return dma;
      
   }
    
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
   int qtdOcorrencias = 0;
   
   for (int i = 0; texto[i] != '\0'; i++) {
       if (isCaseSensitive == 1) {
           if (texto[i] == c)
               qtdOcorrencias++;
       } else {
            char temp_txt = texto[i], temp_c = c;
            if(texto[i] >= 'A' && texto[i] <= 'Z'){
               temp_txt = texto[i] + 32;
            }

            if(c >= 'A' && c <= 'Z'){
               temp_c = c + 32;
            }

            if (temp_c == temp_txt){
               qtdOcorrencias++;
            }
       }
   }

   return qtdOcorrencias;  
}
/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{

   int qtdOcorrencias = 0;
   int iCont = 0, jCont = 0, kCont = 0;
   int primeiraOcorrencia=0, ultimaOcorrencia=0, achou = 1;
   int posIndice = 0;

   for(iCont = 0; strTexto[iCont] != '\0'; iCont++){
      if(strTexto[iCont] == strBusca[0]){
         jCont = iCont;
         kCont = 0;
         achou = 1;
         while(strBusca[kCont] != '\0'){
            
            if(strTexto[jCont] != strBusca[kCont]){
               achou = 0;
               break;
            }
            kCont++;
            jCont++;
         }
         ultimaOcorrencia = jCont;
 
         if(achou == 1){
            posicoes[posIndice] = iCont + 1;
            posIndice++;
            posicoes[posIndice] = ultimaOcorrencia;
            posIndice++;
            // printf("oc: %d = (p: %d u: %d)\n", qtdOcorrencias+1, iCont + 1, ultimaOcorrencia); debug
            qtdOcorrencias++;
         }
      }
   }
   return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{

   int digito, iCont = 0, jCont = 0;
   int numeros[10], aux = 1; // variavel aux pra fazer a multiplicação

   // separa os digitos e coloca num array
   while(num != 0){
      digito = (num % 10);
      numeros[iCont] = digito;
      iCont++; // pra saber quantos digitos tem
      num = num / 10;
   }

   num = 0; // zera o num pra colocar o novo valor
   for(jCont = iCont-1; jCont >=0; jCont--){ // faz o caminho de trás pra frente
      num = num + numeros[jCont] * aux; // multiplico 1, 10, 100, 1000...
      aux = aux * 10; // variavel que faz isso
   }  

   return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
   int qtdOcorrencias=0;

   int digito, iCont = 0, jCont = 0, kCont = 0, achou = 1, aux=0;
   int numerosBase[15], numerosBusca[15];

   
   while(numerobase != 0){
      digito = (numerobase % 10);
      numerosBase[iCont] = digito;
      // printf("%d ", numerosBase[iCont]);
      iCont++; // pra saber quantos digitos tem
      numerobase = numerobase / 10;
   }

   while(numerobusca != 0){
      digito = (numerobusca % 10);
      numerosBusca[jCont] = digito;
      jCont++; // pra saber quantos digitos tem
      numerobusca = numerobusca / 10;
   }

   for(kCont = 0; kCont <= iCont - jCont; kCont++){
      achou = 1;
      for(aux = 0; aux < jCont; aux++){
         if(numerosBase[kCont + aux] != numerosBusca[aux]){
            achou = 0;
            break;
         }
      }
      if(achou == 1){
         qtdOcorrencias++;
      }
   }

   return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

 int q7(char matriz[8][10], char palavra[5])
 {

      int achou = 0;
      int lenPalavra;
      int iCont, jCont, kCont;

      for(lenPalavra=0; palavra[lenPalavra]; lenPalavra++);
      char palavraInvertida[lenPalavra];

      // invertendo e colocando em outra string
      for(int c = lenPalavra - 1, aux=0; c >= 0; c--, aux++){
         palavraInvertida[aux] = palavra[c];
      }


      // horizontal
      // esquerda -> direita || direita -> esquerda (pode estar invertida)
      achou = 0;
      for(iCont=0; iCont < 8; iCont++){
         for(jCont=0; jCont<10; jCont++){
            if(matriz[iCont][jCont] == palavra[0] || matriz[iCont][jCont] == palavraInvertida[0]){
               kCont = 0;
               for(kCont=0; kCont < lenPalavra; kCont++){
                  // nao sai do limite da matriz
                  if(jCont + kCont >= 10){
                     break;
                  }

                  if(matriz[iCont][jCont+kCont] != palavra[kCont] && matriz[iCont][jCont+kCont] != palavraInvertida[kCont]){
                     break;
                  }
               }

               if(kCont == lenPalavra){
                  achou = 1;
                  break;
               }
            }  
         }
      }

      // vertical 
      // cima -> baixo, baixo -> cima
      kCont = 0;
      for(iCont=0; iCont < 8; iCont++){ // 0
         for(jCont=0; jCont<10; jCont++){ // 00 01
            if(matriz[iCont][jCont] == palavra[0] || matriz[iCont][jCont] == palavraInvertida[0]){
               kCont = 0;
               for(kCont=0; kCont < lenPalavra; kCont++){
                  // nao sai do limite da matriz
                  if(iCont + kCont >= 8){
                     break;
                  }
                  if(matriz[iCont + kCont][jCont] != palavra[kCont] && matriz[iCont + kCont][jCont] != palavraInvertida[kCont]){
                     break;
                  }
               }
            }  
            if(kCont == lenPalavra){
               achou = 1;
               break;
            }
         }
      }
      /*------------------------------------------------------------------------------------------*/
      // diagonal direita -> esquerda
      kCont = 0;
      for(iCont=0; iCont < 8; iCont++){ // 0
         for(jCont=0; jCont<10; jCont++){ // 00 01
            if(matriz[iCont][jCont] == palavra[0] || matriz[iCont][jCont] == palavraInvertida[0]){
               kCont = 0;
               for(kCont=0; kCont < lenPalavra; kCont++){
                  // nao sai do limite da matriz
                  if(iCont + kCont >= 8 || jCont + kCont >= 10){
                     break;
                  }
                  if(matriz[iCont + kCont][jCont + kCont] != palavra[kCont] && 
                     matriz[iCont + kCont][jCont + kCont] != palavraInvertida[kCont]){
                     break;
                  }
               }
            }  
            if(kCont == lenPalavra){
               achou = 1;
               break;
            }
         }
      }
      /*------------------------------------------------------------------------------------------*/
      /*------------------------------------------------------------------------------------------*/
      // diagonal esquerda -> direita
      kCont = 0;
      for(iCont=0; iCont < 8; iCont++){ // 0
         for(jCont=0; jCont<10; jCont++){ // 00 01
            if(matriz[iCont][jCont] == palavra[0] || matriz[iCont][jCont] == palavraInvertida[0]){
               kCont = 0;
               for(kCont=0; kCont < lenPalavra; kCont++){
                  // nao sai do limite da matriz
                  if(iCont + kCont >= 8 || jCont - kCont < 0){
                     break;
                  }
                  if(matriz[iCont + kCont][jCont - kCont] != palavra[kCont] && 
                     matriz[iCont + kCont][jCont - kCont] != palavraInvertida[kCont]){
                     break;
                  }
               }
            }  
            if(kCont == lenPalavra){
               achou = 1;
               break;
            }
         }
      }
      /*------------------------------------------------------------------------------------------*/
      // caso passe
      return achou;
 }



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}
