#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

// Fractional Knapsack Problem
// We can put items in bag PARTIALLY too!
// We have to maximise the profit

bool cmp(pair<int,int> p1, pair<int,int> p2) {
    double pw1 = (double)p1.first/p1.second;
    double pw2 = (double)p2.first/p2.second;
    return pw1 > pw2;
}

double fractionalKnapsack(vector<int> profit, vector<int> weight, int bagCapacity){
    vector<pair<int,int>> items;
    for(int i=0;i<profit.size();i++){
        items.push_back(make_pair(profit[i],weight[i]));
    }
    double ans = 0;
    sort(items.begin(),items.end(),cmp);
    for(int i=0;i<items.size();i++){
        if(bagCapacity>=items[i].second){
            ans += items[i].first;
            bagCapacity -= items[i].second;
        } else {
            ans += (double)(items[i].first * (double)(bagCapacity/items[i].second));
            return ans;
        }
    }
    return ans;
}

int main() {
    vector<int> profit {3, 5, 7, 1, 4};
    vector<int> weight {2, 2, 4, 1, 3};
    int bagCapacity = 8;
    cout<<fractionalKnapsack(profit, weight, bagCapacity);
    return 0;
}