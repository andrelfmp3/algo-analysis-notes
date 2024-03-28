#include <stdio.h>
#include <stdlib.h>

void imprimeArray(int valorInicial){
    if (valorInicial != 5){
        printf("%d ", valorInicial);
        imprimeArray(valorInicial + 1);
    }
}

int main() {

    int valorInicial = 0;

    imprimeArray(valorInicial);

    return 0;

}