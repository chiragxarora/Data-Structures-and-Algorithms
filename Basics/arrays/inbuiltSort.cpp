#include<iostream>
#include<algorithm>
using namespace std;

// defining a comparator function
bool compare(int a, int b){
    return a>b;     // swapping will be done when comparator returns false
}

int main () {
    // sort() => inside algorithm header file
    // it takes starting index and ending index(not included) => [start, end)
    int arr[10] = {1, 6, 2, 90, -4, 0, -100, 6, 66, 6};
    int n = sizeof(arr) / sizeof(int);
    sort(arr, arr+n, compare);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}