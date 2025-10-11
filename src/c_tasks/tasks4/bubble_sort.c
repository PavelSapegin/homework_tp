#include <stdio.h>


void bubble_sort(int arr[],int len_arr)
{

    for (int i = 0; i < len_arr; ++i)
    {  
        for (int j = i + 1; j < len_arr; ++j)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main()
{
    int nums[] = {5,4,1,12,12};
    int len_nums = sizeof(nums) / sizeof(nums[0]);
    
    
    bubble_sort(nums, len_nums);
    for (int i = 0; i < 5; ++ i)
        printf("%d ", *(nums + i));
    return 0;
}
