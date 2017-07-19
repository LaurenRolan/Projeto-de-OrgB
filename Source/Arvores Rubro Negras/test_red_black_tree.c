#include"red_black_tree.h"
#include<stdio.h>
#include<ctype.h>
#define MAX_SIZE 10000
#define SEARCH 1000
#define MAX_VALUE 2000

/*  this file has functions to test a red-black tree of integers */

void IntDest(void* a) {
  free((int*)a);
}



int IntComp(const void* a,const void* b) {
  if( *(int*)a > *(int*)b) return(1);
  if( *(int*)a < *(int*)b) return(-1);
  return(0);
}

void IntPrint(const void* a) {
  printf("%i",*(int*)a);
}

void InfoPrint(void* a) {
  ;
}

void InfoDest(void *a){
  ;
}

int main()
{
  int i =0;
  int value, j;
  srand(time(NULL));   // should only be called once
  unsigned int r;
  int *array;
  array = (int*) malloc(sizeof(int)*MAX_SIZE);
	
   if(array == NULL)
   {
        printf("Vetor não foi inicializado.\n");
        return 1;
   }
	
  //FILE *arq;
  rb_red_blk_node* newNode;
  rb_red_blk_tree* tree;

  /*cria a arvore*/
  tree=RBTreeCreate(IntComp,IntDest,InfoDest,IntPrint,InfoPrint);
  /*arq = fopen("file.txt", "r");
  if(arq == NULL)
  {
    printf("Erro na abertura dos numeros\n");
  }*/


 /*insercao na arvore*/
  for(i = 0; i < MAX_SIZE; i++){ //gera números aleatórios
        r = (rand()%MAX_VALUE)+1;
        array[i] = r;
        RBTreeInsert(tree, &r, (void*)1);
  }
	/*
  while(i<MAX_SIZE)
  {
    newInt=(int*) malloc(sizeof(int));
    fscanf(arq, "%d", newInt);
    printf("%d - ", *newInt);
    
    i++;
  }
	*/
  for(i = 0; i < SEARCH; i++){
        value = array[(rand()%MAX_SIZE)];
        if(( newNode = RBExactQuery(tree, &value) ) == NULL) {
                printf("Erro ao pesquisar na arvore.\n");
                return -1;
        }
  }
	/*
  while(i<MAX_PESQUISA)
  {	
    newInt=(int*) malloc(sizeof(int));
    fscanf(arq, "%d", newInt);
    printf("%d - ", *newInt);
    if ( ( newNode = RBExactQuery(tree,newInt) ) != NULL) {assignment
      printf("data found in tree at location %i\n",(int)newNode);
    } else {
      printf("data not in tree\n");
    }
	i++;
  }

  fclose(arq);
 */   
   /* RBTreePrint(tree);*/
	printf("Processo concluido com sucesso.\n");
    return 0;
}
