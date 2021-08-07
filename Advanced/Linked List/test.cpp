#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> base2To6Hire2020(vector<bool> base2) {
    vector<int> base10;
    double base = 1;
    double ans = 0;
    for(int i = base2.size()-1;i>=0;i--){
        ans += (int)base2[i] * base;
        base *= 2;
    }
    cout<<ans;
    cout<<(int)ans<<endl;
    for(double a = ans; a!=0; a= floor(a/10)) {
        int rem = a - floor(a/10)*10;
        base10.push_back(rem);
    }
    return base10;
}

int main() {
    vector<bool> v {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0};
    //cout<<v.size();
    vector<int> a = base2To6Hire2020(v);
    for(auto i : a) {
        cout<<i<<" ";
    }
    return 0;
}