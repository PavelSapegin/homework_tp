#include "stack.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int priority(char x) // Функция для сравнения операторов
{
    switch (x) {
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
    char opers[] = "+-*/";
    int n = strlen(str);
    stack_obj* top = NULL;

    for (int i = 0; i < n; ++i) {
        if (!isspace(str[i])) {
            if (isdigit(str[i])) {
                while (i < n && isdigit(str[i]))
                    printf("%c", str[i++]);
                printf(" ");
                i--;
            } else if (strchr(opers, str[i]) != NULL) {
                while (top != NULL && priority(str[i]) <= priority(top->data)) {
                    printf("%c ", top->data);
                    top = pop(top);
                }
                top = push(top, str[i]);
            }

            else if (str[i] == '(')
                top = push(top, str[i]);

            else if (str[i] == ')') {
                while (top != NULL && top->data != '(') {
                    printf("%c ", top->data);
                    top = pop(top);
                }
                if (top != NULL && top->data == '(')
                    top = pop(top);
            }
        }
    }

    while (top != NULL) // выводим всё, что осталось в стэке
    {
        if (top->data != '(')
            printf("%c ", top->data);
        top = pop(top);
    }
    printf("\n");
}

int main()
{
    char str[255];
    printf("Введите ваше выражение:\n");
    fgets(str, sizeof(str), stdin);
    sort_station(str);

    return 0;
}
