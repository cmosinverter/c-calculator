#ifndef STACK_H
#define STACK_H

#define BUFFER_SIZE 1024

// Generic stack definition macro
#define DEFINE_STACK_TYPE(type, suffix) \
typedef struct { \
    type array[BUFFER_SIZE]; \
    int top; \
} stack_##suffix

// Generic stack function declarations macro
#define DECLARE_STACK_FUNCTIONS(type, suffix) \
void push_##suffix(stack_##suffix *stack, type val); \
void pop_##suffix(stack_##suffix *stack, type *dst)

// Define stack types
DEFINE_STACK_TYPE(float, v);
DEFINE_STACK_TYPE(char, o);

// Declare stack functions
DECLARE_STACK_FUNCTIONS(float, v);
DECLARE_STACK_FUNCTIONS(char, o);

#endif