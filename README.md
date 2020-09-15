## ESTUDO DE COMPARAÇÃO DE TEMPOS DE EXECUÇÃO DE ESTRUTURAS DE DADOS PARA ORDENAR VETORES EM C

PDF: https://github.com/Victor-Morvy/Estudo_de_processamento_Estrutura_Ordenacao_C/blob/master/FINAL/Compara%C3%A7%C3%A3o%20de%20estrutura%20de%20dados%20de%20ordena%C3%A7%C3%A3o%20de%20vetores%20em%20c.pdf

## 1. INTRODUÇÃO

Em aula foram apresentadas 04 estruturas de dados, estas: Bubble Sort,
Quick Sort, Selection Sort e Insertion Sort, todas estruturadas com suas
características e complexidade. Então foi proposto este presente trabalho para que
testamos a performance de ordenação dessas estruturas e mais uma não listada, e
foi indicado a estrutura Merge Sort para comparação.

## 2. OBJETIVO

Obter dados de processamento das estruturas de dados: Bubble Sort, Quick
Sort, Selection Sort, Insertion Sort e Marge Sort e compara-las entre si.


## 3. METODOLOGIA

Foram criados 5 arquivos do tipo texto. O primeiro “arquivo300.txt” contendo
300 valores gerados aleatoriamente entre 0 e 999. O segundo “arquivo999.txt”
contendo 999 valores gerados aleatoriamente entre 0 e 999. E o terceiro “arquivo
9990.txt” contendo 9990 valores gerados aleatoriamente entre 0 e 9990,
“arquivo20.txt” contendo 20 valores gerados aleatoriamente entre 0 e 999 e um
último “arquivo99900.txt” contendo 99900 valores gerados aleatoriamente entre 0 e
9990 (este foram realizados apenas 3 laços, pois eram muitos números).

Foi criado uma função chamada carregarNumero() que carrega estes
arquivos e devolve o vetor.

![](/images/image--000.jpg)

Foi criada também uma função chamada criaFile() que é chamada após o
arquivo ser ordenado, esta função é responsável por criar os arquivos com o
resultado da performance.

![](/images/image--001.jpg)

Para cada tipo de estrutura e arquivo txt foi criada a seguinte linha de código:

![](/images/image--002.jpg)

Este código se repete com algumas variações, entre o tipo de estruturas a
ordenar e o arquivo .txt que será usado para consulta, este definido pelo segundo
parâmetro da função carregaNumero(). Nele a variável QTLOOP está setada para
20, isto é, o programa testará em forma de laço por 20 vezes (menos o arquivo com
99900 dados, que foram feitos 3 laços), carregando novamente o vetor com os
valores dos arquivos .txt, então é iniciado o contador de performance, armazenando-o 
em uma variável chamada tempoInicial, em seguida, é executado a função de uma
estrutura de dados que ordenará o vetor de acordo, estes como já citados são:
Bubble Sort, Quick Sort, Selection Sort e Insertion Sort e Merge Sort. Após
executado, o contador de performance finaliza armazenando o valor em uma outra
variável chamada tempoFinal. Um vetor chamado tempo alocado com 20 unidades
de memória inteiros é montado, dando a cada índice os valores da subtração da
variável tempoFinal com a variável tempoInicial. E então executado a função
criaFile() dando como um dos parâmetros o vetor tempo.

Para que não houvessem grandes interferências externas, foram fechados os
navegadores, arquivos-texto, arquivos excel, pastas e alguns programas que
estavam rodando no processo que não seriam utilizados no processo, e, por fim,
compilado.

## 4. DADOS OBTIDOS

Tabela 1 – Dados gerados pelas estruturas com 300 dados carregados no vetor.

![](/images/image--003.jpg)

Tabela 2 – Dados gerados pelas estruturas com 999 dados carregados no vetor.

![](/images/image--004.jpg)

Tabela 3 – Dados gerados pelas estruturas com 9990 dados carregados no vetor.

![](/images/image--005.jpg)

Tabela 4 – Dados gerados pelas estruturas com 20 dados carregados no vetor.

![](/images/image--006.jpg)

Tabela 5 – Dados gerados pela estrutura com 99900 dados carregados no vetor.

![](/images/image--007.jpg)

Tabela 6 – Comparação de dados gerados em relação a estruturas e valores médios
obtidos.

![](/images/image--008.jpg)

Gráfico 1 – Comparação de dados gerados em relação a estruturas e valores
médios obtidos.

![](/images/image--009.jpg)


## 5. CONCLUSÃO

Ao concretizar esta bateria de testes com diferentes estruturas de
organização e tamanho de vetores, obtive resultados variados, nos 3 primeiros
testes, de 300, 999 e 9990 dados as estruturas Bubble Sort, Selection Sort, Insertion
Sort e Quick Sort se manteve em uma posição subsequente da outra, com uma
pequena diferença da Merge Sort, que quanto mais dados, mais se aproximava da
Quick Sort.

(Em ordem Tabela 1, Tabela 2 e Tabela 3).

- 300 dados

    Merge Sort, Bubble Sort, Selection Sort, Insertion Sort, Quick Sort
- 999 dados

    Bubble Sort, Selection Sort, Merge Sort, Insertion Sort, Quick Sort
- 9990 dados

    Bubble Sort, Selection Sort, Insertion Sort, Merge Sort, Quick Sort
    
Foi possível perceber também que os dados de testes gerados a partir do
arquivo de 20 dados foi quase indiferente entre as estruturas Bubble Sort, Selection
Sort, Insertion Sort e Quick Sort, com destaque da Merge Sort, que apresentou uma
média de 500% a mais de processamento vide Tabela 4.

Outro detalhe da estrutura de dados Merge Sort, é que em uma determinada
quantidade de dados, ainda assim não passa o Quick Sort e velocidade de
processamento, é possível perceber na Tabela 5 este fenômeno.

Contudo, é conclusivo que a estrutura de Merge Sort é um tanto quanto
interessante em relação a diminuição de processamento exponencial com a
quantidade de dados, e que chega a um limite em uma determinada quantidade de
dados em relação ao Quick Sort, que impressiona pela sua velocidade de
processamento, tendo apenas em torno de 10% do processamento do Merge Sort,
segundo colocado no caso com mais dados.


