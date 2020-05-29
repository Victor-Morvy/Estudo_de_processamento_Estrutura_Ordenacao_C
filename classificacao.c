void merge(int vetor[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }
    
    free(vetAux);
}

void mergeSort(int vetor[], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

void bubble(int x[], int n)
{
    int hold, j, pass;
    int trocou = 1;

    for(pass=0; pass < n-1 && trocou; pass++) {
        trocou = 0;
        for (j=0; j < n-pass-1; j++) {
            if (x[j]>x[j+1]) {
                trocou = 1;
                hold = x[j];
                x[j] = x[j+1];
                x[j+1] = hold;
            }
        }
    }
}

void quicksort(int x[], int ini, int fim)
{
    int i, j, pivo, aux;
    i = ini;
    j = fim;
    pivo = x[ini];
    while(i <= j)
    {
        while(x[i] < pivo && i < fim)
            i++;
        while(x[j] > pivo && j > ini)
            j--;
        if(i <= j)
        {
            aux = x[i];
            x[i] = x[j];
            x[j] = aux;
            i++;
            j--;
        }
    }
    if(j > ini)
        quicksort(x, ini, j);
    if(i < fim)
        quicksort(x, i, fim);
}

void selection(int x[], int n) {
  int i, j, min, aux;
  for (i = 0; i < (n-1); i++)
  {
    min = i;
    for (j = (i+1); j < n; j++) {
        if(x[j] < x[min])
         min = j;
    }
    aux = x[i];
    x[i] = x[min];
    x[min] = aux;
  }
}

void insertion(int x[], int n)
{
    int i, aux, j;
    for (i = 1; i < n; i++)
    {
        aux = x[i];
        j = i-1;

        while (j >= 0 && x[j] > aux)
        {
            x[j+1] = x[j];
            j -= 1;
        }
        x[j+ 1] = aux;
    }
}

void imprimir(int x[], int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%i ", x[i]);
	printf("\n\n");
}


/*int main()
{
	int x[] = {4,6,23,4,5,7,3,5,6,78,2,4,6,7,3,5,764,23,5,7};

	imprimir(x, 20);

	//insertion(x, 20);

	imprimir(x, 20);

	return 0;
}
*/
