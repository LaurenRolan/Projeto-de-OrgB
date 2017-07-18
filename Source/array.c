#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000
#define SEARCH 1000
int main(){
    int *array;
    int value;
    int i = 0, j;
    FILE *numbers;
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
     i = 0;
    while (i < SEARCH)
    {
        fscanf(numbers, "%d", &value);
        printf("%d", value);
        for(j = 0; j < MAX; j++){
            if(value == array[j]) break;
            else if(j == MAX - 1) {
                printf("Erro na leitura do array.\n");
                return -1;
            }
        }
        i++;
    }
    fclose(numbers);
    printf("Processo concluido com sucesso.\n");
    return 0;
}
