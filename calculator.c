#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

int is_operator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        return 1;
    } else {
        return 0;
    }
}

int get_priority(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;  // '(' or any other character
}

int priority_greater_or_equal(char a, char b) {
    return get_priority(a) >= get_priority(b);
}

float calculate(float val1, float val2, char op) {

    float res = 0;
    if (op == '+') {
        res = val1 + val2;
    } else if (op == '-') {
        res = val1 - val2;
    } else if (op == '*') {
        res = val1 * val2;
    } else if (op == '/') {
        res = val1 / val2;
    }
    return res;
}

int main(){

    char *input = malloc(sizeof(char) * BUFFER_SIZE);
    if (fgets(input, BUFFER_SIZE, stdin) == NULL) {
        fprintf(stderr, "Error reading input\n");
        return 1;
    }
    input[strcspn(input, "\n")] = '\0';

    stack *value_stack = stack_init();
    stack *operator_stack = stack_init();

    float val1, val2;
    float res;
    char op;

    char *c_num = malloc(sizeof(char) * BUFFER_SIZE);
    c_num[0] = '\0';
    int c_num_index = 0;

    for(int i = 0; i < strlen(input); i++) {
        if (input[i] >= 48 && input[i] <= 57) {
            c_num[c_num_index] = input[i];
            c_num[++c_num_index] = '\0';

        } else {

            if (c_num_index > 0) {
                push(value_stack, strtof(c_num, NULL));
                c_num_index = 0;
                c_num[0] = '\0';
            }

            if (input[i] == '(') {
                push(operator_stack, (float)input[i]);
            } else if (is_operator(input[i])) {
                while (!is_empty(operator_stack) && priority_greater_or_equal((char)peek(operator_stack), input[i])) {
                    val2 = pop(value_stack);
                    val1 = pop(value_stack);
                    op = (char)pop(operator_stack);
                    res = calculate(val1, val2, op);
                    push(value_stack, res);
                }
                push(operator_stack, (float)input[i]);
            } else if (input[i] == ')') {
                while ((char)peek(operator_stack) != '(') {
                    val2 = pop(value_stack);
                    val1 = pop(value_stack);
                    op = (char)pop(operator_stack);
                    res = calculate(val1, val2, op);
                    push(value_stack, res);
                }
                op = (char)pop(operator_stack);
            }
        }
    }

    if (c_num_index > 0) {
        push(value_stack, strtof(c_num, NULL));
        c_num_index = 0;
        c_num[0] = '\0';
    }

    while (!is_empty(operator_stack)) {
        val2 = pop(value_stack);
        val1 = pop(value_stack);
        op = (char)pop(operator_stack);
        res = calculate(val1, val2, op);
        push(value_stack, res);
    }

    printf("%f\n", peek(value_stack));

    free(input);
    free(c_num);
    free(value_stack);
    free(operator_stack);
    return 0;
}