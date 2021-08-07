#include <iostream>
#include <algorithm>

using namespace std;

// pass by value
void ValueIncrement(int a){
    a = a + 1;  // these changes are local to the function and will be non existent outside the function
    cout<<"inside value funtion : "<<a<<endl;
}

// pass by reference using pointers
void ReferenceIncrement(int *a) {
    *a = *a + 1;  // these changes are in memory and will sustain outside the function too
    cout<<"inside reference funtion : "<<*a<<endl;
}

void ValArray(int arr[]){
    arr[0] += 10;
    cout<<"inside val fn : arr[0] "<<arr[0]<<endl;
}

void RefArray(int *arr){
    arr[0] += 10;
    cout<<"inside ref fn : arr[0] "<<arr[0]<<endl;
}

int main() {
    int a = 10;
    // ValueIncrement(a);
    // ReferenceIncrement(&a);
    // cout<<"inside main : "<<a;

    // so in arrays, there is nothing like pass by values, its always pass by reference
    int arr[5] = {1,2,3,4,5};
    cout<<"before calls : arr[0] "<<arr[0]<<endl;
    ValArray(arr);
    cout<<"inside main after val call : arr[0] "<<arr[0]<<endl;
    RefArray(arr);
    cout<<"inside main after ref call : arr[0] "<<arr[0]<<endl;
    // for array, arr_variable_name holds the address of first element of array
    cout<<(arr+1)<<endl;  // address of second element of array
    cout<<*(arr+1)<<endl;  // value of second element of array
    return 0;
}