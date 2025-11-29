#include "stack.h"

void push_v(v_stack *stack, float val) {
    stack->array[(stack->top)++] = val;
}

void pop_v(v_stack *stack, float *dst) {
    *dst = stack->array[--(stack->top)];
}

void push_o(o_stack *stack, char val) {
    stack->array[(stack->top)++] = val;
}

void pop_o(o_stack *stack, char *dst) {
    *dst = stack->array[--(stack->top)];
}