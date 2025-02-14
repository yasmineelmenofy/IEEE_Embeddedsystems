#include <stdio.h>
#include <stdlib.h>
#include "Stack_linkedbased.h"

int main()
{
    Stack s;
    CreateStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Stack size: %d\n", StackSize(&s));

    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));

    printf("Stack after popping:\n");
    TraverseStack(&s);

    ClearStack(&s);

    if (Is_StackEmpty(&s))
        printf("Stack is empty\n");

    return 0;
}
