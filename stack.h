#ifndef STACK_H
#define STACK_H

#define BUFFER_SIZE 1024

typedef struct {
    float array[BUFFER_SIZE];
    int top;
} v_stack;

typedef struct {
    char array[BUFFER_SIZE];
    int top;
} o_stack;

void push_v(v_stack *stack, float val);

void pop_v(v_stack *stack, float *dst);

void push_o(o_stack *stack, char val);

void pop_o(o_stack *stack, char *dst);

#endif