#include <stdlib.h>
#include <stdio.h>

int contador = 0; //variável global, conta instruções

//declaração de métodos
int elementoMax (int tamanho, int array[]);

int main(){

    int tamanho;

    printf("Entre com o tamanho do Array de inteiros: ");
    scanf("%d", &tamanho);         

    int array[tamanho];

    for(int i = 0; i < tamanho; i++){
        int valor;

        printf("Digite o valor para a posição %d do array: ", i+1);
        scanf("%d", &valor);     

        array[i] = valor;
    }

    printf("O maior elemento do Array é %d ", elementoMax(tamanho, array));
    printf("(Num. Operacoes = %d )", contador); //contabiliza toda função

    return 0;

}

// retorna maior valor do array
int elementoMax (int tamanho, int array[]){
    int maiorValor = array[0];
    for(int i = 1; i < tamanho; i++){ //int i = 0 é errado? tamanho -1 funciona igualmente 
        if(maiorValor < array[i]){
            maiorValor = array[i];
        }
        contador += 1;
    }
    return maiorValor;
}

