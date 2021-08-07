#include <iostream>
#include <algorithm>

using namespace std;

// 0-1 Knapsack problem

int knapsack(int wt[], int price[], int idx, int cap, int n) {
    if(idx==n) {
        return 0;
    }
    // rob
    int rob = 0;
    if(wt[idx] <= cap) {
        rob = knapsack(wt,price,idx+1,cap-wt[idx],n) + price[idx];
    }
    // not rob
    int notRob = knapsack(wt,price,idx+1,cap,n);

    return max(rob,notRob);
}

int main() {
    int wt[] = {1,2,6,3,4};
    int price[] = {1,3,5,2,6};
    int n = sizeof(wt)/sizeof(int);
    cout<<knapsack(wt,price,0,8,n);
    return 0;
}