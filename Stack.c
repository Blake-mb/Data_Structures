#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int size;
    int *arr;
    int top;
} Stack;

void init (Stack *stack, int size)
{
    stack->size = size;
    stack->arr = (int *)malloc(size * sizeof(int));
    stack->top = -1;    // Top is initialized as -1 so that when it is incremented in the push function, the top value is at position arr[top]
}

bool is_full (Stack *stack)
{
    if (stack->top >= stack->size) return true;   // This could probably be an '=='
    else return false;
}

bool is_empty (Stack *stack)
{
    if (stack->top == -1) return true;
    else return false;
}

void push (Stack *stack, int in_val)
{
    if (is_full(stack))
    {
        printf("This stack is full\n");
        return;
    }

    stack->top++;
    stack->arr[stack->top] = in_val;
}

int pop (Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Stack underflow!\n");
        return -1;
    }

    int out_val = stack->arr[stack->top];  
    stack->top--;   // NOTE: Decrementing top does not actually clear the memory address but allows it to be over written when push is next called
    return out_val;
}

int peek(Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Stack underflow!\n");
        return -1;
    }

    return stack->arr[stack->top];

}