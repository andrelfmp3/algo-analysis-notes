#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int contador = 0; //variável global, conta instruções

//declaração de métodos
void ImprimeArray(int array[], int n, char msg[]);
void geraArrayInteiro(int array[], int n);
void insertionSort(int array[], int n);

int main() {
    int n; //tamanho do array

    printf("Entre com o tamanho do Array de Inteiros: ");
    scanf(" %d", &n);

    int array[n];
    int arrayTemp[n]; // Declare arrayTemp with proper size

    //Gerando o array 
    geraArrayInteiro(array, n);
    printf("Ordenacao\n");
    insertionSort(array, n); // Pass arrayTemp to insertionSort
    ImprimeArray(array, n, "Array ordenado: ");
    printf("Numero de Operacoes para Ordenacao: %d", contador);

    return 0;
}

// método para exibir na tela todos os valores do array
void ImprimeArray(int array[], int n, char msg[]) {
    printf("%s", msg); 
    for(int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

// método para ordenar array, feito em sala
void insertionSort(int array[], int n) {
    int chave;

    for(int j = 1; j < n; j++) {
        contador = contador + 1;
        chave = array[j];
        int i = j - 1;

        while((i >= 0) && (array[i] > chave)) { 
            array[i + 1] = array[i];
            i--;
            contador = contador + 1;
        }

        array[i + 1] = chave;
        ImprimeArray(array, n, "Array Desord.[] = "); //método chama método (recursividade)
    }
}

// método para gerar array com valores aleatórios (%100 para fins de organização)
void geraArrayInteiro(int array[], int n) {
    srand(time(NULL));

    for(int i = 0; i < n; i++) {
        array[i] = rand() % 100;
    }     
}
