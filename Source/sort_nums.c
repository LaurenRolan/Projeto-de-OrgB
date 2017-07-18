#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000
#define SEARCH 1000

int main(){
    int *array;
    int value;
    int i = 0;
    srand(time(NULL));
    FILE *numbers, *search;
    array = (int*) malloc(sizeof(int)*MAX);

    if(array == NULL)
    {
        printf("Vetor não foi inicializado.\n");
        return 1;
    }

    numbers = fopen("file.txt", "r");
    if(numbers == NULL)
    {
        printf("Erro na abertura do arquivo com numeros.\n");
        return 1;
    }

    while (i < MAX)
    {
        fscanf(numbers, "%d", &array[i]);
        i++;
    }
    fclose(numbers);

    search = fopen("pesquisa.txt", "w");
    if(search == NULL)
    {
        printf("Erro na abertura do arquivo com numeros.\n");
        return 1;
    }
    for(i = 0; i < SEARCH; i++){
        valor = (rand()%SEARCH);
        fprintf(search, "%d ", array[value]);
    }
    fclose(search);
    printf("Processo concluido com sucesso.\n");
    return 0;
}
