#include <stdio.h>
#include <stdlib.h>

long fatorialRecursivo(int n){
    if (n <= 1){
        return 1;
    }
    return n * fatorialRecursivo(n-1);
}

int main() {

    int n = 5;

    int resposta = fatorialRecursivo(n);
    printf("   %d   ", resposta);

    return 0;

}