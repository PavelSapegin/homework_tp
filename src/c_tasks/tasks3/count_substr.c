#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char s1[] = "Abboja Boboja";
    char s2[] = "Hello";
    int lens1 = strlen(s1);
    int step = 2;
    int count = 0;
    printf("%s\n", s1); 
    for (int start = 0; start + step <= lens1; ++start)
    {
        char sub[start+step];
        
        for (int i = 0; i < step; ++i)
	{
	    sub[i] = s1[start + i];
	}	
        sub[start+step] = '\0';
	printf("%s\n", sub);
    }

    return 0;
}


