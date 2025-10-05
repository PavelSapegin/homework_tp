#include <stdio.h>
#include <string.h>

int main()
{
    char s1[1000000];
    char s2[1000000];
    scanf("%s", s1);
    scanf("%s", s2);
    printf("%s\n%s", s1, s2);
    int lens1 = strlen(s1);
    int step = strlen(s2);
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
	if (strcmp(s2,sub) == 0)
		count++;
    }

    printf("%d\n", count);
    return 0;
}


