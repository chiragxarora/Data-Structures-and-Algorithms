#include <iostream>
#include <algorithm>
# include <cstring>

// char *strtok(char *s, char *delimiters)
// returns a token on each subsequent call
// on the first call function should be passed with string argument for 's'
// on subsequent calls we should pass the string argument as null

using namespace std;

int main() {
    char s[100] = "Today is a rainy day";
    char *ptr = strtok(s," ");  // points to the first token in the given array
    cout<<endl<<ptr;
    while(ptr != NULL) {
        ptr = strtok(NULL," ");
        cout<<endl<<ptr;
    }
    return 0;
}