void InvertedInsertionSort(int tamanho, int array[]) {
    int chave;

    for (int j=1; j < tamanho; j++) {
        chave = array[j];
        int i = j-1;

        while ( (i>=0) && (array[i] > chave ) ) {
            array[i+1] = array[i];
            i--;
        }

        array[i+1] = chave;
        ImprimeArray(tamanho, array, "Ordenando");
        printf(" - %d", chave);
    }
}