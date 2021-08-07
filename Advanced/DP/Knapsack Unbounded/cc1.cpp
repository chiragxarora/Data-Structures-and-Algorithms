#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

long long int pizza(vector<int> slices, vector<int> time, int idx, long long int target, long long int **dp)
{
    if (idx == 0 && target != 0)
        return INT_MAX;
    if (target <= 0)
        return 0;
    if (dp[idx][target] != INT_MAX)
        return dp[idx][target];
    // pick
    long long int p1 = pizza(slices, time, idx, target - slices[idx - 1], dp) + time[idx - 1];
    long long int p2 = pizza(slices, time, idx - 1, target, dp);
    return dp[idx][target] = min(p1, p2);
}

int main()
{
    vector<int> slices{6, 8, 10};
    vector<int> time{15, 20, 25};
    int t = 0;
    vector<long long int> tests{123, 15, 300, 1};
    while (t < tests.size())
    {
        long long int target = tests[t];
        long long int **dp;
        dp = new long long int *[slices.size() + 1];
        for (int i = 0; i < slices.size() + 1; i++)
        {
            dp[i] = new long long int[target + 1];
        }
        for (int i = 0; i < slices.size() + 1; i++)
        {
            for (long long int j = 0; j < target + 1; j++)
            {
                dp[i][j] = INT_MAX;
            }
        }
        
        cout << pizza(slices, time, slices.size(), target, dp)<<endl;
        t++;
    }

    return 0;
}

int coinChangeBU(vector<int> coins, int target)
{
    int **dp;
    dp = new int *[coins.size() + 1];
    for (int i = 0; i < coins.size() + 1; i++)
    {
        dp[i] = new int[target + 1];
    }
    for (int i = 0; i < coins.size() + 1; i++)
    {
        for (int j = 0; j < target + 1; j++)
        {
            if (i == 0 && j != 0)
            {
                dp[i][j] = 0;
            }
            else if (j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                if (coins[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    return dp[coins.size()][target];
}

// ** Bottom Up Space Efficient!  {converting 2D DP to 1D}

int coinChangeBUSE(vector<int> coins, int target)
{
    int *dp = new int[target + 1];
    dp[0] = 1;
    for (int i = 1; i < target + 1; i++)
    {
        dp[i] = 0;
    }
    for (int i = 1; i < coins.size() + 1; i++)
    {
        for (int j = 1; j < target + 1; j++)
        {
            if (coins[i - 1] <= j)
            {
                int up = dp[j];
                int prev = dp[j - coins[i - 1]];
                dp[j] = up + prev;
            }
        }
    }
    return dp[target];
}
