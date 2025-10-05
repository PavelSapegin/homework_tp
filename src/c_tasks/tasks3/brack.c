#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000000];
    fgets(str, sizeof(str), stdin); // Считываем строку

    // Заводим счётчик и длину строки присваеваем переменной
    int count = 0;
    int len = strlen(str);

    // Проходимся по строке и считаем количество
    // открывающихся (+1) и закрывающихся (-1)
    // скобок
    // Если count != 0, то либо открывающихся,
    // либо закрывающихся скобок больше

    for (int i = 0; i < len; ++i)
    {

        if (str[i] == '(')
            count += 1;

        else if (str[i] == ')')
            count -= 1;

        if (count < 0)
        {
            printf("False");
            return 0;
        }
    }

    if (count == 0)
        printf("True");

    else
        printf("False");

    return 0;
}






