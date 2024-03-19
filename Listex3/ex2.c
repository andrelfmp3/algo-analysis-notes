#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraArrayInteiro(int array[], int tamanho);
void MergeSortRecursivo(int A[], int p, int r, int tamanho);
void IntercalaComSentinela(int A[], int p, int q, int r); // baseado em pseudo código
void ImprimeArrayInteiro(int array[], int tamanho, char a[]);

int main(){

    int tamanho;

    printf("Entre com o tamanho de Array de Inteiros: ");
    scanf("%d", &tamanho);

    int *array = (int *)malloc(tamanho * sizeof(int)); //REVER

    geraArrayInteiro(array, tamanho);

    /*
    array[0] = 89;
    array[1] = 26;
    array[2] = 87;
    array[3] = 49;
    array[4] = 76;
    array[5] = 8;
    array[6] = 79;
    array[7] = 32; 
    array[8] = 6;
    array[9] = 69;
    */

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

void MergeSortRecursivo(int A[], int p, int r, int tamanho) { 
    if (p < r) {
        int q = (p + r) / 2;
        ImprimeArrayInteiro(A, tamanho, "Array Ord.    [] =");
        MergeSortRecursivo(A, p, q, tamanho);
        MergeSortRecursivo(A, q + 1, r, tamanho);
        IntercalaComSentinela(A, p, q, r);
        ImprimeArrayInteiro(A, tamanho, "Array Ord.    [] =");
    }
}

void IntercalaComSentinela(int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1 + 1];
    int R[n2 + 1];

    for (int i = 0; i < n1; i++) { //pseudo código corrigido para começar em 0
        L[i] = A[p + i]; // pseudo código corrigido (posição +1 )
    }

    for (int j = 0; j < n2; j++) { //pseudo código corrigido para começar em 0
        R[j] = A[q + j + 1]; // pseudo código corrigido (posição +1 )
    }
    R[n2] = __INT_MAX__;
    L[n1] = __INT_MAX__;


    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}
