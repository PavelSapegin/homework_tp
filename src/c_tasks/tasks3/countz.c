#include <stdio.h>

int main()
{
    int n;
    int count = 0;

    printf("Введите количество элементов в массиве: ");
    scanf("%d", &n);
    printf("Введите элементы массива через пробел:\n");
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        if (arr[i] == 0)
            count++;
    }

    printf("Количество нулей в массиве: %d шт.\n", count);

    return 0;
}
