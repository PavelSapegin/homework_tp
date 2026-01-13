#include <stdio.h>

int main()
{
    int x;
    int x_2;
    long long res;

    scanf("Введите число: %d\n", &x);

    x_2 = x * x;
    res = x_2 * (x_2 + x + 1) + 1;

    printf("%lld\n", res);

    return 0;
}