#include "sortedlist.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc > 1 && strcmp(argv[1], "--test") == 0)
        return run_tests();

    list* st = NULL;
    int choice = -10;

    while (1) {

        printf("\n");
        menu();
        if (scanf("%d", &choice) != 1 || choice < 0 || choice > 3) {
            while (getchar() != '\n')
                ;
            printf("Ошибка ввода\n");
            continue;
        }

        switch (choice) {
        case 0:
            free_list(&st);
            return 0;

        case 1: {
            int num;
            printf("Введите значение:\n");
            if (scanf("%d", &num) == 1) {
                append(&st, num);
                printf("Значение успешно добавлено!\n");
            } else {
                printf("Ошибка\n");
            }
            break;
        }
        case 2: {
            int num;
            printf("Введите значение:\n");
            if (scanf("%d", &num) == 1) {
                delete (&st, num);
                printf("Значение успешно удалено!\n");
            }

            break;
        }
        case 3: {
            print(&st);
            break;
        }
        }
    }
    return 0;
}
