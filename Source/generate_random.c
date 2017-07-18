#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_SIZE 10000
#define MAX_VALUE 2000

int main(){
    long unsigned int i;
    srand(time(NULL));   // should only be called once
    unsigned int r;
    FILE *f = fopen("file.txt", "w");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    for(i = 0; i < MAX_SIZE; i++){
        r = (rand()%MAX_VALUE)+1;
        fprintf(f, "%d ", r);
    }
    printf("Processo concluido com sucesso.\n");
    return 0;
}
