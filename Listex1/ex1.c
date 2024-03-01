#include <stdlib.h>
#include <stdio.h>

int elementoMax (int tamanho, int array[]);
int instrucoes = 0; //conta instrucoes

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
    printf("(Num. Operacoes = %d )", instrucoes);

    return 0;

}

int elementoMax (int tamanho, int array[]){
    int maiorValor = array[0];
    for(int i = 1; i < tamanho; i++){ //int i = 0 é errado? tamanho -1 funciona igualmente 
        if(maiorValor < array[i]){
            maiorValor = array[i];
        }
        instrucoes += 1;
    }
    return maiorValor;
}
