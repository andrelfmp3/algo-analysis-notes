#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraArrayInteiro(int array[], int tamanho);
void MergeSortIterativo(int A[], int p, int r, int tamanho);
void IntercalaSemSentinela(int A[], int p, int q, int r); // baseado em pseudo código
void ImprimeArrayInteiro(int array[], int tamanho, char a[]);


int main(){

    int tamanho;

    printf("Entre com o tamanho de Array de Inteiros: ");
    scanf("%d", &tamanho);

    int *array = (int *)malloc(tamanho * sizeof(int)); //REVER

    geraArrayInteiro(array, tamanho);

    /*
    array[0] = 75;
    array[1] = 35;
    array[2] = 59;
    array[3] = 36;
    array[4] = 25;
    array[5] = 51;
    array[6] = 42;
    array[7] = 56; 
    array[8] = 82;
    array[9] = 26;
    array[10] = 13;
    array[11] = 1;
    */

    printf("\n"); //alinha
    printf("Ordenacao\n");
    ImprimeArrayInteiro(array, tamanho, "Array Desord. [] =");
    MergeSortIterativo(array, 0, tamanho-1, tamanho);
    ImprimeArrayInteiro(array, tamanho, "Array Ord.    [] =");


    free(array); //REVER    
    return 0; 

}

void geraArrayInteiro(int array[], int tamanho) {
    srand(time(NULL));
    for(int i = 0; i < tamanho; i++) {
        array[i] = rand() % 100;
    }     
}

void ImprimeArrayInteiro(int array[], int tamanho, char a[]){
    printf("%s", a);
    for(int i = 0; i < tamanho; i++){
        printf(" %d", array[i]);
    }
    printf("\n"); 
}

void MergeSortIterativo(int array[], int p, int r, int tamanho) {
    int q;
    for (int tamanho_atual = 1; tamanho_atual <= r; tamanho_atual = 2 * tamanho_atual) {
        for (p = 0; p < r; p += 2 * tamanho_atual) {
            q = p + tamanho_atual - 1;
            int fim_direita = p + 2 * tamanho_atual - 1;
            if (fim_direita < r) {
                IntercalaSemSentinela(array, p, q, fim_direita);
                ImprimeArrayInteiro(array, tamanho, "Array Desord. [] =");
            } else {
                IntercalaSemSentinela(array, p, q, r);
                ImprimeArrayInteiro(array, tamanho, "Array Desord. [] =");
            }
        }
    }
}


void IntercalaSemSentinela(int A[], int p, int q, int r) {
    //pseudocódigo adaptado com conteúdo de aula
    int i, j;
    int *B;

    B = (int*) malloc( (r+1) * sizeof(int) );

    //Copia da primeira metade do array - em ordem
    for(i = p; i <= q; i++) {
        B[i] = A[i];
    }

    //Copia da segunda metade do array - invertendo a ordem
    for(j = q + 1; j <= r; j++) {
        B[r + q + 1 - j] = A[j];
    }

    i = p;
    j = r;

    for(int k = p; k <= r; k++) {
        if(B[i] <= B[j]) {
            A[k] = B[i];
            i++;
        } else {
            A[k] = B[j];
            j--;
        }
    }

    free(B);
}