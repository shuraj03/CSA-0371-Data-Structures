#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define the structure for the stack
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Function to initialize a stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow: Cannot push element %d\n", value);
        return;
    }
    stack->arr[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow: Cannot pop element\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Function to peek the top element of the stack
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}

int main() {
    struct Stack stack;
    initialize(&stack);
    
    // Push elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    
    // Peek at the top element
    printf("Top element: %d\n", peek(&stack));
    
    // Pop elements from the stack
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));
    
    // Try to pop from an empty stack
    printf("Popped element: %d\n", pop(&stack));
    
    return 0;
}
