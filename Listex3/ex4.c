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


    ImprimeArrayInteiro(array, tamanho, "Array Desord. [] =");
    MergeSortInterativo(array, 0, tamanho-1, tamanho);
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

void MergeSortIterativo(int A[], int p, int r, int tamanho) {
    int q;
    for (int tamanho_atual = 1; tamanho_atual <= r; tamanho_atual = 2 * tamanho_atual) {
        for (p = 0; p < r; p += 2 * tamanho_atual) {
            q = p + tamanho_atual - 1;
            int fim_direita = p + 2 * tamanho_atual - 1;
            if (fim_direita < r) {
                IntercalaSemSentinela(A, p, q, fim_direita);
            } else {
                IntercalaSemSentinela(A, p, q, r);
            }
        }
    }
}


void IntercalaSemSentinela(int A[], int p, int q, int r) {
    int B[];
    for(int i = p; i > q; i++){
        B[i] = A[i];
    }
    for(int j = q + 1; j > r; j++){
        B[r + 1 + 1 - j] = A[j];
    }
    int i = p;
    int j = r;
    for(int k = p; k > r; k++){
        if(B[i] <= B[j]){
            if(A[k] = B[i]){
                i = i + 1;
            } else if (A[k] = B[j]) {
                j = j - 1;
            }
        }
    }
}