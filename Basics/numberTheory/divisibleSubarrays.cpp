#include <iostream>
#include <unordered_map>

using namespace std;

// Find all subarrays of a given aray whose su is divisible by k

int main() {
    int arr[] = {1,2,3,5};
    int n = sizeof(arr)/sizeof(int);
    int k = 5;
    unordered_map<int, int> map;  // <remainder, frequency>
    map.insert(make_pair(0,1));
    int ans = 0, sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        int rem = sum%k;
        if(rem<0){
            rem += k;
        }
        if(map.find(rem) != map.end()){
            ans += map[rem];
            map[rem] += 1;
        } else {
            map.insert(make_pair(rem,1));
        }
    }
    cout<<ans;
    return 0;
}