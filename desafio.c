#include <windows.h>
#include <stdio.h>
#include <locale.h>
#include "classificacao.c"
#define QTLOOP 20

int * carregaNumero(int * tam, int test){
	int i = 0, n, *vetor, qt;
	
	FILE *arquivo;
	
	switch(test)
	{
		case 1:
			arquivo = fopen("arquivo300.txt", "r");
		break;
		case 2:
			arquivo = fopen("arquivo999.txt", "r");
		break;
		case 3:
			arquivo = fopen("arquivo9990.txt", "r");
		break;
		case 4:
			arquivo = fopen("arquivo20.txt", "r");
		break;
		case 5:
			arquivo = fopen("arquivo99900.txt", "r");
		break;
	}
	
	fscanf(arquivo, "%d\n", &qt);

	vetor = malloc (sizeof(int)*qt);
	
	while(!feof(arquivo)){
		fscanf(arquivo, "%d\n", &n);
		vetor[i] = n;
		i++;
	}
	
	fclose(arquivo);
	*tam = qt;
	return vetor;
	
}

void criaFile(char * fileName, int * vector){
	int i;
	
	FILE *arquivo;
	arquivo = fopen(fileName, "w");
	for(i = 0; i < QTLOOP; i++){
		fprintf(arquivo, "%i\n", vector[i]);
		
	}
	fclose(arquivo);
	
	printf("\nArquivo %s criado!\n", fileName);
	
}

void mediaPerformace(int * vetor, int * resultado){
	
	int mediaVetor = 0, i;
	
	for(i = 0; i < QTLOOP; i++){
		mediaVetor += vetor[i];
	}
	mediaVetor = mediaVetor / QTLOOP;
	
	*resultado = mediaVetor;
	
}



