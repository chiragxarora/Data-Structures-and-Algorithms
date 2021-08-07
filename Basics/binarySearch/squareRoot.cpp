#include <iostream>
#include <algorithm>

using namespace std;

// Find square root of a number using binary search!

bool check(int val, int n)
{
    if(val*val > n){
        return false;
    } else {
        return true;
    }
}

int main()
{
    int n;
    cin >> n;
    int start = 0, end = n, ans = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (check(mid, n))
        {
            ans = mid;
            start = mid+1;
        }
        else {
            end = mid-1;
        }
    }
    cout<<ans;
    return 0;
}