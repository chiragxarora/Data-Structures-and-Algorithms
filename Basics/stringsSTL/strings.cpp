#include <iostream>
#include <string>

using namespace std;

int main()
{
    // String Initialization
    // Strings are mutable in C++
    string s0;
    string s1("Hello");
    string s2(s1);
    string s3 = s2;
    s2 = "World";
    //cout<<s0<<endl<<s1<<endl<<s2<<endl<<s3<<endl;

    // char array to string
    char a[] = {'a', 'b', 'c', 'd', '\0'};
    string s4(a);
    //cout<<s4;

    // check empty

    if (s0.empty())
    {
        //cout<<endl<<"s0 is empty"<<endl;
    }

    // append to a string

    s0.append("I love c++");
    //cout<<s0<<endl;
    s0 += " and python!";
    //cout<<s0<<endl;

    // length and remove

    //cout<<s0.length()<<endl;
    s0.clear(); // clears the string
    //cout<<s0.length()<<endl;

    // comparison

    s0 = "Apple";
    s1 = "Mango";
    // s0.compare(s1) : lexicographic comparison
    // returns 0 if strings are equal
    // returns +ve if s0 > s1
    // returns -ve if s0 < s1
    //cout<<s1.compare(s0);
    // overloaded operator comparison
    if (s1 > s0)
    {
        //cout<<"\nMango is greater";
    }

    // accessing characters via index

    //cout<<endl<<s1[2]<<endl<<s1[3];

    // find substrings

    string s = "I want to have apple juice";
    int idx = s.find("apple"); // returns starting index of string passed
    //cout<<idx;

    // remove a word from the string

    string word = "apple";
    s.erase(idx, word.length() + 1);
    //cout<<s;

    // Iterate over all the characters of string
    // using for loop
    for (int i = 0; i < s.length(); i++)
    {
        //cout << s[i] << " ";
    }
    // using iterator
    // auto keyword automatically defines the data type depending upon the value of right side
    for (string::iterator it = s.begin(); it != s.end(); it++)
    {
        //cout<<(*it)<<" ";
    }
    // using for each loop
    for(char ch : s) {
        cout<<ch<<" ";
    }
    return 0;
}