#include <stdlib.h>
#include <assert.h>
#include "sortedlist.h"

void test_append_simple()
{
    printf("Test simple append: \n");
    list *start = NULL;
    append(&start,2);

    assert (start->data == 2);
    assert (start->next == NULL);
}

void test_append_multiply()
{
    printf("Test multipling append: \n");

    list *start = NULL;

    int added[] = {32,20,10,15};
    int sorted_added[] = {10,15,20,32};

    for (int i = 0; i < 4; ++i)
        append(&start,added[i]);
    
    for (int i = 0; i < 4; ++i)
    {
        assert (start->data == sorted_added[i]);
        start = start->next;
    }

    assert (start == NULL); 
}

void test_delet_empty()
{
    printf("Test deleting elements from empty list: \n");

    list *start = NULL;

    delet(&start, 42);
    assert(start == NULL);
}

void test_delet()
{
    printf("Test simple deleting element from list: \n");

    list *start = NULL;

    append(&start, 43);
    append(&start, 56);
    delet(&start, 43);

    assert(start->data == 56);
    assert(start->next == NULL);
}

void test_delet_middle()
{
    printf("Test deleting elements from middle of list: \n");

    list *start = NULL;

    append(&start, 89);
    append(&start, 90);
    append(&start, 90);
    append(&start, 90);
    append(&start, 1);

    delet(&start, 90);

    assert(start->data == 1);
    assert(start->next->data == 89);


}
int run_tests()
{
    printf("-----Test of Sorted list:----- \n");
    test_append_simple();
    test_append_multiply();
    test_delet_empty();
    test_delet();
    test_delet_middle();
    printf("Tests sucseed!\n");
    return 0;
}
