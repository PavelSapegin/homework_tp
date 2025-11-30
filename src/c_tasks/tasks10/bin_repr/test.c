#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "double_repr.h"


void assert_int(const char* test_name, short expected, short actual)
{
    if (expected == actual)
    {
        printf("[OK] %s: got %d\n",test_name,actual);
    }
    else
    {
        printf("[FAIL] %s : expected %d, got %d\n",test_name, 
            expected,actual);
    }
}

void assert_str(const char* test_name, char *expected, char *actual)
{
    if (strcmp(expected,actual) == 0)
    {
        printf("[OK] %s got: %s\n",test_name, actual);
    }
    else
    {
        printf("[FAIL] %s: expected %s, got %s\n", test_name,
        expected, actual);
    }
    free(actual);
}


void run_tests()
{
    printf("=== ЗАПУСК ТЕСТОВ ===\n\n");

    // тесты bin_to_dec
    assert_int("Ноль в десятичном виде", 0, bin_to_dec("0000000000000000"));
    assert_int("Один в десятичном виде", 1, bin_to_dec("0000000000000001"));
    assert_int("Пять в десятичном виде", 5, bin_to_dec("0000000000000101"));
    assert_int("Минус один в десятичном виде", -1, bin_to_dec("1111111111111111"));
    assert_int("Максимальное (short)", 32767, bin_to_dec("0111111111111111"));
    assert_int("Минимальное (short)", -32768, bin_to_dec("1000000000000000"));
    printf("\n");

    // тесты bin_sum
    assert_str("0 + 0", 
               "0000000000000000", 
               bin_sum("0000000000000000", "0000000000000000"));
    
    assert_str("1 + 1", 
               "0000000000000010", 
               bin_sum("0000000000000001", "0000000000000001"));
      
    assert_str("-1 + 1", 
               "0000000000000000", 
               bin_sum("1111111111111111", "0000000000000001"));

    printf("\n=== ТЕСТЫ ЗАВЕРШЕНЫ ===\n");
}


