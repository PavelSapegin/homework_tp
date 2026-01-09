#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int id;
    struct list* next;
} list;

// функция для начального заполнения статусов воинам
void fill(list** start, int n)
{
    if (n <= 0)
        return;

    *start = malloc(sizeof(list));
    (*start)->id = 1;
    list* curr = *start;
    int to_id = 2;

    for (int i = 0; i < n - 1; ++i) {
        list* new = malloc(sizeof(list));
        new->id = to_id++;
        curr->next = new;
        curr = curr->next;
    }

    curr->next = *start;
}

int kill(list* start, int m)
{
    list* curr = start;
    list* prev = start;

    // ставим prev в хвост списка
    while (prev->next != start)
        prev = prev->next;

    while (curr->next != curr) {
        for (int i = 1; i < m; ++i) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        free(curr);
        curr = prev->next;
    }

    int win_id = curr->id;
    free(curr);
    return win_id;
}
int main()
{
    int n, m;
    printf("Введите числа n и m:\n");
    if (scanf("%d %d", &n, &m) != 2 || n <= 0 || m <= 0) {
        printf("Данные введены некорректно\n");
        return 42;
    }

    list* st = NULL;
    fill(&st, n);
    int res = kill(st, m);
    printf("Чтобы выжить нужно встать %d-им/ым\n", res);
    return 0;
}
