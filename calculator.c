#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

int is_operator(char *ch) {
    if (*ch == '+' || *ch == '-' || *ch == '*' || *ch == '/') {
        return 1;
    } else {
        return 0;
    }
}

int op_geq(char *a, char *b) {

    int op_a = 0;
    int op_b = 0;

    if (*a == '(') {
        op_a = 0;
    } else if (*a == '+' || *a == '-') {
        op_a = 1;
    } else if (*a == '*' || *a == '/') {
        op_a = 2;
    }

    if (*b == '(') {
        op_b = 0;
    } else if (*b == '+' || *b == '-') {
        op_b = 1;
    } else if (*b == '*' || *b == '/') {
        op_b = 2;
    }

    return op_a >= op_b;
}

float calculate(float val1, float val2, char *op) {

    float res = 0;
    if (*op == '+') {
        res = val1 + val2;
    } else if (*op == '-') {
        res = val1 - val2;
    } else if (*op == '*') {
        res = val1 * val2;
    } else if (*op == '/') {
        res = val1 / val2;
    }
    return res;
}

int main(){
    
    char *input = malloc(sizeof(char) * BUFFER_SIZE);
    fgets(input, BUFFER_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0';

    stack_o stack_o = {0};
    stack_v stack_v = {0};

    float val1, val2;
    int res;
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
                push_v(&stack_v, strtof(c_num, NULL));
                c_num_index = 0;
                c_num[0] = '\0';
            }

            if (input[i] == '(') {
                push_o(&stack_o, input[i]);
            } else if (is_operator(input+i)) {
                while (stack_o.top > 0 && op_geq(&stack_o.array[stack_o.top-1], input+i)) {
                    pop_v(&stack_v, &val2);
                    pop_v(&stack_v, &val1);
                    pop_o(&stack_o, &op);
                    res = calculate(val1, val2, &op);
                    push_v(&stack_v, res);
                }
                push_o(&stack_o, input[i]);
            } else if (input[i] == ')') {
                while (stack_o.array[stack_o.top - 1] != '(') {
                    pop_v(&stack_v, &val2);
                    pop_v(&stack_v, &val1);
                    pop_o(&stack_o, &op);
                    res = calculate(val1, val2, &op);
                    push_v(&stack_v, res);
                }
                pop_o(&stack_o, &op);
            }
        }
    }

    if (c_num_index > 0) {
        push_v(&stack_v, strtof(c_num, NULL));
        c_num_index = 0;
        c_num[0] = '\0';
    }

    while (stack_o.top > 0) {
        pop_v(&stack_v, &val2);
        pop_v(&stack_v, &val1);
        pop_o(&stack_o, &op);
        res = calculate(val1, val2, &op);
        push_v(&stack_v, res);
    }

    printf("%f\n", stack_v.array[0]);

    free(input);
    free(c_num);
    return 0;
}