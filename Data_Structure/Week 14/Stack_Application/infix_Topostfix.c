#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Stack.h"


int preced(char op) {
    switch(op) {
        case '^': return 3;
        case '*': case '/': case '%': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

void infixToPost(const char *infix, char *postfix) {
    Stack op;
    CreateStack(&op);

    int j = 0;
    char num[10];
    int numIndex = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char input = infix[i];

        if (isdigit(input)) {
            num[numIndex++] = input;
        } else {
            if (numIndex > 0) {
                num[numIndex] = '\0';
                for (int k = 0; num[k] != '\0'; k++) {
                    postfix[j++] = num[k];
                }
                postfix[j++] = ' ';
                numIndex = 0;
            }

            if (input == '(') {
                push(&op, input);
            } else if (input == ')') {
                while (!Is_StackEmpty(&op) && StackTop(&op) != '(') {
                    postfix[j++] = pop(&op);
                    postfix[j++] = ' ';
                }
                pop(&op);
            } else {
                while (!Is_StackEmpty(&op) && preced(StackTop(&op)) >= preced(input)) {
                    postfix[j++] = pop(&op);
                    postfix[j++] = ' ';
                }
                push(&op, input);
            }
        }
    }

    if (numIndex > 0) {
        num[numIndex] = '\0';
        for (int k = 0; num[k] != '\0'; k++) {
            postfix[j++] = num[k];
        }
        postfix[j++] = ' ';
    }

    while (!Is_StackEmpty(&op)) {
        postfix[j++] = pop(&op);
        postfix[j++] = ' ';
    }

    postfix[j] = '\0';
}

int main() {
    char infix[] = "3+5*2/(7-2)";
    char postfix[50];

    infixToPost(infix, postfix);
    printf("Postfix: %s\n", postfix);

    return 0;
}
