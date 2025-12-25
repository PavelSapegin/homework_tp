#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "sortedlist.h"

void test_append_simple()
{
    printf("Test simple append: ");
    list *start = NULL;
    append(&start,2);

    assert (start->data == 2);
    assert (start->next == NULL);
    free_list(&start);
    printf("OK\n");
}

void test_append_multiply()
{
    printf("Test multipling append: ");

    list *start = NULL;

    int added[] = {32,20,10,15};
    int sorted_added[] = {10,15,20,32};

    for (int i = 0; i < 4; ++i)
        append(&start,added[i]);
    
    list *curr = start;
    for (int i = 0; i < 4; ++i)
    {
        assert (curr->data == sorted_added[i]);
        curr = curr->next;
    }

    assert (curr == NULL); 
    free_list(&start);
    printf("OK\n");
}

void test_delete_empty()
{
    printf("Test deleting elements from empty list: ");

    list *start = NULL;

    delete(&start, 42);
    assert(start == NULL);
    printf("OK\n");
}

void test_delete()
{
    printf("Test simple deleting element from list: ");

    list *start = NULL;

    append(&start, 43);
    append(&start, 56);
    delete(&start, 43);

    assert(start->data == 56);
    assert(start->next == NULL);
    free_list(&start);
    printf("OK\n");
}

void test_delete_middle()
{
    printf("Test deleting elements from middle of list: ");

    list *start = NULL;

    append(&start, 89);
    append(&start, 90);
    append(&start, 90);
    append(&start, 90);
    append(&start, 1);

    delete(&start, 90);

    assert(start->data == 1);
    assert(start->next->data == 89);
    free_list(&start);
    printf("OK\n");

}

void test_delete_all()
{
    printf("Test deleting all elements from list: ");

    list *start = NULL;

    append(&start,42);     
    append(&start,42);

    delete(&start,42);
    assert (start == NULL);
    free_list(&start);
    printf("OK\n");
}

void test_delete_not_existing()
{
    printf("Test deleting not existing element from list: ");

    list *start = NULL;

    append(&start, 78);
    append(&start,12);

    delete(&start, 10);

    assert (start->data == 12);
    assert (start->next->data == 78);
    free_list(&start);
    printf("OK\n");

}
int run_tests()
{
    printf("-----Test of Sorted list:----- \n");
    test_append_simple();
    test_append_multiply();
    test_delete_empty();
    test_delete();
    test_delete_middle();
    test_delete_all();
    test_delete_not_existing();
    printf("Tests succeed!\n");
    return 0;
}


