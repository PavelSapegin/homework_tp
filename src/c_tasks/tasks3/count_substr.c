#include <stdio.h>
#include <string.h>

int main()
{
    // Заводим строки
    char s[1000000];
    char s1[1000000];

    // Считываем строки
    scanf("%[^\n]\n",s);
    scanf("%[^\n]",s1);

    // Для дальнейшей работы со строками
    // длины их строк присваиваем переменным
    // и создаем счетчик вхождений

    int lens1 = strlen(s);
    int step = strlen(s1);
    int count = 0;


    // Перебираем все подстроки длинной строки s1
    for (int start = 0; start + step <= lens1; ++start)
    {
        char sub[start + step];

        // собираем подстроку
        for (int i = 0; i < step; ++i)
        {
            sub[i] = s[start + i];
        }

        sub[start + step] = '\0';

        if (strcmp(s1, sub) == 0)
            count++;
    }

    printf("%d\n", count);
    return 0;
}




