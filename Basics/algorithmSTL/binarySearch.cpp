#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[] = {11, 21, 34, 34, 34, 34, 55, 65, 76, 87, 98, 109};
    int n = sizeof(arr) / sizeof(n);
    int key;
    cin >> key;
    // search for key in a sorted array
    bool present = binary_search(arr, arr + n, key);
    if (present)
    {
        cout << "present\n";
    }
    else
    {
        cout << "not present\n";
    }

    // two more things
    // get the index of the element
    //lower_bound(start,end,key) and upper_bound(start,end,key)
    auto it = lower_bound(arr,arr+n,key);
    // lower_bound returns the address of first occurence of element greater than or equal to key
    int idx = it - arr;
    if(*it != key){
        cout<<"element not found\n";
    }
    cout << "lower bound for the given key found at " << idx <<" "<<*it<< endl;

    
    auto itt = upper_bound(arr,arr+n,key);
    // upper_bound returns the address of first occurence of element strictly greater than key
    cout<<"frequency of given key = "<<itt-it;

    // upper bound - lower bound will be equal to the frequency of key in the sorted array


    return 0;
}