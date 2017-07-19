#include"red_black_tree.h"
#include<stdio.h>
#include<ctype.h>
#define MAX_INSERCAO 5000
#define MAX_PESQUISA 100

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
  int* newInt;
	
  FILE *arq;
  rb_red_blk_node* newNode;
  rb_red_blk_tree* tree;

  /*cria a arvore*/
  tree=RBTreeCreate(IntComp,IntDest,InfoDest,IntPrint,InfoPrint);
  arq = fopen("file.txt", "r");
  if(arq == NULL)
  {
    printf("Erro na abertura dos numeros\n");
  }


 /*insercao na arvore*/
  while(i<MAX_INSERCAO)
  {
    newInt=(int*) malloc(sizeof(int));
    fscanf(arq, "%d", newInt);
   /* printf("%d - ", *newInt);*/
    RBTreeInsert(tree,newInt,(void*)1);
    i++;
  }

  i=0;
  while(i<MAX_PESQUISA)
  {	
    /*newInt=(int*) malloc(sizeof(int));*/
    fscanf(arq, "%d", newInt);
    printf("%d - ", *newInt);
    if ( ( newNode = RBExactQuery(tree,newInt) ) != NULL) {/*assignment*/
      printf("data found in tree at location %i\n",(int)newNode);
    } else {
      printf("data not in tree\n");
    }
	i++;
  }

  fclose(arq);
    
   /* RBTreePrint(tree);*/

    return 0;
}










