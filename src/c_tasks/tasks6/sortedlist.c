#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    struct list *next;
}list;

void print(list **start)
{
    list *curr = *start;
    while (curr != NULL)
    {
        printf("%d\n",curr->data);
        curr = curr->next;
    }
}

void append(list **start,int new_val)
{
    list *new = malloc(sizeof(list));
    new->data = new_val;
    new->next = NULL;
    
    if (*start == NULL)
    {
        *start = malloc(sizeof(list));
        (*start)->data = new->data;
        (*start)->next = new->next;
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
        *start = (*start)->next;
    }

    list *curr = *start;
    while (curr->next != NULL)
    {
        if (curr->next->data == val)
        {
            curr->next = curr->next->next;
        }
        else
            curr = curr->next;
    }

}
int main()
{
    list *st = NULL;

    append(&st,12);
    append(&st,14);
    append(&st,13);
    append(&st,1);
    append(&st,10000);
    print(&st);
    return 0;
}
