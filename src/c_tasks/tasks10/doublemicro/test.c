#include "double_conv.h"
#include <math.h>
#include <stdio.h>

void assert_test(Number input, char expected_sign, int expected_exp,
    double expected_man)
{
    ParsedDouble res = convert(input);

    char correct_man = fabs(res.man - expected_man) < 1e-9;
    char correct_exp = (res.exp == expected_exp);
    char correct_sign = (res.sign == expected_sign);

    if (correct_sign && correct_exp && correct_man) {
        printf("[OK] Тест пройден для %.6g\n", input.val);
    } else {
        printf("[FAIL] Тест провален для %.6g\n", input.val);
        printf("Expected: %c%.17g * 2^%d\n", expected_sign,
            expected_man, expected_exp);
        printf("\nGot: %c%.17g * 2^%d\n", res.sign, res.man, res.exp);
    }
}

void run_tests()
{
    printf("=== ЗАПУСК ТЕСТОВ ===\n\n");

    Number test1 = { .val = -2.5 };
    Number test2 = { .val = 12312.323 };
    Number test3 = { .val = -25.0 };
    Number test4 = { .val = 1.0 };

    assert_test(test1, '-', 1, 1.25);

    assert_test(test2, '+', 13, 1.5029691162109375);

    assert_test(test3, '-', 4, 1.5625);

    assert_test(test4, '+', 0, 1.0);

    printf("\n=== ТЕСТЫ ЗАВЕРШЕНЫ ===\n");
}
