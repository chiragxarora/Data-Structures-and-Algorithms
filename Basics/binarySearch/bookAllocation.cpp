#include <iostream>
#include <algorithm>

using namespace std;

// Book Allocation : https://www.interviewbit.com/problems/allocate-books/

bool isPossible(long long int arr[], long long int limit, long long int n, long long int students){
    long long int rn = 1, prev = arr[0], c_read = arr[0];
    for(long long int i=1;i<n;i++){
        if(c_read + arr[i] > limit){
            c_read = arr[i];
            rn++;
        } else {
            c_read += arr[i];
        }
    }
    if(rn==students) {
        return true;
    } else {
        return false;
    }
}

long long int binarySearch(long long int arr[], long long int start, long long int end, long long int n, long long int students){
    long long int ans = end;
    while(start<=end){
        long long int mid = (start+end)/2;
        if(isPossible(arr,mid,n,students)){
            ans = mid;
            end = mid-1;
        } else {
            start = mid+1;
        }
    }
    return ans;
}

int main() {
    long long int t;
    cin>>t;
    while(t--) {
        long long int n,s;
        cin>>n>>s;
        long long int *arr = new long long int [n];
        for(long long int i=0;i<n;i++){
            cin>>arr[i];
        }
        int max = 0;
        for(int i=0;i<n;i++){
            max += arr[i];
        }

        cout<<binarySearch(arr,arr[0],max,n,s)<<endl;
    }
    
    return 0;
}