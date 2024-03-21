#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraArrayInteiro(int array[], int tamanho);
void MergeSortRecursivo(int A[], int p, int r, int tamanho);
void IntercalaSemSentinela(int A[], int p, int q, int r); // baseado em pseudo código
void ImprimeArrayInteiro(int array[], int tamanho, char a[]);


int main(){

    int tamanho;

    printf("Entre com o tamanho de Array de Inteiros: ");
    scanf("%d", &tamanho);

    int *array = (int *)malloc(tamanho * sizeof(int)); //REVER

    geraArrayInteiro(array, tamanho);

    /*
    array[0] = 88;
    array[1] = 45;
    array[2] = 97;
    array[3] = 27;
    array[4] = 78;
    array[5] = 53;
    array[6] = 29;
    array[7] = 50; 
    array[8] = 88;
    array[9] = 46;
    array[10] = 59;
    array[11] = 8;
    */

    printf("\n"); //alinha
    printf("Ordenacao\n");
    ImprimeArrayInteiro(array, tamanho, "Array Desord. [] =");
    MergeSortRecursivo(array, 0, tamanho-1, tamanho);
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

void MergeSortRecursivo(int *A, int p, int r, int tamanho) { 
    if (p < r) {
        int q = (p + r) / 2;
        ImprimeArrayInteiro(A, tamanho, "Array Ord.    [] =");
        MergeSortRecursivo(A, p, q, tamanho);
        MergeSortRecursivo(A, q + 1, r, tamanho);
        IntercalaSemSentinela(A, p, q, r);
        ImprimeArrayInteiro(A, tamanho, "Array Ord.    [] =");
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