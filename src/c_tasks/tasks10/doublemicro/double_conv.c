#include <stdio.h>
#include "double_conv.h"

enum {bias = 1023,hidden_bit=1};

int get_exp(Number num)
{
    int res = (int)(((num.conv) >> 52) & 0x7FFULL); // 7FF - 11 единиц
    return res - bias;
}

double get_man(Number num)
{
    unsigned long long bin_man = num.conv & 0xFFFFFFFFFFFFFULL; // 52 единицы
    double res = 0.0;
    double curr = 0.5;

    for (int i = 51; i>=0; --i)
    {
        if ((bin_man >> i) & 1)
            res += curr;
        curr /= 2.;
    }

    return res + hidden_bit;
}
ParsedDouble convert(Number num)
{
    ParsedDouble res;
    
    if (num.val == 0.0)
    {
        res.sign = '+';
        res.exp = 0;
        res.man = 0.0;
        
        return res;
    }
    
    res.sign = ((num.conv >> 63) & 1) ? '-' : '+';
    res.exp = get_exp(num);
    res.man = get_man(num);
    
    return res;
}
