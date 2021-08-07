#include <iostream>
#include <algorithm>

using namespace std;

// A list has n numbers and except one number, all others are occuring thrice. Find the unique number

int main()
{
    int cnt[64] = {0};
    int arr[] = {1, 1, 1, 5, 5, 5, 8, 6, 6, 7, 6, 7, 7};
    int n = sizeof(arr) / sizeof(int);
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int j = 0;
        while (num != 0)
        {
            int lastBit = num & 1;
            cnt[j] += lastBit;
            num = num >> 1;
            j++;
        }
    }
    int ans = 0, p = 1;
    for (int i = 0; i < 64; i++)
    {
        cnt[i] %= 3;
        ans += cnt[i] * p;
        p = p << 1;
    }
    cout << ans;

    return 0;
}