#include <iostream>
#include <cstring>
#include <string>

using namespace std;

char *myStrtok(char *str, char delim){

    static char *input = NULL;  // this will point to the tokens in the string

    if(str != NULL){
        // we've made the first call to the function
        input = str;
    }

    // start extracting tokens and store it in an array
    char *output = new char [strlen(input)+1];   // dynamic array
    int i;
    for(i=0;input[i]!='\0';i++){
        if(input[i] != delim){
            output[i] = input[i];
        } else {
            output[i] = '\0';
            input += i+1;
            return output;
        }
        // corner case
        if(input[i+1] == '\0'){
            output[i] = input[i];
            output[i+1] = '\0';
            input += i+1;
            return output;
        }
    }
    return NULL;
}

// we need to maintain two things
// need an array to store the string inside the function (will use dynamic array to keep it in memory once the call is over)
// need a static variable to store the state of string (upto which token string is read)

int main() {
    char s[100] = "Today is a rainy day";
    char *ptr = myStrtok(s,' ');
    cout<<ptr<<"\n";
    while(ptr != NULL) {
        ptr = myStrtok(NULL,' ');
        cout<<ptr<<"\n";
    }
    return 0;
}