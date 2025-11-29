#include "stack.h"

// Generic stack function implementations macro
#define IMPLEMENT_STACK_FUNCTIONS(type, suffix) \
void push_##suffix(stack_##suffix *stack, type val) { \
    stack->array[(stack->top)++] = val; \
} \
\
void pop_##suffix(stack_##suffix *stack, type *dst) { \
    *dst = stack->array[--(stack->top)]; \
}

// Implement stack functions for different types
IMPLEMENT_STACK_FUNCTIONS(float, v)
IMPLEMENT_STACK_FUNCTIONS(char, o)