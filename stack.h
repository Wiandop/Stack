#ifndef STACK_STACK_H
#define STACK_STACK_H

struct Stack {
    int* memory;
    int size;
    int num_of_elem;
    int canary;
    // hash
};

void make_canary(struct Stack *stack);
int verify_canary(struct Stack *stack);
void stack_init(struct Stack *stack);
void delete_stack(struct Stack *stack);
void push(struct Stack *stack, int key);
void pop(struct Stack *stack);

#endif
