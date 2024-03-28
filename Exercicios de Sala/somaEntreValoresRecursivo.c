#include <stdio.h>
#include <stdlib.h>

int somaRecursiva(int m, int n){                  // m = 4, n = 2, 9
    int resposta = 0; //valor aleatório
    if( m == n ){
        return m;
    } else {
        return m + somaRecursiva(m+1, n);
    }
}


int main() {

    int m = 2;
    int n = 4;

    int resposta = somaRecursiva(m, n);
    printf("   %d   ", resposta);

    return 0;

}