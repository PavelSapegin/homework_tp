#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Структура списков f и r
typedef struct list {
    int val;
    struct list* next;
} list;

// Структура очереди
typedef struct queue {
    list* f;
    list* r;
} queue;

// Добавление в начала списка
list* add(int val, list* start)
{
    list* new = malloc(sizeof(list));
    new->val = val;
    new->next = start;
    return new;
}

// Реверс списка
list* reverse(list* start)
{
    list* new = NULL;

    while (start != NULL) {
        new = add(start->val, new);
        start = start->next;
    }

    return new;
}

// Перенаправление r в f, если f пустой
queue redirect(list* f, list* r)
{
    if (f == NULL) {
        f = reverse(r);
        r = NULL;
    }

    return (queue) { f, r };
}

// Добавление в очередь
queue enqueue(queue q, int x)
{
    list* temp = add(x, q.r);
    return redirect(q.f, temp);
}

// Удаление из очереди
queue dequeue(queue q, int* out_val)
{
    if (q.f == NULL) {
        printf("Error. Queue is empty\n");
        return (queue) { NULL, NULL };
    }

    *out_val = q.f->val;
    return redirect(q.f->next, q.r);
}

int main()
{

    printf("TEST FIFO:...\n");
    queue q_test1 = { NULL, NULL };
    int x_test1;

    q_test1 = enqueue(q_test1, 1);
    q_test1 = enqueue(q_test1, 2);
    q_test1 = enqueue(q_test1, 3);

    q_test1 = dequeue(q_test1, &x_test1);
    assert(x_test1 == 1);
    q_test1 = dequeue(q_test1, &x_test1);
    assert(x_test1 == 2);
    q_test1 = dequeue(q_test1, &x_test1);
    assert(x_test1 == 3);

    assert((q_test1.f == NULL) && (q_test1.r == NULL));

    printf("TEST ROTATION:...");
    queue q_test2 = { NULL, NULL };
    int x_test2;

    q_test2 = enqueue(q_test2, 1);
    q_test2 = enqueue(q_test2, 2);
    q_test2 = dequeue(q_test2, &x_test2);

    assert(q_test2.f != NULL && q_test2.f->val == 2);
    assert(q_test2.r == NULL);
    q_test2 = enqueue(q_test2, 3);

    return 0;
}
