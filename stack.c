#include "stack.h"
#include <stdlib.h>

// Generic stack function implementations macro
#define IMPLEMENT_STACK_FUNCTIONS(type, suffix) \
stack_##suffix *stack_##suffix##_init() { \
    stack_##suffix *stack = malloc(sizeof(stack_##suffix)); \
    if (stack) stack->top = -1; \
    return stack; \
} \
\
int is_empty_##suffix(stack_##suffix *stack) { \
    return stack->top == -1; \
} \
void push_##suffix(stack_##suffix *stack, type val) { \
    stack->array[++(stack->top)] = val; \
} \
\
type pop_##suffix(stack_##suffix *stack) { \
    if (is_empty_##suffix(stack)) { \
        return 0; \
    } \
    return stack->array[(stack->top)--]; \
} \
type peek_##suffix(stack_##suffix *stack) { \
    if (is_empty_##suffix(stack)) { \
        return 0; \
    } \
    return stack->array[stack->top]; \
}

// Implement stack functions for different types
IMPLEMENT_STACK_FUNCTIONS(float, v)
IMPLEMENT_STACK_FUNCTIONS(char, o)