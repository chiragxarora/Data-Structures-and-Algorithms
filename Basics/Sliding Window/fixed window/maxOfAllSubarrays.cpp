#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <deque>

using namespace std;

// Find maximum of all subarrays of size k 


void solve(vector<int> v, int k) {
    int i=0, j=0;
    deque<int> d;
    int mx = INT_MIN;
    while(j<v.size()){
        while(d.size()>0 && v[d.back()]<v[j]){
            d.pop_back();
        }
        d.push_back(j);
        if(j-i+1==k){
            cout<<v[d.front()]<<" ";
            if(i==d.front()){
                d.pop_front();
            }
            i++;
        }
        j++;
    }
}

int main() {
    vector<int> v {3,1,2,0,1,2,3,4,5};
    int k = 3;
    solve(v,k);
    return 0;
}