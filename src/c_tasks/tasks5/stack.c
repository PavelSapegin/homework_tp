#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

stack_obj* push(stack_obj* top, int value)
{
    stack_obj* new = malloc(sizeof(stack_obj));
    new->data = value;
    new->next = top;

    return new;
}

stack_obj* pop(stack_obj* top)
{
    if (top == NULL)
        return NULL;

    stack_obj* new_top = top->next;

    return new_top;
}

void show_stack(stack_obj* top)
{
    stack_obj* curr = top;
    while (curr != NULL) {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
}
