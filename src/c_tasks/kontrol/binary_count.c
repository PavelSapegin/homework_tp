#include <stdio.h>

int to_bin_sum(int x)
{
    int res = 0;
    while (x > 0) {
        res += x % 2;
        x /= 2;
    }

    return res;
}

void max_bin_sum(int arr[], size_t len)
{
    int max_sum = 0;
    for (int i = 0; i < len; ++i) {
        int curr_sum = to_bin_sum(arr[i]);
        if (max_sum < curr_sum) {
            max_sum = curr_sum;
        }
    }

    for (int i = 0; i < len; ++i) {
        int curr_sum = to_bin_sum(arr[i]);
        if (curr_sum == max_sum)
            printf("%d ", arr[i]);
    }
}

int main()
{
    size_t len = 6;
    int arr[] = { 1, 2, 3, 4, 5, 255 };
    max_bin_sum(arr, len);
    return 0;
}
