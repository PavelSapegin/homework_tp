#include <stdio.h>
#include <stdlib.h>

char *to_bin(short x)
{
    char *str = malloc(sizeof(char) * 17);

    int bit = 0b1000000000000000;
    for (int i = 0; i < 16; ++i)
    {
        str[i] = (x & bit) ? '1' : '0';
        bit >>= 1;
    }
    str[17] = '\0';
    return str;
}

char *bin_sum(char *num1, char *num2)
{
    char *res = malloc(sizeof(char) * 18);
    char add = '0';
    for (int i = 15; i >= 0; --i)
    {
        if (num1[i] == '1' && num2[i] == '1')
        {
            if (add == '0')
            {
                res[i] = '0';
            }
            else
            {
                res[i] = '1';
            }
            add = '1';
        }
        else if ((num1[i] == '1' && num2[i] == '0') ||
                 (num1[i] == '0' && num2[i] == '1'))
        {
            if (add == '0')
            {
                res[i] = '1';
            }
            else
            {
                res[i] = '0';
            }
        }
        else
        {
            if (add == '0')
            {
                res[i] = '0';
            }
            else
            {
                res[i] = '1';
                add = '0';
            }
        }
    }
    res[18] = '\0';
    return res;
}

short bin_to_dec(char *str)
{
    int res = 0;
    for (int i = 0; i < 16; ++i)
    {
        res = res * 2 + ((str[i] == '1') ? 1 : 0);
    }

    return (str[0] == '1') ? res - 65536 : res;
}
