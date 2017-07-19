#include "../Headers/bTree.h"
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10000
#define SEARCH 1000
#define MAX_VALUE 2000

int main(){
    bTree bt = btCreate();
    int value, i = 0, j;
    long unsigned int count;
    srand(time(NULL));   // should only be called once
    unsigned int r;
    int *array;
    array = (int*) malloc(sizeof(int)*MAX_SIZE);

     if(array == NULL)
    {
        printf("Vetor não foi inicializado.\n");
        return 1;
    }

    for(i = 0; i < MAX_SIZE; i++){ //gera números aleatórios
        r = (rand()%MAX_VALUE)+1;
        array[i] = r;
    }
    i = 0;
    for(i = 0; i < SEARCH; i++){
        value = array[(rand()%MAX_SIZE)];
        if(!btSearch(bt, value)) {
                printf("Erro ao pesquisar na arvore.\n");
                return -1;
        }
    }

    printf("Processo concluido com sucesso.\n");

    return 0;
}
