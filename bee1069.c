#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definindo a estrutura da pilha
typedef struct stack {
    int top;
    int *values;
} Stack;

// Função para criar uma nova pilha
Stack *Stack_Create() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = 0;
    stack->values = (int *)malloc(sizeof(int) * 100); // Tamanho fixo de 100 para a pilha
    return stack;
}

// Função para destruir a pilha
void Stack_Destroy(Stack *stack) {
    free(stack->values);
    free(stack);
}

// Função para verificar se a pilha está vazia
bool Stack_IsEmpty(Stack *stack) {
    return stack->top == 0;
}

// Função para adicionar um valor à pilha
void Stack_Push(Stack *stack, int value) {
    stack->values[stack->top] = value;
    stack->top += 1;
}

// Função para remover um valor da pilha
int Stack_Pop(Stack *stack) {
    stack->top -= 1;
    return stack->values[stack->top];
}

int main() {
    int N; // Número de casos de teste
    char diamante[1000]; // Buffer para a linha de entrada
    scanf("%d", &N);
    getchar(); // Consumir o caractere de nova linha após o número de casos

    // Processa cada caso de teste
    for (int i = 0; i < N; i++) {
        // Leitura da linha (cada caso de teste)
        scanf("%[^\n]", diamante);
        getchar(); // Consumir o caractere de nova linha após a entrada

        Stack *stack = Stack_Create();
        int cont = 0;

        // Processa a string
        for (int j = 0; diamante[j] != '\0'; j++) {
            if (diamante[j] == '<') {
                Stack_Push(stack, 1); // Adiciona um marcador para '<'
            } else if (diamante[j] == '>') {
                if (!Stack_IsEmpty(stack)) {
                    Stack_Pop(stack); // Remove um marcador para '<'
                    cont++; // Contabiliza um diamante
                }
            }
        }

        // Exibe o resultado para o caso de teste
        printf("%d\n", cont);
        
        // Destrói a pilha
        Stack_Destroy(stack);
    }

    return 0;
}
