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

int get_exp(char bits[]);
double get_man(char bits[]);
ParsedDouble convert(Number num);
