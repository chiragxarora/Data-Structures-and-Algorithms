#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

// problem link : https://hack.codingblocks.com/app/practice/6/1042/problem

string extractStringAtKey(string str, int key)
{
    char *ptr = strtok((char *)str.c_str(), " ");
    while (key > 1)
    {
        ptr = strtok(NULL, " ");
        key--;
    }
    return (string)ptr;
}

bool numericCompare(pair <string,string> s1, pair <string,string> s2) {
    return stoi(s1.second) < stoi(s2.second);
}
 
bool lexicoCompare(pair <string,string> s1, pair <string,string> s2) {
    return s1.second < s2.second;
}

int main()
{
    int n;
    cin >> n;
    cin.get();
    string a[100];
    for (int i = 0; i < n; i++)
    {
        getline(cin, a[i]);
    }
    int key;
    string reversal, ordering;

    // pair to store strings witht their keys
    pair <string,string> p[100];
    for(int i=0;i<n;i++){
        p[i].first = a[i];
        p[i].second = extractStringAtKey(a[i],key);
    }

    // now sorting
    if(ordering == "numeric"){
        sort(p,p+n,numericCompare);
    } else {
        sort(p,p+n,lexicoCompare);
    }

    // now reversal
    if(reversal =="true"){
        for(int i=0;i<n/2;i++){
            swap(p[i],p[n-1-i]);
        }
    }

    //print output
    for(int i=0;i<n;i++){
        cout<<p[i].first;
    }
    return 0;
}