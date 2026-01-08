#include <stdio.h>

int swap(int x)
{
    int res = 0;
    int buddy = 0;
    while (x > 0)
    {
        res *= 10;
        res += x % 10;
        x /= 10;
    }
    return res;
}
int fib_zifr(int arr[], int n)
{
    int nt = n;
    int zifrs[10000]; 
    arr[0] = 1;
    arr[1] = 1;
    zifrs[0] = 1;
    zifrs[1] = 1;
    int indx = 2;

    for (int i = 2; i < nt; ++i)
    {
        arr[i] = arr[i-1] + arr[i-2];
        int temp = swap(arr[i]);
        while (temp > 0)
        {
            zifrs[indx++] = temp %10;
            temp /= 10;
        }

    }

    int res = (nt > 5) ? zifrs[nt] : zifrs[nt -1];
    return res;

}
int main()
{
    int arr[100] = {0};
    int x = 8;
    printf("%d", fib_zifr(arr,x));
    return 0;
}
