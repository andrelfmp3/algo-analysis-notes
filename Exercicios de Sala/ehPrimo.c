#include <stdio.h>
#include <stdlib.h>

int ehPrimo(int n) {
    int primo = 1;
    for(int i = 2; i <= n/2; i++) { // dividir por 2
        if(n % i == 0) {
            primo = 0;
            break;
        }
    }
    return primo;
}

