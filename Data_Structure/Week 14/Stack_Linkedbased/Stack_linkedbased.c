#include <stdio.h>
#include <stdlib.h>
#include "Stack_linkedbased.h"


void CreateStack(Stack *s){
 s->top=NULL;
 s->Size=0;
}


int Is_StackFull(Stack *s){
   return 0;
}

int Is_StackEmpty(Stack *s){
   return s->top==NULL;
}

int StackSize(Stack *s){
   return s->Size;
}

void push(Stack *s, Stack_Element data){
      StackNode *n =(StackNode*)malloc(sizeof(StackNode));
      n->data=data;
      n->link=s->top;
      s->top=n;
      s->Size++;
}

Stack_Element pop(Stack *s){
  StackNode *n=s->top;
  Stack_Element value;
  value=s->top->data;
  s->top=s->top->link;
  free(n);
  n=NULL;
  s->Size--;
  return value;
}

void ClearStack(Stack *s){
  StackNode *n;
  while(! Is_StackEmpty(s)){
    n=s->top;
    s->top=s->top->link;
    free(n);
  }
  n=NULL;
  s->Size=0;
}

void TraverseStack(Stack *s){
  if(Is_StackEmpty(s)){
    printf("stack underflow");
  }else{
    Stack_Element value;
    while( ! Is_StackEmpty(s)){
    value=pop(s);
    printf("%d",value);
    printf(" ");
    }
     printf("\n");
  }
}
