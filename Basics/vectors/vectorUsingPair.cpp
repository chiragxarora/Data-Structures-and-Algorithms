#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

// there are n cabs on x-y plane, sort them on the basis of distance from origin

bool compare(pair<int,int> p1, pair<int,int> p2){
    int d1 = p1.first*p1.first + p1.second*p1.second;
    int d2 = p2.first*p2.first + p2.second*p2.second;
    return d1 < d2;
}

int main() {
    vector<pair<int,int>> v;
    int n;
    cin>>n;
    while(n--) {
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end(),compare);
    for(auto vc : v){
        cout<<vc.first<<" "<<vc.second<<endl;
    }
    return 0;
}