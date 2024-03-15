int maxMin1 (int tamanho, int array[], int maiorValor, int menorValor){
    maiorValor = array[0]; // 1 vez
    menorValor = array[0]; // 1 vez

    for(int i = 1; i < tamanho; i++){  // 1 (int i = 1) + n-1 (i < tamanho, n-1 pois começa no 1) + n-1 (i++, n-1 pois começa no n-1) + 1 (saída do for)
        contador1 += 1;
        if(array[i] > maiorValor){ // n - 1 vezes
            maiorValor = array[i]; // 1 vez
            contador1 += 1; // 1 vez
        }
        if(array[i] < menorValor){ // n - 1 vezes
            menorValor = array[i]; // 1 vez
            contador1 += 1; // 1 vez
        }
    }
    contador1 += 3; // Adiciona 3 para o printf e as duas atribuições iniciais
    printf("maxMin1() - Maior Elemento: %d - Menor Elemento: %d (Num. de Operacoes: %d)\n", maiorValor, menorValor, contador1);
}

// Imprime valor máximo e mínimo
int maxMin2(int tamanho, int array[], int maiorValor, int menorValor){
    maiorValor = array[0];
    menorValor = array[0];

    for(int i = 1; i < tamanho; i++){ // 1  + n-1 + n-1 + 1 
        if(array[i] > maiorValor){ // n - 1
            maiorValor = array[i];
            contador2 += 1; 
        } else if (array[i] < menorValor){ // n - 1. (else if é excluidente, no pior caso 2x, no melhor, x)
            menorValor = array[i];
            contador2 += 1; 
        }
    }
    contador2 += 3; // Adiciona 3 para o printf e as duas atribuições iniciais
    printf("maxMin2() - Maior Elemento: %d - Menor Elemento: %d (Num. de Operacoes: %d)\n", maiorValor, menorValor, contador2);
}

// Imprime valor máximo e mínimo
int maxMin3 (int tamanho, int Array[], int maiorValor, int menorValor){ //compara em pares
    if(tamanho%2 != 0){
        Array[tamanho+1] = Array[tamanho];
        tamanho = tamanho + 1;
        contador3 += 1;
    }

    maiorValor = Array[0];
    menorValor = Array[1];
    if( Array[0] < Array[1]){ // feita 1 vez
        maiorValor = Array[1];
        menorValor = Array[0];
        contador3 += 1;
    } 
    // lógica do for: (incremente de 2 em 2, então x/1 vira x/2; e começa em 2, logo é n -2/2)
    for(int i = 2; i < tamanho; i = i + 2){ // 1 + (n-2)/2 + (n-2)/2 + 1                    
        contador3 += 1;
        if(Array[i] > Array[i+1]){ // (n - 2) / 2 vezes                
            contador3 += 1;
            if(Array[i] > maiorValor){ // (n - 2) / 2 vezes (dentro do if else, apenas 2 serão executados, por ser uma condição excludente)
                maiorValor = Array[i]; 
                contador3 += 1;
            }
            if(Array[i+1] < menorValor){ // (n - 2) / 2 vezes (dentro do if else, apenas 2 serão executados, por ser uma condição excludente)
                menorValor = Array[i+1];
                contador3 += 1;
            }
        } else {
            if(Array[i] < menorValor){ // (dentro do if else, apenas 2 serão executados, por ser uma condição excludente)
                menorValor = Array[i];
                contador3 += 1;
            }
            if(Array[i+1] > maiorValor){ // (dentro do if else, apenas 2 serão executados, por ser uma condição excludente)
                maiorValor = Array[i+1];
                contador3 += 1;
            }
        }
    }
    contador3 += 3; // Adiciona 3 para o printf e as duas atribuições iniciais
    printf("maxMin3() - Maior Elemento: %d - Menor Elemento: %d (Num. de Operacoes: %d)\n", maiorValor, menorValor, contador3);
}