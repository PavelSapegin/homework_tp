#include <stdio.h>
#include "stack.h"
#include <string.h>

int check_brackets(char str[])
{
    stack_obj *top = NULL;

        for (int i = 0; i < strlen(str); ++i)
        {
            if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            {
                top = push(top, str[i]);
            }
            else
            {
                if ((str[i] == ')' && top->data != '(') || \
                    (str[i] == ']' && top->data != '[') || \
                    (str[i] == '}' && top->data != '{') || \
                     (top == NULL))
                    return 0;
                else
                    top = pop(top);
            }   

        }
    return 1;
}
int main()
{
    char str[] = "{}{}()[]"; //({[]})
    int res = check_brackets(str);
    printf("%d\n", res);
    return 0;
}
