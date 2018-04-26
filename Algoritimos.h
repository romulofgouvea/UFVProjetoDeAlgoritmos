void trocarPosicaoValores( int *posicaoA, int *posicaoB ) {
    int temporario;
	temporario = *posicaoA;
	*posicaoA = *posicaoB;
    *posicaoB = temporario;
}

void insertionSort(int original[], int length ) {
	int i, j, atual;
	for (i = 1; i < length; i++){
		atual = original[i];
		j = i - 1;
		while ((j >= 0) && (atual < original[j])){
			original[j + 1] = original[j];
            j = j - 1;
		}
		original[j + 1] = atual;
	}
}

void selectionSort( int vetorDesordenado[], int tamanhoVetor ){
   int i, j, posicaoValorMinimo;
   for (i = 0; i < ( tamanhoVetor - 1 ); i++)
   {
      posicaoValorMinimo = i;
      for (j = ( i + 1 ); j < tamanhoVetor; j++)
      {
         if( vetorDesordenado[j] < vetorDesordenado[posicaoValorMinimo] )
         {
           posicaoValorMinimo = j;
         }
       }

       if ( i != posicaoValorMinimo )
       {
          trocarPosicaoValores( &vetorDesordenado[i], &vetorDesordenado[posicaoValorMinimo] );
       }
   }
}

void bubleSort( int vetorDesordenado[], int tamanhoVetor ) {
    int i, j;
	for( i = 0; i < ( tamanhoVetor -1 );  i++ ){
	    for( j=0; j <( tamanhoVetor -( i +1 ) ); j++ ) {
		   if( vetorDesordenado[j] > vetorDesordenado[j+1] ){
		   		trocarPosicaoValores( &vetorDesordenado[j], &vetorDesordenado[j+1] );
		   }
		}
	}
}

void mergeSort(int *vetor, int posicaoInicio, int posicaoFim) {
    int i, j, k, metadeTamanho, *vetorTemp;

    if(posicaoInicio == posicaoFim) return;

    // ordenacao recursiva das duas metades
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;
    mergeSort(vetor, posicaoInicio, metadeTamanho);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim);

    // intercalacao no vetor temporario t
    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));

    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        if (i == metadeTamanho + 1 ) { // i passou do final da primeira metade, pegar v[j]
            vetorTemp[k] = vetor[j];
            j++;
            k++;
        }
        else {
            if (j == posicaoFim + 1) { // j passou do final da segunda metade, pegar v[i]
                vetorTemp[k] = vetor[i];
                i++;
                k++;
            }
            else {
                if (vetor[i] < vetor[j]) {
                    vetorTemp[k] = vetor[i];
                }
                else {
                    vetorTemp[k] = vetor[j];
                }
                j++;
                k++;
            }
        }

    }
    // copia vetor intercalado para o vetor original
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        vetor[i] = vetorTemp[i - posicaoInicio];
    }
    free(vetorTemp);
}

void combsort(int *arr, int size) {
    float shrink_factor = 1.247330950103979;
    int gap = size, swapped = 1, swap, i;

    while ((gap > 1) || swapped) {
        if (gap > 1)
           gap = gap / shrink_factor;

        swapped = 0;
        i = 0;

        while ((gap + i) < size) {
            if (arr[i] - arr[i + gap] > 0) {
                swap = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = swap;
                swapped = 1;
            }
            ++i;
        }
    }
}

void qsortPrimeiro(int *vet, int inicio, int fim){
	//implementação em C, para o algoritmo que considera o primeiro elemento como pivô.
   /* inicia os indices */
	int i = inicio;
	int j = fim;
	int tmp;
	/* verifica se ainda é necessário a ordenacao (> 2 elementos)  */
	if (i >= j)
   {
	    return;
	}
	/*  considera o primeiro elemento como pivo*/
	int pivo = vet[inicio];
	/* 'corre' todo o vetor até que os indices se encontrem */
	while (i < j) 
   {
      /* 'procura' por um elemento menor ou igual ao pivo*/
	    while (i<j && vet[i] < pivo) { i++; }
  	 /* 'procura' por um elemento maior ou igual ao pivo*/
	    while (i<j && vet[j] > pivo) { j--; }
      /* troca os elementos encontrados se os indices nao tivem se cruzado*/
	    if (i < j)                           
       {
		    tmp= vet[i];
		    vet[i] = vet[j];
		    vet[j] = tmp;
		    i++;
		    j--;
	    }
	}
	/* se os indices se cruzaram, reorganiza os indices*/
	if (j < i)
   {
	    tmp = j;
	    j = i;
	    i = tmp;
	}
	/* ordernar o subvetor da esquerda */
	qsortPrimeiro(vet, inicio, i);
	/* se o pivo escolhido era o primeiro elemento, ordena os demais à direita*/
	if(i == inicio)
	{
      qsortPrimeiro(vet,i+1,fim);
   }
   else
   {
    /* ordena o subvetor a direta*/
     qsortPrimeiro(vet,i,fim);
   }
}

