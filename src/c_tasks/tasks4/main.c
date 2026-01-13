#include <stdio.h>

extern void bubble_sort(int arr[], int len_arr);

int main()
{
    int nums[100];

    // копия массива для подсчета элементов
    // изменивших свою позицию
    int nums_copy[100];
    int len_nums = 0; // считаем длину массива с реальнымим данными
    int count = 0;

    while ((len_nums < 100) && (scanf("%d", &nums[len_nums]) == 1)) {
        nums_copy[len_nums] = nums[len_nums];
        len_nums++;

        char c = getchar();
        if (c == '\n')
            break;
    }

    bubble_sort(nums, len_nums);

    for (int i = 0; i < len_nums; ++i) {
        printf("%d ", nums[i]);
        if (nums[i] != nums_copy[i])
            count++;
    }
    return count;
}
