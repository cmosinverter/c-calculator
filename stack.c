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

void push(stack *s, float val) {
    s->array[++(s->top)] = val;
}

float pop(stack *s) {
    if (is_empty(s)) {
        return 0;
    }
    return s->array[(s->top)--];
}

float peek(stack *s) {
    if (is_empty(s)) {
        return 0;
    }
    return s->array[s->top];
}