void qsortCentral(int *vet, int inicio, int fim){
	//implementação em C, para o algoritmo que considera o elemento central como pivô.
   /* inicia os indices */
	int i = inicio;
	int j = fim;
	int tmp;
	/* verifica se ainda é necessário a ordenacao (> 2 elementos)  */
	if (i >= j)
   {
	    return;
	}
	/*  considera o elemento central como pivo*/
	int pivo = vet[(int)(inicio+fim)/2];
	/* 'corre' todo o vetor até que os indices se encontrem */
	while (i < j) 
   {
        /* 'procura' por um elemento menor ou igual ao pivo*/
	    while (i<j && vet[i] < pivo) { i++; }
		/* 'procura' por um elemento maior ou igual ao pivo*/
	    while (i<j && vet[j] > pivo) { j--; }
      /* troca os elementos encontrados se os indices nao tivem se cruzado*/
	    if (i < j)                           
       {
		    tmp= vet[i];
		    vet[i] = vet[j];
		    vet[j] = tmp;
		    i++;
		    j--;
	    }
	}
	/* se os indices se cruzaram, reorganiza os indices*/
	if (j < i)
   {
	    tmp = j;
	    j = i;
	    i = tmp;
	}
	/* ordernar o subvetor da esquerda */
	qsortCentral(vet, inicio, i);
	/* se o pivo escolhido era o primeiro elemento, ordena os demais à direita*/
	if(i == inicio)
	{
      qsortCentral(vet,i+1,fim);
   }
   else
   {
    /* ordena o subvetor a direta*/
     qsortCentral(vet,i,fim);
   }
}

void qsortParcial(int *vet, int inicio, int fim,int k){
	//implementação em C, para o algoritmo de ordenação parcial que considera o elemento central como pivô.
   /* inicia os indices */
	int i = inicio;
	int j = fim;
	int tmp;
	/* verifica se ainda é necessário a ordenacao (> 2 elementos)  */
	if (i >= j)
   {
	    return;
	}
	/*  considera o elemento central como pivo*/
	int pivo = vet[(int)(inicio+fim)/2];
	/* 'corre' todo o vetor até que os indices se encontrem */
	while (i < j) 
   {
        /* 'procura' por um elemento menor ou igual ao pivo*/
	    while (i<j && vet[i] < pivo) { i++; }
		/* 'procura' por um elemento maior ou igual ao pivo*/
	    while (i<j && vet[j] > pivo) { j--; }              
      /* troca os elementos encontrados se os indices nao tivem se cruzado*/
	    if (i < j)                           
       {
		    tmp= vet[i];
		    vet[i] = vet[j];
		    vet[j] = tmp;
		    i++;
		    j--;
	    }
	}
	/* se os indices se cruzaram, reorganiza os indices*/
	if (j < i)
   {
	    tmp = j;
	    j = i;
	    i = tmp;
	}
	/* ordernar o subvetor da esquerda */
	qsortParcial(vet, inicio, i,k);
	/* ordena se ainda não foram ordenados k elementos */
	if(i < k)
	{
	  /* se o pivo escolhido era o primeiro elemento, ordena os demais à direita*/
	   if(i == inicio)
	   {
         qsortParcial(vet,i+1,fim,k);
      }
      else
      {
      /* ordena o subvetor a direta*/
      qsortParcial(vet,i,fim,k);
      }
   }
}

void shellsort(int* vetor, int n){ 
    int i, j; 
    int h = 1; 
    int x; 
     
    do{  
       h = h * 3 + 1; 
    }while(h < n); 
     
    do{ 
       h /= 3; 
        for(i = h; i < n; i++){ 
            x = vetor[i]; 
            j = i - h; 
            while(j >= 0 && vetor[j] > x){ 
               vetor[j + h] = vetor[j]; 
               j -= h; 
            } 
            vetor[j + h] = x; 
        } 
    }while(h != 1);   
}  

int max (int *a, int n, int i, int j, int k) {
    int m = i;
    if (j < n && a[j] > a[m]) {
        m = j;
    }
    if (k < n && a[k] > a[m]) {
        m = k;
    }
    return m;
}
 
void downheap (int *a, int n, int i) {
    while (1) {
        int j = max(a, n, i, 2 * i + 1, 2 * i + 2);// usei 2 * i + 1 porque meu vetor começa de 0
        if (j == i) {
            break;
        }
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
        i = j;
    }
}
 
void heapsort (int *a, int n) {
    int i;
    for (i = (n - 2) / 2; i >= 0; i--) {
        downheap(a, n, i);
    }
    for (i = 0; i < n; i++) {
        int t = a[n - i - 1];
        a[n - i - 1] = a[0];
        a[0] = t;
        downheap(a, n - i - 1, 0);
    }
}
