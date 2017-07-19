#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000
#define SEARCH 1000
#define MAX_VALUE 2000

int main(){
    long unsigned int count;
    srand(time(NULL));   // should only be called once
    unsigned int r;
    int *array;
    int value;
    int i = 0, j;
    array = (int*) malloc(sizeof(int)*MAX_SIZE);

    if(array == NULL)
    {
        printf("Vetor não foi inicializado.\n");
        return 1;
    }

    for(i = 0; i < MAX_SIZE; i++){
        r = (rand()%MAX_VALUE)+1;
        array[i] = r;
    }
    i = 0;
    for(i = 0; i < SEARCH; i++){
        value = array[(rand()%MAX)];
        for(j = 0; j < MAX; j++){
            if(value == array[j]) break;
            else if(j == MAX - 1) {
                printf("Erro na leitura do array.\n");
                return -1;
            }
        }
    }
    printf("Processo concluido com sucesso.\n");
    return 0;
}
