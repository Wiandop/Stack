#ifndef STACK_STACK_H
#define STACK_STACK_H

struct Stack {
    int* memory;
    int size;
    int num_of_elem;
    int canary;
    int hash;
};

void make_canary(struct Stack *stack);
int verify_canary(struct Stack *stack);
void stack_init(struct Stack *stack);
void delete_stack(struct Stack *stack);
void push(struct Stack *stack, int key);
int pop(struct Stack *stack);
unsigned int MurmurHash2 (int *key, unsigned int len);
int verify_hash(struct Stack *stack);

#endif
