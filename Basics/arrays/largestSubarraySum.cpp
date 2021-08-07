#include<iostream>
using namespace std;

int maxSubArraySumPrefixMethod(int arr[], int n) {
    int prefixSum [9];
    int c_sum = 0;
    for(int i=0;i<n;i++) {
        c_sum += arr[i];
        prefixSum[i] = c_sum;
    }
    // 1 2 3 4 5 6
    // 1 3 6 10 15 21
    int max = -10000;
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            int subArraySum = 0;
            subArraySum = prefixSum[j] - prefixSum[i] + arr[i];
            if(subArraySum > max) {
                max = subArraySum;
            }
        }
    }
    return max;
}

int maxSubArraySumKadaneMethod(int arr[], int n) {
    int currentSum = 0, maxSum = 0;
    for(int i=0;i<n;i++)  {
        if(currentSum + arr[i] >= 0 ) {
            currentSum += arr[i];
        } else {
            currentSum = 0;
        }
        if(currentSum >= maxSum) {
            maxSum = currentSum;
        }
    }
    return maxSum;
}

int main() {
    int a[9] = {-4,-1,3,-20,6,-2,-1,-4,-7};
    int n = sizeof(a)/sizeof(int);
    cout<<maxSubArraySumPrefixMethod(a,n)<<endl;  // O(n^2)
    cout<<maxSubArraySumKadaneMethod(a,n);
    // Kadane fails in the case where all elements are negative :(
    // But this can be fixed with some modifications in the algorithm 
    return 0;
}