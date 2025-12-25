#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "double_conv.h"


int main(int argc, char *argv[])
{
    if (argc > 1 && (strcmp(argv[1],"--test") == 0))
    {
        run_tests();
        return 0;
    }
    Number num1;

    printf("Enter number: ");
    if (scanf("%lf",&num1.val) != 1)
    {
        printf("Incorrect input!\n");
        return 1;
    }

    ParsedDouble result = convert(num1);
    printf("Result: %c%.17g*2^%d\n", result.sign, result.man, result.exp);
    return 0;
}

