#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int contador = 0; //variável global, conta instruções

//declaração de métodos
void imprimeArray(int array[], int tamanho, char msg[]);
void geraArrayInteiro(int array[], int tamanho);
void insertionSortInvertido(int array[], int n);

int main() {
    int tamanho; //tamanho do array

    printf("Entre com o tamanho do Array de Inteiros: ");
    scanf(" %d", &tamanho);

    int array[tamanho];

    array[0] = 62;
    array[1] = 89;
    array[2] = 23;
    array[3] = 60;
    array[4] = 23;
    array[5] = 13;
    array[6] = 87;
    array[7] = 32;
    array[8] = 61;
    array[9] = 17;
    array[10] = 2;
    array[11] = 85;
    array[12] = 3;
    array[13] = 86;
    array[14] = 3;

    //Gerando o array 
    //geraArrayInteiro(array, n);
    printf("Ordenacao\n\n");
    imprimeArray(array, tamanho, "Array Desord. []: ");
    printf("\n");
    insertionSortInvertido(array, tamanho); 
    imprimeArray(array, tamanho, "Array Ord []: ");
    printf("\nNumero de Operacoes para Ordenacao: %d\n", contador);

    return 0;
}

// método para exibir na tela todos os valores do array
void imprimeArray(int array[], int tamanho, char msg[]) {
    printf("%s", msg); 
    for(int i = 0; i < tamanho; i++){
        printf("%d ", array[i]);
    };
}

// método para ordenar array adaptado                                       NAO INVERTIDO
void insertionSortInvertido(int array[], int tamanho) {
    int chave;

    for(int j = 1; j < tamanho; j++) {
        contador = contador + 1;
        chave = array[j];
        int i = j - 1;

        while((i >= 0) && (array[i] < chave)) { 
            array[i + 1] = array[i];
            i--;
            contador = contador + 1;
        }

        array[i + 1] = chave;
        imprimeArray(array, tamanho, "Array Ord Decrescente.[] = "); //método chama método (recursividade)
        printf("- %d\n", chave);
    }
}

// método para gerar array com valores aleatórios (%100 para fins de organização)
//void geraArrayInteiro(int array[], int n) {
//    srand(time(NULL));
//
//    for(int i = 0; i < n; i++) {
//        array[i] = rand() % 100;
//    }     
//}
