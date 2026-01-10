#pragma once

typedef struct stack_obj {
    int data;
    struct stack_obj* next;
} stack_obj;

stack_obj* push(stack_obj* top, int value);
stack_obj* pop(stack_obj* top);
void show_stack(stack_obj* top);
