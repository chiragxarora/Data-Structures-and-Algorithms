#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// SCS = Shortest Common Supersequence
// given 2 strings, make a string of minimum length using s1 and s2 that have both s1 and s2 as subsequences
// Find length of the super subsequence and print it!

string SCS(string s1, string s2)
{
    int **dp = new int *[s1.length() + 1];
    for (int i = 0; i < s1.length() + 1; i++)
    {
        dp[i] = new int[s2.length() + 1];
    }
    for (int i = 0; i < s1.length() + 1; i++)
    {
        for (int j = 0; j < s2.length() + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
    }
    string ans = "";
    int i = s1.length(), j = s2.length();
    while (i != 0 && j != 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans += s1[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                ans += s1[i - 1];
                i--;
            }
            else if (dp[i - 1][j] < dp[i][j - 1])
            {
                ans += s2[j - 1];
                j--;
            }
            else
            {
                ans += s1[i - 1];
                i--;
            }
        }
    }
    while (i != 0)
    {
        ans += s1[i - 1];
        i--;
    }
    while (j != 0)
    {
        ans += s2[j - 1];
        j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    cout<<SCS("abcab","bcd")<<endl;
    return 0;
}