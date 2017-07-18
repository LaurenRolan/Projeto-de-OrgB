#include "../Headers/bTree.h"
#include <stdlib.h>
#include <time.h>
#define MAX 10000
#define SEARCH 1000

int main(){
    bTree bt = btCreate();
    FILE *numbers;
    int value, i = 0;

    numbers = fopen("file.txt", "r");
    if(numbers == NULL)
    {
        printf("Erro na abertura do arquivo com numeros.\n");
        return 1;
    }

    while (i < MAX)
    {
        fscanf(numbers, "%d", &value);
        btInsert(bt, value);
        i++;
    }

    i = 0;
    while (i < SEARCH)
    {
        fscanf(numbers, "%d", &value);
        if(!btSearch(bt, value)) {
                printf("Erro ao pesquisar na arvore.\n");
                return -1;
        }
        i++;
    }
    fclose(numbers);

    printf("Processo concluido com sucesso.\n");

    return 0;
}
