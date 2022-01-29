#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    struct Stack stack;
    stack_init(&stack);
    push(&stack, 8);
    push(&stack, 8);
    push(&stack, 8);
    push(&stack, 8);
    push(&stack, 8);
    push(&stack, 8);
    push(&stack, 8);
    push(&stack, 8);
    printf("%d \n", stack.size);
    printf("%d \n", verify_canary(&stack));
    return 0;
}
