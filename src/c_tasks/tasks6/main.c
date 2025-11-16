#include <stdio.h>
#include <string.h>
#include "sortedlist.h"


int main(int argc, char *argv[])
{
    if (argc > 1 && strcmp(argv[1], "--test") == 0)
        return run_tests();

    list *st = NULL;
    int choice = -10;

    
    while (1)
    {

        printf("\n");
        menu();
        if (scanf("%d",&choice) !=1 || choice < 0 || choice > 3)
        {
            spaces();
            printf("Ошибка ввода");
            continue;
        }

        switch(choice)
        {
            case 0:
                return 0;
            
            case 1:
            {
                int num;
                printf("Введите значение:\n");
                if (scanf("%d",&num) == 1)
                {
                    append(&st,num);
                    spaces();
                    printf("Значение успешно добавлено!\n");
                }
                else
                    {
                    spaces();
                    printf("Ошибка\n");
                    }
                break;
            }
            case 2:
            {
                int num;
                printf("Введите значение:\n");
                if (scanf("%d",&num) == 1)
                {
                    delet(&st,num);
                    spaces();
                    printf("Значение успешно удалено!");
                }
                
                break;
            }
            case 3:
            {
                spaces();
                print(&st);
                break;
            }
        }
    }
    return 0;
}

