#include <iostream>
#include <cstring>
using namespace std;

// Input n strings and print out the largest string

int main() {
    int n;
    cin>>n;
    char largest[1000];
    largest[0] = '\0';
    while(n-- >=0){
        char current[1000];
        cin.getline(current,1000);
        if(strlen(current) > strlen(largest)){
            strcpy(largest,current);
        }
    }
    cout<<largest;
    return 0;
}