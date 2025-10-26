#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int status;
    struct list *next;
} list;

// функция для начального заполнения статусов воинам
void fill(list **start, int n)
{
    list *curr = *start;
    (*start)->status = 1;
    for (int i = 0; i < n - 1; ++i)
    {
        list *new = malloc(sizeof(list));
        new->status = 1;
        curr->next = new;
        curr = curr->next;
    }

    curr->next = *start;
}

int kill(list **start, int n, int m)
{
    int war = n;   // счётчик выживших
    int count = 0; // счётчик для выбора, кого убить
    list *curr = *start;

    while (war > 1)
    {
        if (count == m && curr->status != 0)
        {
            curr->status = 0;
            war--;
            count = 0;
        }
        else if (curr->status != 0)
        {
            count++;
        }

        curr = curr->next;
    }

    // находим выжевшего
    list *checker = *start;
    int k = 0;
    while (checker->status != 1)
    {
        k++;
        checker = checker->next;
    }
    return k + 1;
}
int main()
{
    int n, m;
    printf("Введите числа n и m:\n");
    if (scanf("%d %d", &n, &m) != 2)
    {
        printf("Данные введены некорректно\n");
        return 42;
    }

    list *st;
    fill(&st, n);
    int res = kill(&st, n, m);
    printf("Чтобы выжить нужно встать %d-им/ым\n", res);
    return 0;
}
