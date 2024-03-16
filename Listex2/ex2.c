// André Lyra Fernandes - resolvido
#include <stdio.h>
#include <stdlib.h>

int contador1 = 0; //variável global, conta instruções 
int contador2 = 0; //variável global, conta instruções 
int contador3 = 0; //variável global, conta instruções

//declaração de métodos10 9 8 7 5 6 4 7 1 2 5
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
    printf("\n");
    maxMin1(tamanho, array, maiorValor, menorValor);
    maxMin2(tamanho, array, maiorValor, menorValor);
    maxMin3(tamanho, array, maiorValor, menorValor);

    return 0;

}

// Imprime valor máximo e mínimo
int maxMin1 (int tamanho, int array[], int maiorValor, int menorValor){
    maiorValor = array[0]; 
    menorValor = array[0]; 

    for(int i = 1; i < tamanho; i++){  
        contador1 += 1;
        if(array[i] > maiorValor){ 
            maiorValor = array[i]; 
        }
        contador1 += 1; 
        if(array[i] < menorValor){ 
            menorValor = array[i]; 
        }
    }
    printf("maxMin1() - Maior Elemento: %d - Menor Elemento: %d (Num. de Operacoes: %d)\n", maiorValor, menorValor, contador1);
}

// Imprime valor máximo e mínimo
int maxMin2 (int tamanho, int array[], int maiorValor, int menorValor){
    maiorValor = array[0];
    menorValor = array[0];

    for (int i = 1; i < tamanho; i++) { 
        contador2++;
        if (array[i] > maiorValor) { 
            maiorValor = array[i]; 
        } else {
            if (array[i] < menorValor) { 
                menorValor = array[i]; 
            }
        }
    }

    printf("maxMin2() - Maior Elemento: %d - Menor Elemento: %d (Num. de Operacoes: %d)\n", maiorValor, menorValor, contador2);
}


// Imprime valor máximo e mínimo
int maxMin3 (int tamanho, int Array[], int maiorValor, int menorValor){
    if (tamanho % 2 != 0) { // 1
        Array[tamanho + 1] = Array[tamanho]; // 1
        tamanho++; // 1
    }
    maiorValor = Array[1]; // 1
    menorValor = Array[0]; // 1
    contador3++;
    if (Array[0] > Array[1]) { // 1
        maiorValor = Array[0]; // 1
        menorValor = Array[1]; // 1
    }

    for (int i = 2; i < tamanho; i += 2) { // 1 + 2(((n - 2)) / 2) + 1
        contador3++;
        if (Array[i] > Array[i + 1]) { // (n - 2) / 2
            contador3++;
            if (Array[i] > maiorValor) { // (n - 2) / 2
                maiorValor = Array[i]; // (n - 2) / 2
            }
            contador3++;
            if (Array[i + 1] < menorValor) { // (n - 2) / 2
                menorValor = Array[i + 1]; // (n - 2) / 2
            }
        } else {
            contador3++;
            if (Array[i + 1] > maiorValor) { // independente do resultado do primeiro if, a mesma quantidade de instruções será executada
                maiorValor = Array[i + 1];
            }
            contador3++;
            if (Array[i] < menorValor) {
                menorValor = Array[i];
            }
        }
    }
    printf("maxMin3() - Maior Elemento: %d - Menor Elemento: %d (Num. de operacoes: %d)\n",
             maiorValor, menorValor, contador3);  // 1
}

// Imprime array de forma numerada
void numeraArray(int tamanho, int Array[]){
    for(int i = 0; i < tamanho; i++){
        int n;
        printf("Digite um valor para a posição %d do Array: ", i+1);
        scanf("%d", &n);
        Array[i] = n;
    }
}
