void entradacrescente(char url[], int tamanho){
	int i,num;
	FILE *arquivo;
	arquivo = fopen(url,"w");

	if(arquivo == NULL){
			printf("Erro, nao foi possivel abrir o arquivo\n");
			system("pause");
			return;
	}

	fprintf(arquivo,"%d\n", tamanho);

	for(i=0 ; i<tamanho ; i++){
		fprintf(arquivo,"%d\n", i);
	}

	fclose(arquivo);
}

void entradadecrescente(char url[], int tamanho){
	int i,num;
	FILE *arquivo;
	arquivo = fopen(url,"w");

	if(arquivo == NULL){
			printf("Erro, nao foi possivel abrir o arquivo\n");
			system("pause");
			return;
	}

	fprintf(arquivo,"%d\n", tamanho);

	for(i=tamanho-1 ; i >= 0 ; i--){
		fprintf(arquivo,"%d\n", i);
	}

	fclose(arquivo);
}

void entradarandom(char url[], int tamanho){
	int i,num;
	FILE *arquivo;
	arquivo = fopen(url,"w");

	if(arquivo == NULL){
			printf("Erro, nao foi possivel abrir o arquivo\n");
			system("pause");
			return;
	}

	fprintf(arquivo,"%d\n", tamanho);

	for(i=0;i<tamanho;i++){
		num = rand() % tamanho;
		fprintf(arquivo,"%d\n", num);
	}

	fclose(arquivo);
}

void gravaTempo(char url[], float tempo){
	FILE *arquivo;
	arquivo = fopen(url,"w");
	if(arquivo == NULL){
		printf("Erro, nao foi possivel abrir o arquivo\n");
		system("pause");
		return;
	}
	fprintf(arquivo,"%.5f\n", tempo);
	fclose(arquivo);
}

void gravaSaida(char url[], int vetor[], int tamanho){
	int i;
	FILE *arquivo;
	arquivo = fopen(url,"w");
	if(arquivo == NULL){
		printf("Erro, nao foi possivel abrir o arquivo\n");
		system("pause");
		return ;
	}

	for(i=0 ; i < tamanho ; i++){
		fprintf(arquivo,"%d\n", vetor[i]);
	}
	fclose(arquivo);
}
