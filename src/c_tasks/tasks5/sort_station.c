#include <stdio.h>
#include <string.h>
#include "stack.h"

int equivalention(char x) // Функция для сравнения операторов
{
    switch(x)
    {
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        default:
            return 0;
    }
}

void sort_station(const char str[])
{
    char nums[10] = "0123456789";
    char opers[4] = "+-*/";
    stack_obj *top = NULL;

    for (int i = 0; i < strlen(str); ++i)
    {
        if (str[i] != ' ')
        {
            if (strchr(nums,str[i]) != NULL)
                printf("%c ", str[i]);
        
            else if (strchr(opers,str[i]) != NULL)
            {
                while (top != NULL &&equivalention(str[i]) <= equivalention(top->data)) // Тут ошибка с равными операциями
                {
                    printf("%c ",top->data);
                    top = pop(top);
                }  
                top = push(top,str[i]);
            } 

            else if (str[i] == '(')
                top = push(top,str[i]);
            
            else if (str[i] == ')')
            {
                while (top->data != '(')
                {   
                    printf("%c ",top->data); 
                    top = pop(top);
                }
                top = pop(top);
            }   
        }   
    }
        

    while (top != NULL) // выводим всё, что осталось в стэке
    {
        printf("%c ", top->data);
        top = pop(top); 
    }
    printf("\n");
}

int main()
{
    char str[255];
    printf("Введите ваше выражение:\n");
    scanf("%s", str);
    sort_station(str);

    return 0;
}

