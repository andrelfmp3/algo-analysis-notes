int contador1, contador2, contador3;

int maxMin1 (int tamanho, int array[], int maiorValor, int menorValor){
    maiorValor = array[0]; // 1 vez
    menorValor = array[0]; // 1 vez
    for(int i = 1; i < tamanho; i++){  // 1 + (n-1) + (n-1) + 1 
        if(array[i] > maiorValor){ // n - 1 vezes (no pior caso)
            maiorValor = array[i]; // 1 vez
        }
        if(array[i] < menorValor){ // n - 1 vezes (no pior caso)
            menorValor = array[i]; // 1 vez
        }
    }
    printf("maxMin1() - Maior Elemento: %d - Menor Elemento: %d (Num. de Operacoes: %d)\n", maiorValor, menorValor, contador1);
    // 1 vez
}

int maxMin2(int tamanho, int array[], int maiorValor, int menorValor){
    maiorValor = array[0]; // 1 vez
    menorValor = array[0]; // 1 vez
    for(int i = 1; i < tamanho; i++){ // 1  + n-1 + n-1 + 1 vezes
        if(array[i] > maiorValor){ // n - 1 vezes (no pior caso)
            maiorValor = array[i]; // 1 vez 
        } else if (array[i] < menorValor){ // condição excludente
            menorValor = array[i];
        }
    }
    printf("maxMin2() - Maior Elemento: %d - Menor Elemento: %d (Num. de Operacoes: %d)\n", maiorValor, menorValor, contador2);
    // 1 vez
}

int maxMin3 (int tamanho, int Array[], int maiorValor, int menorValor){ //compara em pares
    if(tamanho%2 != 0){ // 1 vez (no pior caso)
        Array[tamanho+1] = Array[tamanho]; // 1 vez 
        tamanho = tamanho + 1; // 1 vez 
    }
    maiorValor = Array[0]; // 1 vez
    menorValor = Array[1]; // 1 vez
    if( Array[0] < Array[1]){ // 1 vez (no pior caso)
        maiorValor = Array[1]; // 1 vez 
        menorValor = Array[0]; // 1 vez 
    } 
    for(int i = 2; i < tamanho; i = i + 2){ // 1 + (n-2)/2 + (n-2)/2 + 1                    
        if(Array[i] > Array[i+1]){ // (n - 2) / 2 vezes (no pior caso)                
            if(Array[i] > maiorValor){ // (n - 2) / 2 vezes (no pior caso)
                maiorValor = Array[i];  // 1
            }
            if(Array[i+1] < menorValor){ // (n - 2) / 2 vezes (no pior caso)
                menorValor = Array[i+1]; // 1 (no pior caso)
            }
        } else {
            if(Array[i] < menorValor){ 
                menorValor = Array[i];
            }
            if(Array[i+1] > maiorValor){ 
                maiorValor = Array[i+1]; // 1
            }
        }
    }
    printf("maxMin3() - Maior Elemento: %d - Menor Elemento: %d (Num. de Operacoes: %d)\n", maiorValor, menorValor, contador3);
    // 1 vez
}

// dentro do if else, apenas 2 serão executados, por ser uma condição excludente)
// lógica do for: (incremente de 2 em 2, então x/1 vira x/2; e começa em 2, logo é n -2/2)
// contadores excluidos da função
