#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void CreateStack(Stack *s){
    s->top=-1;
}

int Is_StackFull(Stack *s){
 if(s->top == MAX_STACK-1)
    return 1;
  else
 return 0;
}

int Is_StackEmpty(Stack *s){
  if(s->top == -1)
    return 1;
  else
    return 0;
}

int StackSize(Stack *s){
 return s->top +1;
}

void push(Stack *s,Stack_Element data){
 if(Is_StackFull(s)){
    printf("Stack overflow \n");
    return;
 }else{
     s->top ++;
  s->arr[(s->top)]=data;
 }
}

Stack_Element pop(Stack *s){
 if(Is_StackEmpty(s)){
    printf("Stack under flow \n" );
    return -1;
 }else{
   Stack_Element data;
   data = s->arr[(s->top)--];
   return data;
 }
}

void ClearStack(Stack *s){
  s->top=-1;
}

int StackTop(Stack *s){
 if(Is_StackEmpty(s)){
    printf("Stack underflow \n");
    return -1;
 }else{
   return s->arr[s->top];
 }
}

void TraverseStack(Stack *s){
 if(Is_StackEmpty(s)){
    printf("Stack under flow \n" );
    return;
 }else{
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}
}