#include <stdio.h>
#include <string.h>

int main() 
{
    char str[10000];
    fgets(str,sizeof(str),stdin);
    
    int count = 0;
    int len = strlen(str);
    for (int i = 0; i < len; ++i)
    {
        
        
        if (str[i] == '(')
            count += 1;
        
        else if (str[i] == ')')
            count -= 1;

        if (count < 0) {
            printf("False");
            return 0;
	}
    }

    if (count == 0)
        printf("True");
    return 0;
}
