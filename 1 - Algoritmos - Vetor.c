#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Arquivo.h"
#include "Algoritimos.h"

void menu1(){
	printf("\n***Menu 1***");
	printf("\n s-Sair");
	printf("\n c-Crescente");
	printf("\n d-Decrescente");
	printf("\n r-Aleatorio");
	//printf("\nt-Todos");
}

void menu2(){
	printf("\n***Menu 2***");
	printf("\n 0-Sair");
	printf("\n 1-Entrada de 10");
	printf("\n 2-Entrada de 100");
	printf("\n 3-Entrada de 1.000");
	printf("\n 4-Entrada de 10.000");
	printf("\n 5-Entrada de 100.000");
	printf("\n 6-Entrada de 1.000.000");
}

void Operacao(int tipo,int  tamanho,char urlEntrada[],char urlSaida[],char urlTempo[]){
	//DECLARAÇÃO DE VARIAVEL
	FILE *arquivo;
	float inicio,final,tempo;
	int *vetor,i,num;
	vetor = (int *) malloc((tamanho+1) * sizeof(int));
	//salvar o arquivo de entrada
	printf("\nGerando entrada aguarde...\n");
	
	//if(!arquivo){
		switch(tipo){
			case 1:
				entradacrescente(urlEntrada,tamanho);	
				break;
			case 2:
				entradadecrescente(urlEntrada,tamanho);
				break;
			case 3:
				entradarandom(urlEntrada,tamanho);
				break;
			default:
				printf("ERRO 404!");
		}
	//}
	printf("Gerando vetor aguarde...\n");
	arquivo = fopen(urlEntrada,"r");
	if(arquivo == NULL){
			printf("Erro, nao foi possivel abrir o arquivo\n");
			system("pause");
			return ;
	}
	
	//pega o arquivo
	i=0;
	while((fscanf(arquivo,"%d", &num)) != EOF){
		 vetor[i] = num;
		 //printf("%d\n",vetor[i]);
		i++;
	}
	fclose(arquivo);
	
	//Reordena
	for(i=1; i <= tamanho ; i++){
		vetor[i-1] = vetor[i]; 
	}
	
	//pegar o vetor ordenar
	printf("Ordenando vetor aguarde...\n\n");
	inicio = clock();
	printf("Tempo Inicial: %.2f\n",inicio);
	//Trabalho1
	//insertionSort(vetor,tamanho);
	//selectionSort(vetor,tamanho);
	//bubleSort(vetor,tamanho);
	
	//Trabalho2
	//mergeSort(vetor,0,tamanho);
	//combsort(vetor,tamanho);
	
	//Trabalho3
	//qsortPrimeiro(vetor, 0, tamanho);
	//qsortCentral(vetor, 0, tamanho);
	//qsortParcial(vetor, 0, tamanho,tamanho/2);
	
	//shellsort(vetor,tamanho);
	heapsort(vetor,tamanho);
	
	final = clock();
	printf("Tempo Final: %.2f\n",final);
	tempo = (final - inicio) / (double) CLOCKS_PER_SEC;
	printf("Tempo Decorrido: %.5f\n\n",tempo);
	//criar o arquivo de saida
	printf("Gravando saida aguarde...\n");
	gravaSaida(urlSaida,vetor,tamanho);
	
	// criar o arquivo de tempo
	printf("Gravando tempo aguarde...\n");
	gravaTempo(urlTempo,tempo);
	
	free(vetor);
}

void optTamanho(int tipo){
	int opcao;
	char urlEntrada[80],urlSaida[80],urlTempo[80];
	
	switch(tipo){
		case 1:
			strcpy( urlEntrada, "arquivodeentrada/crescente/entradacrescente");
			strcpy( urlSaida  , "arquivodesaida/crescente/saidacrescente");
			strcpy( urlTempo  , "arquivodetempo/crescente/tempocrescente");
			break;
		case 2:
			strcpy( urlEntrada, "arquivodeentrada/decrescente/entradadecrescente");
			strcpy( urlSaida  , "arquivodesaida/decrescente/saidadecrescente");
			strcpy( urlTempo  , "arquivodetempo/decrescente/tempodecrescente");
			break;
		case 3:
			strcpy( urlEntrada, "arquivodeentrada/random/entradarandom");
			strcpy( urlSaida  , "arquivodesaida/random/saidarandom");
			strcpy( urlTempo  , "arquivodetempo/random/temporandom");
			break;
		default:
				printf("ERRO 404!");
	}
	
	menu2();
	printf("\n\nDigite uma opcao valida: ");
	scanf("%d", &opcao);
	switch(opcao){
		case 0: 
			return;
		case 1:
			Operacao(tipo,10, strcat(urlEntrada,"10.txt"), strcat(urlSaida,"10.txt"), strcat(urlTempo,"10.txt"));
			break;
		case 2:
			Operacao(tipo,100, strcat(urlEntrada,"100.txt"), strcat(urlSaida,"100.txt"), strcat(urlTempo,"100.txt"));
			break;
		case 3:
			Operacao(tipo,1000, strcat(urlEntrada,"1000.txt"), strcat(urlSaida,"1000.txt"), strcat(urlTempo,"1000.txt"));
			break;
		case 4:
			Operacao(tipo,10000, strcat(urlEntrada,"10000.txt"), strcat(urlSaida,"10000.txt"), strcat(urlTempo,"10000.txt"));
			break;
		case 5:
			Operacao(tipo,100000, strcat(urlEntrada,"100000.txt"), strcat(urlSaida,"100000.txt"), strcat(urlTempo,"100000.txt"));
			break;
		case 6:
			Operacao(tipo,1000000, strcat(urlEntrada,"1000000.txt"), strcat(urlSaida,"1000000.txt"), strcat(urlTempo,"1000000.txt"));
			break;
		default:
			printf("ERRO 404!");
	}
}

int main(){
	int i;
	char opcao;
	do{
		menu1();
		printf("\n\nDigite uma opcao valida: ");
		scanf("%c", &opcao);
		switch(opcao){
			case 's':
				return;
			case 'c': 
				optTamanho(1);
				break;
			case 'd': 
				optTamanho(2);
				break;
			case 'r': 
				optTamanho(3);
				break;
			case 't': 
				optTamanho(4);
				break;
			default:
				printf("ERRO 404!");	
		}
	}while(1);
}

