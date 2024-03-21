#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Assinaturas dos Métodos
void geraArrayInteiros(int arrayA[], int n);
void imprimeArray(int arrayA[], int n, char msg[]);
void insertionSort(int arrayA[], int n);
void copiaArray(int arrayA[], int arrayB[], int n);
void mergeSort(int arrayA[], int inicio, int fim);
void intercalaSemSentinela(int arrayA[], int inicio, int meio, int fim);
void intercalaComSentinela(int arrayA[], int inicio, int meio, int fim);

int main()
{
    //Variaveis Locais
    int n;              //Tamanho do Array
    int *arrayOriginal; //Array de Inteiros gerado automaticamente
    int *arrayTemp;     /*Array temporário para ser utilizado
                        nas ordenações, mantendo integridade
                        dos dados do Array Original */

    //Definindo o Array e alocando espaço de memória
    printf("\n Entre com o tamanho n do array de inteiros: ");
    scanf("%d", &n);
    arrayOriginal = (int*) malloc( n * sizeof(int) );
    arrayTemp = (int*) malloc( n * sizeof(int) );

    //Gerando o Array Original
    geraArrayInteiros(arrayOriginal, n);
    imprimeArray(arrayOriginal, n, "Array Original");

    //Ordenando o array por Insertion Sort
    printf("\n Algoritmo Insertion Sort: \n");
    imprimeArray(arrayOriginal, n, "Array Original");
    copiaArray(arrayOriginal, arrayTemp, n);
    insertionSort(arrayTemp, n);
    imprimeArray(arrayTemp, n, "Array Ordenado");
    printf("\n");
    system("pause");

    //Ordenando o array por Merge Sort Sem Sentinela
    printf("\n Algoritmo Merge Sort Sem Sentinela: \n");
    imprimeArray(arrayOriginal, n, "Array Original");
    copiaArray(arrayOriginal, arrayTemp, n);
    mergeSort(arrayTemp, 0, n-1);
    imprimeArray(arrayTemp, n, "Array Ordenado");
    printf("\n");
    system("pause");

    return 0;
}

/* geraArrayInteiros(): Método para gerar n números inteiros
   de 0 a 99 e armazenar em um array de inteiros */
void geraArrayInteiros(int arrayA[], int n) {
    int numAleatorio;

    srand( time(NULL) );
    for (int i=0; i<n; i++) {
        numAleatorio = rand() % 100;
        arrayA[i] = numAleatorio;
    }
}

/* imprimeArray(): Imprime os n elementos inteiros de um array */
void imprimeArray(int arrayA[], int n, char msg[]) {
    printf("\n %s = ", msg);

    for (int i=0; i<n; i++) {
        printf(" %d", arrayA[i]);
    }
}

/* insertionSort(): Método de ordenação direta de arrays de
   inteiros com complexidade T(n) = n^2 */
void insertionSort(int arrayA[], int n) {
    int chave;

    for (int j=1; j<n; j++) {
        chave = arrayA[j];
        //printf(" - %d", chave);
        int i = j-1;

        while ( (i>=0) & (arrayA[i] > chave ) ) {
            arrayA[i+1] = arrayA[i];
            i--;
        }

        arrayA[i+1] = chave;
        //imprimeArray(arrayA, n, "Ordenando");
    }
}

/* copiaArray(): Método que copia os n elementos do
   arrayA (origem) para o arrayB (destino) */
void copiaArray(int arrayA[], int arrayB[], int n) {
    for (int i=0; i<n; i++) {
        arrayB[i] = arrayA[i];
    }
}

/* mergeSort(): Método de ordenação por intercalação de
   elementos inteiros em arrays de com complexidade
   T(n) = n * lgn */
void mergeSort(int arrayA[], int inicio, int fim) {
    int meio;

    if(inicio < fim) {
        meio = (inicio + fim) / 2;
        mergeSort(arrayA, inicio, meio);
        mergeSort(arrayA, meio+1, fim);
        //intercalaSemSentinela(arrayA, inicio, meio, fim);
        intercalaComSentinela(arrayA, inicio, meio, fim);
    }
}

/* intercalaSemSentinela(): Método auxiliar do MergeSort para intercalar
   dois segmentos de array já ordenado, invertendo a segunda parte do array.
   T(n) = n */
void intercalaSemSentinela(int arrayA[], int inicio, int meio, int fim) {
    int i, j;
    int *arrayB;

    arrayB = (int*) malloc( (fim+1) * sizeof(int) );

    //Copia da primeira metade do array - em ordem
    for(i=inicio; i<=meio; i++) {
        arrayB[i] = arrayA[i];
    }

    //Copia da segunda metade do array - invertendo a ordem
    for(j=meio+1; j<=fim; j++) {
        arrayB[fim+meio+1-j] = arrayA[j];
    }

    i = inicio;
    j = fim;

    for(int k=inicio; k<=fim; k++) {
        if(arrayB[i] <= arrayB[j]) {
            arrayA[k] = arrayB[i];
            i++;
        } else {
            arrayA[k] = arrayB[j];
            j--;
        }
    }

    free(arrayB);
}

/* intercalaComSentinela(): Método auxiliar do MergeSort para intercalar
   dois segmentos de array já ordenado, utilizando um sentinela. T(n) = n */
void intercalaComSentinela(int arrayA[], int inicio, int meio, int fim) {
    int *L, *R;
    int n1, n2, i, j;

    n1 = meio - inicio + 1;
    n2 = fim - meio;

    L = (int*) malloc( (n1+1) * sizeof(int) );
    R = (int*) malloc( (n2+1) * sizeof(int) );

    for(i=0; i<n1; i++) {
        L[i] = arrayA[inicio+i];
    }

    for(j=0; j<n2; j++) {
        R[j] = arrayA[meio+j+1];
    }

    L[n1] = 30000;
    R[n2] = 30000;

    i=0;
    j=0;

    for(int k=inicio; k<=fim; k++) {
        if(L[i] <= R[j]) {
            arrayA[k] = L[i];
            i++;
        } else {
            arrayA[k] = R[j];
            j++;
        }
    }

    free(L);
    free(R);
}