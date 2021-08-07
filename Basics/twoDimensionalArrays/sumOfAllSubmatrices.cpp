#include <iostream>
#include <algorithm>

using namespace std;

// print sum of all possible sub matrices of a given matrix

// brute force
// find all submatrices and find sum

int subMsum(int arr[100][100], int tlr, int tlc, int brr, int brc)
{
    int sum = 0;
    for (int i = tlr; i <= brr; i++)
    {
        for (int j = tlc; j <= brc; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}

void subMatricesSumBruteForce(int arr[][100], int n)
{
    int sum = 0;
    for (int tlr = 0; tlr < n; tlr++)
    {
        for (int tlc = 0; tlc < n; tlc++)
        {
            for (int brr = tlr; brr < n; brr++)
            {
                for (int brc = tlc; brc < n; brc++)
                {
                    sum += subMsum(arr, tlr, tlc, brr, brc);
                }
            }
        }
    }
    cout << sum << endl;
}

// better approach
// find all submatrices and calculate sum without using loops but with the help of prefixArray manipulation

void subMatricesSumPrefixArr(int arrPrefix[][100], int n)
{
    int sum = 0;
    for (int tlr = 0; tlr < n; tlr++)
    {
        for (int tlc = 0; tlc < n; tlc++)
        {
            for (int brr = tlr; brr < n; brr++)
            {
                for (int brc = tlc; brc < n; brc++)
                {
                    int left = 0, up = 0, oppdiag = 0;
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
                    sum += arrPrefix[brr][brc] - up - left + oppdiag;
                }
            }
        }
    }
    cout << sum << endl;
}

// best approach
// instead of finding all submatrices, we find the number of occurances of a cell in all possible submatrices
// using permutation and combination

void subMatricesSumPNC(int arr[100][100], int n){
    // any cell will be a part of submatrix if top left is in north west
    // and bottom right is in south east direction to the cell
    // assume there's a random cell (i,j) for which, there are
    // x cells in north west which can be top left
    // and y cells in south east which can be bottom right
    // => total pairs of TL,BR = x*y
    int sum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum += arr[i][j] * (((i+1)*(j+1)) * ((n-i)*(n-j)));  // cell value * no. of occurances
        }
    }
    cout<<sum;
}

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
    subMatricesSumBruteForce(arr, n);       // Time complexity: O(n^6)
    subMatricesSumPrefixArr(arrPrefix, n); // Time complexity: O(n^4)
    subMatricesSumPNC(arr, n); // Time complexity: O(n^2)
    return 0;
}