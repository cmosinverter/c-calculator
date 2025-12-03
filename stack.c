#include "stack.h"
#include <stdlib.h>

stack *stack_init() {
    stack *s = malloc(sizeof(stack));
    if (s) {
        s->top = -1;
    }
    return s;
}

int is_empty(stack *s) {
    return s->top == -1;
}

int is_full(stack *s) {
    return s->top >= BUFFER_SIZE - 1;
}

void push(stack *s, float val) {
    if (is_full(s)) {
        return; // Stack overflow protection
    }
    s->top++;
    s->array[s->top] = val;
}

float pop(stack *s) {
    if (is_empty(s)) {
        return 0;
    }
    float val = s->array[s->top];
    s->top--;
    return val;
}

float peek(stack *s) {
    if (is_empty(s)) {
        return 0;
    }
    return s->array[s->top];
}