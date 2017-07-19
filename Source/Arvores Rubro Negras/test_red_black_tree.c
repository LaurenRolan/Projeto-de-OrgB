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
  srand(time(NULL));   // should only be called once
  int *newInt;
  int *array;
  int value;
  array = (int*) malloc(sizeof(int)*MAX_SIZE);
  newInt = (int*) malloc(sizeof(int*));	
   if(array == NULL)
   {
        printf("Vetor nao foi inicializado.\n");
        return 1;
   }
  if(newInt == NULL)
   {
        printf("Int nao foi inicializado.\n");
        return 1;
   }	
  rb_red_blk_node* newNode;
  rb_red_blk_tree* tree;

  /*cria a arvore*/
  tree=RBTreeCreate(IntComp,IntDest,InfoDest,IntPrint,InfoPrint);
  
 /*insercao na arvore*/
  for(i = 0; i < MAX_SIZE; i++){ //gera números aleatórios
	newInt=(int*) malloc(sizeof(int));
        *newInt = (rand()%MAX_VALUE)+1;
        array[i] = *newInt;
        RBTreeInsert(tree, newInt, (void*)1);
  }
	
  for(i = 0; i < SEARCH; i++){
        value = array[(rand()%MAX_SIZE)];
        if(( newNode = RBExactQuery(tree, &value) ) == NULL) {
                printf("Erro ao pesquisar na arvore.\n");
                return -1;
        }
  }
  printf("Processo concluido com sucesso.\n");
  return 0;
}
