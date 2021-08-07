#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v{1,2,3,4,5};
    // push_back() : adds element at the end
    v.push_back(6);  // time complexity: O(1) most of the time
    cout<<endl<<v.capacity()<<endl;
    // pop_back() : removes the last element from the vector
    v.pop_back(); // time complexity: O(1)
    // insert(it,val) : inserts val at the position specified
    v.insert(v.begin()+2,0); // time complexity: O(n)
    // erase(it) : removes the element at position it
    v.erase(v.begin()+2);
    cout<<v.size()<<endl<<v.capacity()<<endl;
    v.resize(30); // resize fills the remaining elements of capacity with zeros
    // if resize is passed with size > capacity, then both size and capacity will increase to the given value
    cout<<v.size()<<endl<<v.capacity()<<endl;
    // clear() : removes all the elements from the vector
    cout<<v.front()<<" "<<v.back()<<endl; // returns first and the last element of the vector
    for(int x:v){
        cout<<x<<",";
    }
    // reserve(1000) : reserves the capacity to 1000 and avoids doubling until limit 1000 is reached
    return 0;
}