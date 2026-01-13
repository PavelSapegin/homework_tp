#include "double_repr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc > 1 && strcmp(argv[1], "--test") == 0) {
        run_tests();
        return 0;
    }
    short num1, num2;
    printf("Введите два числа через пробел:");
    if (scanf("%hd %hd", &num1, &num2) != 2) {
        printf("Неккоректный ввод");
        return 1;
    }

    char* str_num1 = to_bin(num1);
    char* str_num2 = to_bin(num2);
    printf("Числа в дополнительном коде:\n");
    printf("%s\n", str_num1);
    printf("%s\n", str_num2);

    char* sum_bin = bin_sum(str_num1, str_num2);
    short sum_dec = bin_to_dec(sum_bin);

    printf("Сумма чисел в двоичном виде:\n");
    printf("%s\n", sum_bin);
    printf("Сумма чисел в десятичном виде:\n");
    printf("%hd\n", sum_dec);

    free(str_num1);
    free(str_num2);
    free(sum_bin);
    return 0;
}
