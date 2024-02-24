#include <stdlib.h>
#include <stdio.h>

void elementoMax (int tamanho, int array[]);

int main(){

    int tamanho;
    int instrucoes = 0; 

    printf("Entre com o tamanho do Array de inteiros: ");
    scanf("%d", &tamanho);         
                                                                                instrucoes = instrucoes +1;

    int array[tamanho];

    for(int i = 0; i < tamanho; i++){
        int valor;

        printf("Digite o valor para a posição %d do array: ", i+1);
        scanf("%d", &valor);     

        array[i] = valor;
                                                                            instrucoes = instrucoes +1;
    }

    elementoMax(tamanho, array);
    printf("Quantidade de instrucoes: %d", instrucoes);

    return 0;

}

void elementoMax (int tamanho, int array[]){
    int maiorValor = array[0];
    for(int i = 0; i < tamanho; i++){ 
        if(maiorValor < array[i]){
            maiorValor = array[i];
        }
                                                                            instrucoes = instrucoes +1;
    }
    printf("O maior elemento do array e: %d \n\n", maiorValor);
}
