#include <iostream>
#include <algorithm>

using namespace std;

// q queries given, in each query we get coordinates of top left and bottom right cells of a matrix
// print sum of submatrix formed by coordinates given in each query

int main()
{
    int n;
    cin >> n;
    int arr[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int q;
    cin >> q;
    int arrPrefix[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int left = 0, up = 0, oppdiag = 0;
            if (j - 1 >= 0)
            {
                left = arrPrefix[i][j - 1];
            }
            if (i - 1 >= 0)
            {
                up = arrPrefix[i - 1][j];
            }
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                oppdiag = arrPrefix[i - 1][j - 1];
            }
            arrPrefix[i][j] = arr[i][j] + left + up - oppdiag;
        }
    }
    while (q--)
    {
        int tlr, tlc, brr, brc;
        cin >> tlr >> tlc >> brr >> brc;
        int left = 0, up = 0, oppdiag = 0, sum = 0;
        if (tlc - 1 >= 0)
        {
            left = arrPrefix[brr][tlc - 1];
        }
        if (tlr - 1 >= 0)
        {
            up = arrPrefix[tlr - 1][brc];
        }
        if (tlc - 1 >= 0 && tlr - 1 >= 0)
        {
            oppdiag = arrPrefix[tlr - 1][tlc - 1];
        }
        sum = arrPrefix[brr][brc] - up - left + oppdiag;
        cout<<sum;
    }
    return 0;
}