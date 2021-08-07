#include <iostream>
#include <vector>

using namespace std;

// Vector is a dynamic array whose size can grow/shrink

int main() {
    // initialization
    vector<int> a;
    vector<int> b(5,10); // vector of 5 elements with value 10 each
    vector<int> c{1,2,3,4,5};  // init a vector with given values
    vector<int> d(b.begin(),b.end());  // copies vector b into a new vector d

    // iterating over vector
    for(int i=0;i<d.size();i++){
        cout<<d[i]<<" ";
    }
    cout<<endl;
    for(auto it = c.begin(); it!=c.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    for(int x : d){
        cout<<x<<" ";
    }

    // user input
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int no;
        cin>>no;
        v.push_back(no);  // adds the value to the end on vector
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<",";
    }

    // on push_back(), doubling of array takes place, when the current array is full, a new array of double size is created
    // and the values are copied in that array! in starting array is of size "one" 

    cout<<endl;
    cout<<v.size()<<endl;  // number of elements in vector
    cout<<v.capacity()<<endl;  // size of the underlying array
    cout<<v.max_size()<<endl;  // maximum elements that can be stored (depends upon system space)
    return 0;
}