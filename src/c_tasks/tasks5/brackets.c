#include "stack.h"
#include <stdio.h>
#include <string.h>

void free_stack(stack_obj* top)
{
    while (top != NULL)
        top = pop(top);
}

int check_brackets(char str[])
{
    stack_obj* top = NULL;
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            top = push(top, str[i]);
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if ((top == NULL) || (str[i] == ')' && top->data != '(') || (str[i] == ']' && top->data != '[') || (str[i] == '}' && top->data != '{')) {
                free_stack(top);
                return 0;
            }

            else
                top = pop(top);
        }
    }

    return top == NULL;
}
int main()
{
    char str[255];
    printf("Введите строку:\n");
    scanf("%s", str);
    int res = check_brackets(str);
    printf("%d\n", res);
    return 0;
}
