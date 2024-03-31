// André Lyra Fernandes - Resolvido
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declaração dos métods
void imprimeArray(int array[], int tamanho);
void procuraValor(int array[], int tamanho, int numero);

int main() {

    int tamanho;
    int numero;

    printf("Entre com o tamanho do array de inteiros: ");
    scanf("%d", &tamanho);

    int array[tamanho];

    srand(time(NULL)); 

    for (int i = 0; i < tamanho; i++) {
        array[i] = rand() % 100;
    }

    imprimeArray(array, tamanho);

    printf("Entre com o valor inteiro a ser procurado: ");
    scanf("%d", &numero);

    procuraValor(array, tamanho, numero);

    return 0;
}

// Método que imprime na tela array
void imprimeArray(int array[], int tamanho) {
    printf("Array Gerado = ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Método que procura e imprime valor específico no array (caso ele for encontrado)
void procuraValor(int array[], int tamanho, int numero) {
    for (int i = 0; i < tamanho; i++) {
        if (numero == array[i]) {
            printf("O valor %d foi encontrado na posicao %d.\n", numero, i + 1);
            return;
        }
    }
    printf("Valor nao encontrado no Array!\n");
}
