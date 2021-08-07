#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

// Find subarray of size k having maximum sum

int solve(vector<int> v, int k) {
    int i=0, j=0, sum=0;
    int start = 0, end = 0, ans = INT_MIN;
    while(j<v.size()){
        sum += v[j];
        if(j-i+1==k){
            if(sum>ans){
                start = i;
                end = j;
                ans = max(ans,sum); 
            }
            sum -= v[i];
            i++;
        }
        j++;
    }
    for(int p=start;p<=end;p++){
        cout<<v[p]<<" ";
    }
    cout<<endl<<ans<<endl;
    return ans;
}

int main() {
    vector<int> v {1,2,5,3,1,7,5,2,0,4};
    int k = 4;
    cout<<solve(v,k);
    return 0;
}