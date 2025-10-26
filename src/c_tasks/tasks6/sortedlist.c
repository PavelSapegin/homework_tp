#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
} list;

void print(list **start)
{
    list *curr = *start;
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

    if (new->data < (*start)->data)
    {
        int tmp_data = (*start)->data;

        (*start)->data = new->data;
        new->data = tmp_data;
        new->next = (*start)->next;
        (*start)->next = new;
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
    if (*start == NULL)
        return;

    while ((*start)->next != NULL && (*start)->data == val)
    {
        list *del = *start;
        *start = (*start)->next;
        free(del);
    }

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

void spaces()
{
    for (int i = 0; i < 1000; ++i)
        printf("             \n");
}

void menu()
{
    printf("Привет, выберите пункт для работы в отсортированном списке\n");
    printf("0 - Выйти\n");
    printf("1 - Добавить значение\n");
    printf("2 - Удалить значение\n");
    printf("3 - Распечатать список\n");
}
int main()
{
    list *st = NULL;
    int choice = -10;

    
    while (1)
    {

        printf("\n");
        menu();
        if (scanf("%d",&choice) !=1 || choice < 0 || choice > 3)
        {
            spaces();
            printf("Ошибка ввода");
            continue;
        }

        switch(choice)
        {
            case 0:
                return 0;
            
            case 1:
            {
                int num;
                printf("Введите значение:\n");
                if (scanf("%d",&num) == 1)
                {
                    append(&st,num);
                    spaces();
                    printf("Значение успешно добавлено!\n");
                }
                else
                    {
                    spaces();
                    printf("Ошибка\n");
                    }
                break;
            }
            case 2:
            {
                int num;
                printf("Введите значение:\n");
                if (scanf("%d",&num) == 1)
                {
                    delete(&st,num);
                    spaces();
                    printf("Значение успешно удалено!");
                }
                
                break;
            }
            case 3:
            {
                spaces();
                print(&st);
                break;
            }
        }
    }
    return 0;
}
