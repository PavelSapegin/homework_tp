#include "sortedlist.h"

void print(list **start)
{
    if (*start == NULL)
    {
        printf("Список пуст\n");
        return;
    }
    list *curr = *start;
    printf("\n");
    while (curr != NULL)
    {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
}

void append(list **start, int new_val)
{
    list *new = malloc(sizeof(list));
    new->data = new_val;
    new->next = NULL;

    if (*start == NULL)
    {
        *start = new;
        return;
    }

    // добавление элемента в голову списка
    if (new->data < (*start)->data)
    {
        new->next = *start;
        *start = new;
        return;
    }

    list *curr = *start;
    while (curr->next != NULL && curr->next->data < new->data)
        curr = curr->next;

    new->next = curr->next;
    curr->next = new;
}

void delete(list **start, int val)
{

    // удаляем элементы из головы
    while (*start != NULL && (*start)->data == val)
    {
        list *del = *start;
        *start = (*start)->next;
        free(del);
    }

    if (*start == NULL)
        return;

    // удаляем элементы из тела списка
    list *curr = *start;
    while (curr->next != NULL)
    {
        if (curr->next->data == val)
        {
            list *del = curr->next;
            curr->next = curr->next->next;
            free(del);
        }
        else
            curr = curr->next;
    }
}

void menu()
{
    printf("Привет, выберите пункт для работы в отсортированном списке\n");
    printf("0 - Выйти\n");
    printf("1 - Добавить значение\n");
    printf("2 - Удалить значение\n");
    printf("3 - Распечатать список\n");
}

void free_list(list **start)
{
    list *curr = *start;
    while (curr != NULL)
    {
        list *next = curr->next;
        free(curr);
        curr = next;
    }

    *start = NULL;
}
