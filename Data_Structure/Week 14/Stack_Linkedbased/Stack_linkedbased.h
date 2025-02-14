#ifndef STACK_LINKEDBASED_H_INCLUDED
#define STACK_LINKEDBASED_H_INCLUDED

typedef int Stack_Element;

typedef struct StackNode{
   Stack_Element data;
   struct StackNode *link;
}StackNode;

typedef struct Stack{
   StackNode *top;
   int Size;
}Stack;

void CreateStack(Stack *s);
int Is_StackFull(Stack *s);
int Is_StackEmpty(Stack *s);
int StackSize(Stack *s);
void push(Stack *s, Stack_Element data);
Stack_Element pop(Stack *s);
void ClearStack(Stack *s);
void TraverseStack(Stack *s);


#endif // STACK_LINKEDBASED_H_INCLUDED
