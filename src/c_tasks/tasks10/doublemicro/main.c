#include <stdio.h>
#include <stdlib.h>

typedef union Number
{
    double val;
    unsigned char bin[8];
    unsigned long long conv;
} Number;

int get_exp(char bits[])
{
    int res = 0;
    for (int i = 1; i < 12; ++i)
    {
        res = res * 2 + bits[i];
    }

    return res - 1023;
}

double get_man(char bits[])
{
    double res = 0.0;
    double curr = 0.5;

    for (int i = 12; i < 64; ++i)
    {
        if (bits[i] == 1)
            res += curr;
        curr /= 2.;
    }

    return res + 1.0;
}
void convert(Number num)
{
    char *bits = malloc(64 * sizeof(char));

    for (int i = 0; i < 64; ++i)
    {
        bits[i] = (num.conv >> (63 - i) & 1);
    }

    char sign = (bits[0] == 1) ? '-' : '+';
    int exp = get_exp(bits);
    float man = get_man(bits);
    printf("Result: %c%.17g * 2^%d\n", sign, man, exp);
}

int main()
{
    Number num1;

    printf("Enter number: ");
    if (scanf("%lf",&num1.val) != 1)
    {
        printf("Incorrect input!\n");
        return 1;
    }

    convert(num1);
    return 0;
}

