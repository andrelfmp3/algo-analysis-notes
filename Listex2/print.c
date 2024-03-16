int contador1, contador2, contador3;

int maxMin1 (int tamanho, int array[], int maiorValor, int menorValor){
    maiorValor = array[0]; // 1 vez
    menorValor = array[0]; // 1 vez
    for(int i = 1; i < tamanho; i++){  // 1 + (n-1) + (n-1) + 1 
        if(array[i] > maiorValor){ // n - 1 vezes 
            maiorValor = array[i]; // n - 1 vezes 
        }
        if(array[i] < menorValor){ // n - 1 vezes 
            menorValor = array[i]; // 
        }
    }
    printf("maxMin1() - Maior Elemento: %d - Menor Elemento: %d (Num. de Operacoes: %d)\n", maiorValor, menorValor, contador1);
    // 1 vez
}

int maxMin2(int tamanho, int array[], int maiorValor, int menorValor){
    maiorValor = array[0]; // 1 vez
    menorValor = array[0]; // 1 vez
    for(int i = 1; i < tamanho; i++){ // 1  + n-1 + n-1 + 1 vezes
        if(array[i] > maiorValor){ // n - 1 vezes 
            maiorValor = array[i]; 
        } else { 
            if (array[i] < menorValor) { // n - 1
                menorValor = array[i]; // n - 1
            }
        }
    }
    printf("maxMin2() - Maior Elemento: %d - Menor Elemento: %d (Num. de Operacoes: %d)\n", maiorValor, menorValor, contador2);
    // 1 vez
}

int maxMin3 (int tamanho, int Array[], int maiorValor, int menorValor){
    if (tamanho % 2 != 0) { // 1 vez
        Array[tamanho + 1] = Array[tamanho]; // 1 vez
        tamanho++; // 1 vez
    }
    maiorValor = Array[1]; // 1 vez
    menorValor = Array[0]; // 1 vez
    
    if (Array[0] > Array[1]) { // 1 vez
        maiorValor = Array[0]; // 1 vez
        menorValor = Array[1]; // 1 vez
    }

    for (int i = 2; i < tamanho; i += 2) { // 1 + 2(((n - 2)) / 2) + 1 vezes
        if (Array[i] > Array[i + 1]) { // (n - 2) / 2 vezes
            if (Array[i] > maiorValor) { // (n - 2) / 2 vezes
                maiorValor = Array[i]; // (n - 2) / 2 vezes
            }
            if (Array[i + 1] < menorValor) { // (n - 2) / 2 vezes
                menorValor = Array[i + 1]; // (n - 2) / 2 vezes
            }
        } else {
            if (Array[i + 1] > maiorValor) { 
                maiorValor = Array[i + 1];
            }
            if (Array[i] < menorValor) {
                menorValor = Array[i];
            }
        }
    }
    printf("maxMin3() - Maior Elemento: %d - Menor Elemento: %d (Num. de operacoes: %d)\n", maiorValor, menorValor, contador3);  
    // 1 vez
}





