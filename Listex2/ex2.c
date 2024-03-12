#include <stdio.h>
#include <stdlib.h>

int contador1 = 0; //contador ERRADO
int contador2 = 0; //contador ERRADO
int contador3 = 0; //contador ERRADO

int maxMin1 (int tamanho, int array[], int maiorValor, int menorValor);
int maxMin2 (int tamanho, int array[], int maiorValor, int menorValor);
int maxMin3 (int tamanho, int Array[], int maiorValor, int menorValor);
void numeraArray(int tamanho, int Array[]);

int main(){

    int tamanho;
    int maiorValor;
    int menorValor;

    printf("Entre com o tamanho do Array de Inteiros: ");
    scanf("%d", &tamanho);

    int array[tamanho];

    numeraArray(tamanho, array);
    maxMin1(tamanho, array, maiorValor, menorValor);
    maxMin2(tamanho, array, maiorValor, menorValor);
    maxMin3(tamanho, array, maiorValor, menorValor);

    return 0;

}

int maxMin1 (int tamanho, int array[], int maiorValor, int menorValor){
    maiorValor = array[0];
    menorValor = array[0];

    for(int i = 1; i < tamanho; i++){ //int i = 0 é errado? tamanho -1 funciona igualmente? 
        if(array[i] > maiorValor){
            maiorValor = array[i];
            contador1 += 1;
        }
        if(array[i] < menorValor){ //diminui instruções
            menorValor = array[i];
            contador1 += 1;
        }
    }
    printf("maxMin1() - Maior Elemento: %d - Menor Elemento: %d (Num. de Operacoes: %d)\n", maiorValor, menorValor, contador1);
}

int maxMin2 (int tamanho, int array[], int maiorValor, int menorValor){
    maiorValor = array[0];
    menorValor = array[0];

    for(int i = 1; i < tamanho; i++){ //int i = 0 é errado? tamanho -1 funciona igualmente? 
        if(array[i] > maiorValor){
            maiorValor = array[i];
            contador2 += 1;
        }
        else if(array[i] < menorValor){ //diminui instruções
            menorValor = array[i];
            contador2 += 1;
        }
    }
    printf("maxMin2() - Maior Elemento: %d - Menor Elemento: %d (Num. de Operacoes: %d)\n", maiorValor, menorValor, contador2);
}


int maxMin3 (int tamanho, int Array[], int maiorValor, int menorValor){ //compara em pares
    if(tamanho%2 != 0){
        Array[tamanho+1] = Array[tamanho];
        tamanho = tamanho + 1;
    }

    maiorValor = Array[0];
    menorValor = Array[1];
    if( Array[0] < Array[1]){
        maiorValor = Array[1];
        menorValor = Array[0];
    } 
    for(int i = 2; i < tamanho; i = i + 2){
        if(Array[i] > Array[i+1]){
            if(Array[i] > maiorValor){
                maiorValor = Array[i];
                contador3 += 1;
            }
            if(Array[i+1] < menorValor){
                menorValor = Array[i+1];
                contador3 += 1;
            }
        } else {
            if(Array[i] < menorValor){
                menorValor = Array[i];
                contador3 += 1;
            }
            if(Array[i+1] > maiorValor){
                maiorValor = Array[i+1];
                contador3 += 1;
            }
        }
    }
    printf("maxMin3() - Maior Elemento: %d - Menor Elemento: %d (Num. de Operacoes: %d)\n", maiorValor, menorValor, contador3);
}

void numeraArray(int tamanho, int Array[]){
    for(int i = 0; i < tamanho; i++){
        int n;
        printf("Digite um valor para a posição %d do Array: ", i+1);
        scanf("%d", &n);
        Array[i] = n;
    }
}
