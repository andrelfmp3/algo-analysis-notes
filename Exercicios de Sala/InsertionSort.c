// insertion sort
// array de inteiros e tamanho n
// divide em array ordenado e array nao ordenado
// array de um termpo é ordenado 
// n e n-1 no primeiro caso
// sempre faz n-1 iteracoes

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int array[], int n) {

    int i;
    int chave; //key, valor escolhido
    int j;

    for (i = 1; i < n; i++) { //percorre n vezes (tamanho do array)
        chave = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > chave) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = chave;
    }
}