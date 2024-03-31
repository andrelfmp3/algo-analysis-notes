#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int contador = 0; //variável global, conta instruções

//declaração de métodos
int ehPrimo(int n);

int main(){

    srand( time(NULL) );
    int numero = rand() % 100; //resto é sempre de 1 a 99
    printf("Numero inteiro gerado aleatóriamente: %d\n", numero);

    if (ehPrimo(numero) == 1){
        printf("O número %d eh Primo ", numero);
        printf("(Num. Operacoes = %d)", contador);
    }
    else {
        printf("O numero %d NAO eh Primo ", numero);
        printf("(Num. Operacoes = %d)", contador);
    }

    return 0;
}

int ehPrimo(int n){
    int primo = 1;
    for (int i = 2; i <= n / 2; i++){ // dividir por 2
        contador += 1;
        if (n % i == 0){
            primo = 0;
            break;
        }
    }
    return primo;
}
