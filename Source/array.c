#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

int main(){
    int *vetor;
    int valor;
    int i = 0;
    FILE *numeros;
    vetor = (int*) malloc(sizeof(int)*MAX);

    if(vetor == NULL)
    {
        printf("Vetor não foi inicializado.\n");
        return 1;
    }

    numeros = fopen("file.txt", "r");
    if(numeros == NULL)
    {
        printf("Erro na abertura do arquivo com numeros.\n");
        return 1;
    }

    while (i < MAX)
    {
        fscanf(numeros, "%d", &vetor[i]);
        i++;
    }
    fclose(numeros);

    //Fazer busca linear
}


