#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ehPrimo(int n);

int contador = 0;//variavel global

int main(){

    //srand( time(NULL) );
    //int numero = rand() % 100; //resto é sempre de 1 a 99
    int numero = 41;

    if ( ehPrimo(numero) == 1 ){
        printf("O número %d eh Primo ", numero);
        printf("(Num. Operacoes = %d)", contador);
    } else {
        printf("O numero %d NAO eh Primo ", numero);
        printf("(Num. Operacoes = %d)", contador);
    }

    return 0;
}

int ehPrimo(int n) {
    if( n % 2 == 0 ){
        return 0; //nao é primo
        contador++;
    } else {
        for(int i = 3; i < n/2; i+=2) { // dividir por 2 (apartir da metade do nímero nn existe divisor)
            contador++;
            if(n % i == 0) {
                return 0; //nao é primo
                break;
            }
        }
    }
    return 1; //é primo
}