#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

// Find longest subarray with sum equal to k

void solve(vector<int> v, int k) {
    int i=0, j=0, sum=0, ans=0;
    while(j<v.size()){
        sum += v[j];
        while(sum>k){
            sum-=v[i];
            i++;
        }
        if(sum==k){
            cout<<i<<" "<<j<<endl;
            ans = max(ans, j-i+1);
        }
        j++;
    }
}

int main() {
    vector<int> v {1,2,3,7,5};
    int k = 12;
    solve(v,k);
    return 0;
}