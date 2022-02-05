#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/**
 * OUTPUT_LANGUAGE = English
 * PROJECT_NAME = Stack
 * PROJECT_NUMBER = 1.0.0
 * PROJECT_BRIEF = A program with the implementation of a protected stack for a single data type
 * OUTPUT_DIRECTORY = /doc
 */

/**
 * @brief Entry point
 * @detailed Execution of the program
 * starts here.
 * @return Program exit status
 */

int main() {
    struct Stack stack;
    stack_init(&stack);
    push(&stack, 8);
    push(&stack, 8);
    push(&stack, 8);

    printf("%d \n", stack.size);
    printf("%d \n", stack.memory[2]);
    printf("%d \n", verify_canary(&stack));

    for (int i = 0; i < stack.num_of_elem + 2; i++) {
        printf("%d ", stack.memory[i]);
    }

    printf("\n %d \n", MurmurHash2(stack.memory, stack.num_of_elem+2));
    printf("%d \n", verify_hash(&stack));
    push(&stack, 8);
    printf("\n %d \n", MurmurHash2(stack.memory, stack.num_of_elem+2));
    pop(&stack);
    printf("\n %d \n", MurmurHash2(stack.memory, stack.num_of_elem+2));
    return 0;
}
