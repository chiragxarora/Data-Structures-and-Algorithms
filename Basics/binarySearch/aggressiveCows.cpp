#include <iostream>
#include <algorithm>

using namespace std;

// Aggressive cows : https://www.spoj.com/problems/AGGRCOW/

bool isPossible(long long int arr[], long long int dist, long long int n, long long int cows){
    long long int rn = 1, prev = arr[0];
    for(long long int i=1;i<n;i++){
        long long int c_dist = arr[i]-prev;
        if(c_dist>=dist){
            prev = arr[i];
            rn++;
            if(rn==cows){
                return true;
            }
        }
    }
    return false;
}

long long int binarySearch(long long int arr[], long long int start, long long int end, long long int n, long long int cows){
    long long int ans = 0;
    while(start<=end){
        long long int mid = (start+end+1)/2;
        if(isPossible(arr,mid,n,cows)){
            if(mid > ans) {
                ans = mid;
            }
            start = mid+1;
        } else {
            end = mid-1;
        }
    }
    return ans;
}

int main() {
    long long int t;
    cin>>t;
    while(t--) {
        long long int n,c;
        cin>>n>>c;
        long long int *arr = new long long int [n];
        for(long long int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        cout<<binarySearch(arr,0,arr[n-1]-arr[0],n,c)<<endl;
    }
    
    return 0;
}