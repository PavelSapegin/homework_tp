#include <stdio.h>

int find_min(int arr[], size_t len, int start)
{
    int min = arr[start];
    int indx = start;
    for (int j = start + 1; j < len; ++j) {
        if (arr[j] < min) {
            min = arr[j];
            indx = j;
        }
    }

    return indx;
}

void selection_sort(int arr[], size_t len)
{
    for (int i = 0; i < len; ++i) {

        int indx = find_min(arr, len, i);
        int min = arr[indx];

        if (min != arr[i]) {
            int temp = arr[i];
            arr[i] = arr[indx];
            arr[indx] = temp;
        }
    }
}

int main()
{
    size_t arr_len = 10;
    int arr[] = { 1, 2, 3, 4, 5, 4, 3, 5, 2, 1 };
    selection_sort(arr, arr_len);
    for (int i = 0; i < arr_len; ++i) {

        printf("%d ", arr[i]);
    }
    return 0;
}
