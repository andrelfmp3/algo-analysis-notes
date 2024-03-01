//função

int elementoMax (int tamanho, int array[], int maiorValor, int menorValor){
    int maiorValor = array[0];
    int menorValor = array[0];

    for(int i = 1; i < tamanho; i++){ //int i = 0 é errado? tamanho -1 funciona igualmente? 
        if(maiorValor < array[i]){
            maiorValor = array[i];
        }
        else if(menorValor > array[i]){ //diminui instruções
            menorValor = array[i];
        }
    }

    return maiorValor;
    return menorValor; 
}

//função

int elementoMax2 (int A[], int n, int max, int min){ //compara em pares
    if(n%2 != 0){
        A[n+1] = A[n];
        n = n + 1;
    }

    max = A[0];
    min = A[1];
    if( A[0] < A[1]){
        max = A[1];
        min = A[0];
    } 
    for(int i = 2; i < n; i = i + 2){
        if(A[i] > A[i+1]){
        //ex nao finalizado
    }
}