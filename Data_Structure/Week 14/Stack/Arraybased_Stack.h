#ifndef ARRAYBASED_STACK_H_INCLUDED
#define ARRAYBASED_STACK_H_INCLUDED

#define MAX_STACK  100
typedef int Stack_Element;

typedef struct {
 Stack_Element arr[MAX_STACK];
 int top;
}Stack;

void CreateStack(Stack *s);
int Is_StackFull(Stack *s);
int Is_StackEmpty(Stack *s);
int StackSize(Stack *s);
void push(Stack *s, Stack_Element data);
Stack_Element pop(Stack *s);
void ClearStack(Stack *s);
int StackTop(Stack *s);
void TraverseStack(Stack *s);


#endif // ARRAYBASED_STACK_H_INCLUDED
