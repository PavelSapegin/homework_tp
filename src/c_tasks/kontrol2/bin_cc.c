#include <stdbool.h>
#include <stdio.h>

int srav(bool a[], bool b[], size_t len_a, size_t len_b)
{

    int idxa = len_a;
    int idxb = len_b;

    for (int i = 0; i < len_a; ++i) {
        if (a[i] == 1) {
            idxa = i;
            break;
        }
    }

    for (int i = 0; i < len_b; ++i) {
        if (b[i] == 1) {
            idxb = i;
            break;
        }
    }

    size_t true_len_a = len_a - idxa;
    size_t true_len_b = len_b - idxb;

    if (true_len_a > true_len_b) {
        return 1;
    } else if (true_len_a < true_len_b) {
        return 2;
    }

    for (int i = idxa; i < len_a; ++i) {
        if (a[i] > b[i]) {
            return 1;
        } else if (a[i] < b[i]) {
            return 2;
        }
    }

    return 3;
}

int main()
{
    // Пример
    bool a[8] = { 0, 0, 0, 0, 1, 0, 0, 0 };
    bool b[8] = { 0, 0, 1, 0, 0, 0, 0, 0 };
    res = srav(a, b, 8, 8);
    if (res == 1)
        printf("Первое число больше");
    else if (res == 2)
        printf("Второе число больше");

    else if (res == 3)
        printf("Числа равны");

    return 0;
}
