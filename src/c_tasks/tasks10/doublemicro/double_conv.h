#pragma once 

typedef union Number
{
    double val;
    unsigned long long conv;
} Number;

typedef struct ParsedDouble
{
    char sign;
    int exp;
    double man;
} ParsedDouble;

void run_tests();

int get_exp(Number num);
double get_man(Number num);
ParsedDouble convert(Number num);
