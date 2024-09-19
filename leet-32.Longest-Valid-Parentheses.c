#include <stdlib.h>
#include <stdio.h>

typedef struct Stack {
    int top;
    int *values;
} Stack;

Stack *Stack_Create() {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->top = 0;
    stack->values = (int *) malloc(sizeof(int) * 100);
    return stack;
}

void Stack_Destroy(Stack *stack) {
    free(stack->values);
    free(stack);
}

int Stack_IsEmpty(Stack *stack) {
    return stack->top == 0;
}

void Stack_Push(Stack *stack, int value) {
    *(stack->values + stack->top) = value;
    stack->top += 1;
}

int Stack_Pop(Stack *stack) {
    stack->top -= 1;
    int value = *(stack->values + stack->top);
    return value;
}

int countValidParentheses(char *s) {
    Stack *stack = Stack_Create();
    int count = 0;

    // Usando um loop for com índice i
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            Stack_Push(stack, 1);
        } else if (s[i] == ')') {
            if (!Stack_IsEmpty(stack)) {
                Stack_Pop(stack);
                count += 2;
            }
        }
    }

    Stack_Destroy(stack);
    return count;
}

int main() {
    char s1[] = "(1+(2*3)+((8)/4))+1";
    char s2[] = "(1)+((2))+(((3)))";
    char s3[] = "()(())((()()))";

    printf(" %d\n", countValidParentheses(s1));
    printf(" %d\n", countValidParentheses(s2));
    printf(" %d\n", countValidParentheses(s3));

    return 0;
}
