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

int Evaluatepostfix(const char* postfix) {
    Stack value;
    CreateStack(&value);
    int result = 0;
    char num[10];
    int numIndex = 0;

    for (int i = 0; postfix[i]; i++) {
    	int output = postfix[i];

        if (isdigit(output)) {
            num[numIndex++] = output;
        } else if (output == ' ') {
            if (numIndex > 0) {
                num[numIndex] = '\0';
                push(&value,atoi(num) ); // push the number after converting it from string to number
                numIndex = 0;
            }
        } else {              // the output is operator
        	int val1 = pop(&value);
        	int val2 = pop(&value);
        	int tempResult;

            switch (output) {
                case '+': tempResult = val2 + val1; break;
                case '-': tempResult = val2 - val1; break;
                case '%': tempResult = val2 % val1; break;
                case '/': tempResult = val2 / val1; break;
                case '*': tempResult = val2 * val1; break;
                case '^': tempResult = val2 ^ val1; break;
                default:  tempResult = 0; break;
            }
            push(&value,tempResult );
        }
    }

    result = pop(&value);
    return result;
}


int main() {
    char infix[] = "3+5*2/(7-2)";
    char postfix[50];
     int result=0;
    infixToPost(infix, postfix);
    result= Evaluatepostfix(postfix);
    printf("Postfix: %s\n", postfix);
    printf("The final result: %d\n",result);

    return 0;
}
