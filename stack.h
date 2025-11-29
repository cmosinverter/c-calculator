#ifndef STACK_H
#define STACK_H

#define BUFFER_SIZE 1024

// Unified stack using float to store both values and operators
typedef struct {
    float array[BUFFER_SIZE];
    int top;
} stack;

// Stack function declarations
stack *stack_init();
int is_empty(stack *s);
void push(stack *s, float val);
float pop(stack *s);
float peek(stack *s);

#endif