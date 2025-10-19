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
                if  ((top == NULL) || \
                    (str[i] == ')' && top->data != '(') || \
                    (str[i] == ']' && top->data != '[') || \
                    (str[i] == '}' && top->data != '{'))
                    return 0;
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
    scanf("%s",str);
    int res = check_brackets(str);
    printf("%d\n", res);
    return 0;
}
