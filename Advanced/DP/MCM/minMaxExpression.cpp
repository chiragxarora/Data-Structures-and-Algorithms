#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cstring>

using namespace std;

// Boolean Paranthesis: given an expression of numbers and operators(+,*), find the maximum and minimum possible value of the expression

// T | F | F & T ^ F

int minMaxExpression(string str, int i, int j, bool isMin) {
    if(i==j) return str[i]-48;
    int ans = isMin ? INT_MAX : INT_MIN;
    for(int k=i+1;k<j;k+=2){
        int leftans = minMaxExpression(str,i,k-1,isMin);
        int rightAns = minMaxExpression(str,k+1,j,isMin);
        if(isMin){
            if(str[k]=='+'){
                ans = min(ans,leftans+rightAns);
            } else {
                ans = min(ans,leftans*rightAns);
            }
        } else {
            if(str[k]=='+'){
                ans = max(ans,leftans+rightAns);
            } else {
                ans = max(ans,leftans*rightAns);
            }
        }
    }
    return ans;
}

int main() {
    string str = "1+2*3+4*5";
    cout<<"Minimum is : "<<minMaxExpression(str,0,str.length()-1,true)<<endl;
    cout<<"Maximum is : "<<minMaxExpression(str,0,str.length()-1,false)<<endl;
    return 0;
}