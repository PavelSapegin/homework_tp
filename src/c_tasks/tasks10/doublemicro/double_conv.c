#include <stdio.h>
#include "double_conv.h"


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
    
    char bits[64];
    for (int i = 0; i < 64; ++i)
    {
        bits[i] = (num.conv >> (63 - i) & 1);
    }

    res.sign = (bits[0] == 1) ? '-' : '+';
    res.exp = get_exp(bits);
    res.man = get_man(bits);
    
    return res;
}
