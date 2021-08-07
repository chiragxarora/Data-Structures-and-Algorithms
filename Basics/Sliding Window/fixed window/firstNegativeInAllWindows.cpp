#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

// Find first negative number present in all windows of size k

void solve(vector<int> v, int k) {
    int i=0, j=0;
    queue<int> q;
    while(j<v.size()){
        if(v[j]<0){
            q.push(j);
        }
        if(j-i+1==k){
            if(q.size()==0){
                cout<<0<<" ";
            } else {
                cout<<v[q.front()]<<" ";
            }
            if(q.front()==i){
                q.pop();
            }
            i++;
        }
        j++;
    }
}

int main() {
    vector<int> v {-2,5,1,8,-2,9,-1};
    int k = 2;
    solve(v,k);
    return 0;
}