//ordenação por intercalação
// para para esquerda, impar para direito (merga de n impar)

void MergeSort(int A[], int p, int r){
    if (p < r){
        q <- [(p+r)/2]{ //erro proposital
            MergeSort(A, p, q);
            MergeSort(A, q+1, r);
            Intercala(A, p, q, r);
        }
    }
}

//estudar malloc
void Intercala(int A[], int p, int q, int r){ 
    
    //sentinela (final com infinito)

    int cont = 0;
    for(int i = 0; i < r; i++){
        if (A[p + cont] > A[q + cont]){
            A[cont] = q;
            A[cont + 1] = p;
            cont = cont + 2;
        } else if (A[p + cont] < A[q + cont]){
            A[cont] = p;
            A[cont + 1] = q;
            cont = cont + 2;
        }
    }
}