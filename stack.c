#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void make_canary(struct Stack *stack) {
    stack->canary = 2448543;
    stack->memory[0] = stack->canary;
    stack->memory[1] = stack->canary;
    stack->num_of_elem = 2;
    return;
}

int verify_canary(struct Stack *stack) {
    if (stack->memory[0] == stack->memory[stack->num_of_elem]) {
        return 1;
    } else {
        return 0;
    }
}

void stack_init(struct Stack *stack) {
    stack->memory = (int*) malloc(8 * sizeof(int));
    stack->num_of_elem = 0;
    stack->size = 8 * sizeof(int);

    make_canary(stack);
    return;
}

void delete_stack(struct Stack *stack) {
    free(stack->memory);
    return;
}

void push(struct Stack *stack, int key) {
    stack->memory[stack->num_of_elem] = key;
    stack->num_of_elem++;
    stack->memory[stack->num_of_elem] = stack->canary;

    if ((stack->num_of_elem * sizeof(int)) == stack->size) {
        stack->memory = (int*) realloc(stack->memory, sizeof(int) * stack->num_of_elem * 2);
        stack->size *= 2;
    }

    return;
}

void pop(struct Stack *stack) {
    stack->num_of_elem--;

    if ((stack->num_of_elem * sizeof(int)) == stack->size / 4) {
        stack->memory = (int*) realloc(stack->memory, stack->size / 4);
        stack->size /= 4;
    }
}