int main(){
	
	setlocale(LC_ALL, "");
	
	LARGE_INTEGER tempoInicial, tempoFinal;
	
	int tam, vetorBubble, vetorQuickSort, vetorSelectionSort, vetorInsertionSort, vetorMergeSort, tempo[QTLOOP], i, media;
	
	
	
	/*
	//BUBBLE SORT
	QueryPerformanceCounter(&tempoInicial);
	////codigo
	
	QueryPerformanceCounter(&tempoFinal);
		
	tempo = tempoFinal.QuadPart - tempoInicial.QuadPart;
	*/
	
	//vetorBubble = carregaNumero(&tam);
	//vetorQuickSort = carregaNumero(&tam);
	//vetorSelectionSort = carregaNumero(&tam);
	//vetorInsertionSort = carregaNumero(&tam);
	//vetorMergeSort = carregaNumero(&tam);
	
	
	/////////////////////300
	//bubble
	printf("BUBBLE SORT\n");
	printf("Carregando resultados\n");
	for(i = 0; i < QTLOOP; i++){
		vetorBubble = carregaNumero(&tam, 1);
		QueryPerformanceCounter(&tempoInicial);
		//gerando sort
		bubble(vetorBubble, tam);
		
		QueryPerformanceCounter(&tempoFinal);
		tempo[i] = tempoFinal.QuadPart - tempoInicial.QuadPart;
		
		printf(".");
	}	
	criaFile("bubblesort.txt", tempo);
	mediaPerformace(tempo, &media);
	printf("Média: %d\n", media);
	
	//quicksort
	printf("\nQUICK SORT\n");
	printf("Carregando resultados\n");
	for(i = 0; i < QTLOOP; i++){
		vetorQuickSort = carregaNumero(&tam, 1);
		QueryPerformanceCounter(&tempoInicial);
		//gerando sort
		quicksort(vetorQuickSort, 0, tam-1);
		
		QueryPerformanceCounter(&tempoFinal);
		tempo[i] = tempoFinal.QuadPart - tempoInicial.QuadPart;
		
		printf(".");
	}	
	criaFile("quicksort.txt", tempo);
	mediaPerformace(tempo, &media);
	printf("Média: %d\n", media);
	
	//selection
	printf("\nSELECTION SORT\n"); //*alterar o titulo
	printf("Carregando resultados\n");
	for(i = 0; i < QTLOOP; i++){
		vetorSelectionSort = carregaNumero(&tam, 1); //*alterar o vetor
		QueryPerformanceCounter(&tempoInicial);
		//gerando sort
		selection(vetorSelectionSort, tam);
		
		QueryPerformanceCounter(&tempoFinal);
		tempo[i] = tempoFinal.QuadPart - tempoInicial.QuadPart;
		
		printf(".");
	}	
	criaFile("selectionsort.txt", tempo); //*alterar o nome do arquivo
	mediaPerformace(tempo, &media);
	printf("Média: %d\n", media);
	
	//insertion
	printf("\nINSERTION SORT\n"); //*alterar o titulo
	printf("Carregando resultados\n");
	for(i = 0; i < QTLOOP; i++){
		vetorInsertionSort = carregaNumero(&tam, 1); //*alterar o vetor
		QueryPerformanceCounter(&tempoInicial);
		//gerando sort
		insertion(vetorInsertionSort, tam);
		
		QueryPerformanceCounter(&tempoFinal);
		tempo[i] = tempoFinal.QuadPart - tempoInicial.QuadPart;
		
		printf(".");
	}	
	criaFile("insertionSort.txt", tempo); //*alterar o nome do arquivo
	mediaPerformace(tempo, &media);
	printf("Média: %d\n", media);
	
	//mergeSort
	printf("\nMERGE SORT\n"); //*alterar o titulo
	printf("Carregando resultados\n");
	for(i = 0; i < QTLOOP; i++){
		vetorMergeSort = carregaNumero(&tam, 1); //*alterar o vetor
		QueryPerformanceCounter(&tempoInicial);
		//gerando sort
		mergeSort(vetorMergeSort, 0, tam-1);
		
		QueryPerformanceCounter(&tempoFinal);
		tempo[i] = tempoFinal.QuadPart - tempoInicial.QuadPart;
		
		printf(".");
	}	
	criaFile("mergesort.txt", tempo); //*alterar o nome do arquivo
	mediaPerformace(tempo, &media);
	printf("Média: %d\n", media);
	
	/////////////////////999
	//bubble
	printf("BUBBLE SORT\n");
	printf("Carregando resultados\n");
	for(i = 0; i < QTLOOP; i++){
		vetorBubble = carregaNumero(&tam, 2);
		QueryPerformanceCounter(&tempoInicial);
		//gerando sort
		bubble(vetorBubble, tam);
		
		QueryPerformanceCounter(&tempoFinal);
		tempo[i] = tempoFinal.QuadPart - tempoInicial.QuadPart;
		
		printf(".");
	}	
	criaFile("bubblesort2.txt", tempo);
	mediaPerformace(tempo, &media);
	printf("Média: %d\n", media);
	
	//quicksort
	printf("\nQUICK SORT\n");
	printf("Carregando resultados\n");
	for(i = 0; i < QTLOOP; i++){
		vetorQuickSort = carregaNumero(&tam, 2);
		QueryPerformanceCounter(&tempoInicial);
		//gerando sort
		quicksort(vetorQuickSort, 0, tam-1);
		
		QueryPerformanceCounter(&tempoFinal);
		tempo[i] = tempoFinal.QuadPart - tempoInicial.QuadPart;
		
		printf(".");
	}	
	criaFile("quicksort2.txt", tempo);
	mediaPerformace(tempo, &media);
	printf("Média: %d\n", media);
	
	//selection
	printf("\nSELECTION SORT\n"); //*alterar o titulo
	printf("Carregando resultados\n");
	for(i = 0; i < QTLOOP; i++){
		vetorSelectionSort = carregaNumero(&tam, 2); //*alterar o vetor
		QueryPerformanceCounter(&tempoInicial);
		//gerando sort
		selection(vetorSelectionSort, tam);
		
		QueryPerformanceCounter(&tempoFinal);
		tempo[i] = tempoFinal.QuadPart - tempoInicial.QuadPart;
		
		printf(".");
	}	
	criaFile("selectionsort2.txt", tempo); //*alterar o nome do arquivo
	mediaPerformace(tempo, &media);
	printf("Média: %d\n", media);
	
	//insertion
	printf("\nINSERTION SORT\n"); //*alterar o titulo
	printf("Carregando resultados\n");
	for(i = 0; i < QTLOOP; i++){
		vetorInsertionSort = carregaNumero(&tam, 2); //*alterar o vetor
		QueryPerformanceCounter(&tempoInicial);
		//gerando sort
		insertion(vetorInsertionSort, tam);
		
		QueryPerformanceCounter(&tempoFinal);
		tempo[i] = tempoFinal.QuadPart - tempoInicial.QuadPart;
		
		printf(".");
	}	
	criaFile("insertionSort2.txt", tempo); //*alterar o nome do arquivo
	mediaPerformace(tempo, &media);
	printf("Média: %d\n", media);
	
	//mergeSort
	printf("\nMERGE SORT\n"); //*alterar o titulo
	printf("Carregando resultados\n");
	for(i = 0; i < QTLOOP; i++){
		vetorMergeSort = carregaNumero(&tam, 2); //*alterar o vetor
		QueryPerformanceCounter(&tempoInicial);
		//gerando sort
		mergeSort(vetorMergeSort, 0, tam-1);
		
		QueryPerformanceCounter(&tempoFinal);
		tempo[i] = tempoFinal.QuadPart - tempoInicial.QuadPart;
		
		printf(".");
	}	
	criaFile("mergesort2.txt", tempo); //*alterar o nome do arquivo
	mediaPerformace(tempo, &media);
	printf("Média: %d\n", media);
	
	/////////////////////9990
	//bubble
	printf("BUBBLE SORT\n");
	printf("Carregando resultados\n");
	for(i = 0; i < QTLOOP; i++){
		vetorBubble = carregaNumero(&tam, 3);
		QueryPerformanceCounter(&tempoInicial);
		//gerando sort
		bubble(vetorBubble, tam);
		
		QueryPerformanceCounter(&tempoFinal);
		tempo[i] = tempoFinal.QuadPart - tempoInicial.QuadPart;
		
		printf(".");
	}	
	criaFile("bubblesort3.txt", tempo);
	mediaPerformace(tempo, &media);
	printf("Média: %d\n", media);
	
	//quicksort
	printf("\nQUICK SORT\n");
	printf("Carregando resultados\n");
	for(i = 0; i < QTLOOP; i++){
		vetorQuickSort = carregaNumero(&tam, 3);
		QueryPerformanceCounter(&tempoInicial);
		//gerando sort
		quicksort(vetorQuickSort, 0, tam-1);
		
		QueryPerformanceCounter(&tempoFinal);
		tempo[i] = tempoFinal.QuadPart - tempoInicial.QuadPart;
		
		printf(".");
	}	
	criaFile("quicksort3.txt", tempo);
	mediaPerformace(tempo, &media);
	printf("Média: %d\n", media);
	
	//selection
	printf("\nSELECTION SORT\n"); //*alterar o titulo
	printf("Carregando resultados\n");
	for(i = 0; i < QTLOOP; i++){
		vetorSelectionSort = carregaNumero(&tam, 3); //*alterar o vetor
		QueryPerformanceCounter(&tempoInicial);
		//gerando sort
		selection(vetorSelectionSort, tam);
		
		QueryPerformanceCounter(&tempoFinal);
		tempo[i] = tempoFinal.QuadPart - tempoInicial.QuadPart;
		
		printf(".");
	}	
	criaFile("selectionsort3.txt", tempo); //*alterar o nome do arquivo
	mediaPerformace(tempo, &media);
	printf("Média: %d\n", media);
	
	//insertion
	printf("\nINSERTION SORT\n"); //*alterar o titulo
	printf("Carregando resultados\n");
	for(i = 0; i < QTLOOP; i++){
		vetorInsertionSort = carregaNumero(&tam, 3); //*alterar o vetor
		QueryPerformanceCounter(&tempoInicial);
		//gerando sort
		insertion(vetorInsertionSort, tam);
		
		QueryPerformanceCounter(&tempoFinal);
		tempo[i] = tempoFinal.QuadPart - tempoInicial.QuadPart;
		
		printf(".");
	}	
	criaFile("insertionSort3.txt", tempo); //*alterar o nome do arquivo
	mediaPerformace(tempo, &media);
	printf("Média: %d\n", media);
	
	//mergeSort
	printf("\nMERGE SORT\n"); //*alterar o titulo
	printf("Carregando resultados\n");
	for(i = 0; i < QTLOOP; i++){
		vetorMergeSort = carregaNumero(&tam, 3); //*alterar o vetor
		QueryPerformanceCounter(&tempoInicial);
		//gerando sort
		mergeSort(vetorMergeSort, 0, tam-1);
		
		QueryPerformanceCounter(&tempoFinal);
		tempo[i] = tempoFinal.QuadPart - tempoInicial.QuadPart;
		
		printf(".");
	}	
	criaFile("mergesort3.txt", tempo); //*alterar o nome do arquivo
	mediaPerformace(tempo, &media);
	printf("Média: %d\n", media);
	
	
	/////////////99900
	//bubble
	printf("BUBBLE SORT\n");
	printf("Carregando resultados\n");
	for(i = 0; i < QTLOOP; i++){
		vetorBubble = carregaNumero(&tam, 4);
		QueryPerformanceCounter(&tempoInicial);
		//gerando sort
		bubble(vetorBubble, tam);
		
		QueryPerformanceCounter(&tempoFinal);
		tempo[i] = tempoFinal.QuadPart - tempoInicial.QuadPart;
		
		printf(".");
	}	
	criaFile("bubblesort4.txt", tempo);
	mediaPerformace(tempo, &media);
	printf("Média: %d\n", media);
	
	//quicksort
	printf("\nQUICK SORT\n");
	printf("Carregando resultados\n");
	for(i = 0; i < QTLOOP; i++){
		vetorQuickSort = carregaNumero(&tam, 4);
		QueryPerformanceCounter(&tempoInicial);
		//gerando sort
		quicksort(vetorQuickSort, 0, tam-1);
		
		QueryPerformanceCounter(&tempoFinal);
		tempo[i] = tempoFinal.QuadPart - tempoInicial.QuadPart;
		
		printf(".");
	}	
	criaFile("quicksort4.txt", tempo);
	mediaPerformace(tempo, &media);
	printf("Média: %d\n", media);
	
	//selection
	printf("\nSELECTION SORT\n"); //*alterar o titulo
	printf("Carregando resultados\n");
	for(i = 0; i < QTLOOP; i++){
		vetorSelectionSort = carregaNumero(&tam, 4); //*alterar o vetor
		QueryPerformanceCounter(&tempoInicial);
		//gerando sort
		selection(vetorSelectionSort, tam);
		
		QueryPerformanceCounter(&tempoFinal);
		tempo[i] = tempoFinal.QuadPart - tempoInicial.QuadPart;
		
		printf(".");
	}	
	criaFile("selectionsort4.txt", tempo); //*alterar o nome do arquivo
	mediaPerformace(tempo, &media);
	printf("Média: %d\n", media);
	
	//insertion
	printf("\nINSERTION SORT\n"); //*alterar o titulo
	printf("Carregando resultados\n");
	for(i = 0; i < QTLOOP; i++){
		vetorInsertionSort = carregaNumero(&tam, 4); //*alterar o vetor
		QueryPerformanceCounter(&tempoInicial);
		//gerando sort
		insertion(vetorInsertionSort, tam);
		
		QueryPerformanceCounter(&tempoFinal);
		tempo[i] = tempoFinal.QuadPart - tempoInicial.QuadPart;
		
		printf(".");
	}	
	criaFile("insertionSort4.txt", tempo); //*alterar o nome do arquivo
	mediaPerformace(tempo, &media);
	printf("Média: %d\n", media);
	
	//mergeSort
	printf("\nMERGE SORT\n"); //*alterar o titulo
	printf("Carregando resultados\n");
	for(i = 0; i < QTLOOP; i++){
		vetorMergeSort = carregaNumero(&tam, 4); //*alterar o vetor
		QueryPerformanceCounter(&tempoInicial);
		//gerando sort
		mergeSort(vetorMergeSort, 0, tam-1);
		
		QueryPerformanceCounter(&tempoFinal);
		tempo[i] = tempoFinal.QuadPart - tempoInicial.QuadPart;
		
		printf(".");
	}	
	criaFile("mergesort4.txt", tempo); //*alterar o nome do arquivo
	mediaPerformace(tempo, &media);
	printf("Média: %d\n", media);
	
	printf("\nFINALIZADO!!!!!");
	
	//imprimir(vetorBubble, tam);
	//imprimir(vetorQuickSort, tam);
	//imprimir(vetorSelectionSort, tam);
	//imprimir(vetorInsertionSort, tam);
	//imprimir(vetorMergeSort, tam);
	

return 0;
	
}
