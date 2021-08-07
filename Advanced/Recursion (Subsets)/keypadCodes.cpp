#include <iostream>
#include <vector>
#include <string>

using namespace std;

//

string getCodes(char ch)
{
    if (ch == '2')
    {
        return "abc";
    }
    if (ch == '3')
    {
        return "def";
    }
    if (ch == '4')
    {
        return "ghi";
    }
    if (ch == '5')
    {
        return "jkl";
    }
    if (ch == '6')
    {
        return "mno";
    }
    if (ch == '7')
    {
        return "pqrs";
    }
    if (ch == '8')
    {
        return "tuv";
    }
    if (ch == '9')
    {
        return "wxyz";
    }
    return "";
}

vector<string> keypadCodes(string digits)
{
    if (digits.length() == 0)
    {
        vector<string> v;
        v.push_back("");
        return v;
    }
    vector<string> remainingAns = keypadCodes(digits.substr(1));
    string current = getCodes(digits[0]);
    vector<string> ans;
    for (int i = 0; i < current.length(); i++)
    {
        for (int j = 0; j < remainingAns.size(); j++)
        {
            string val = current[i] + remainingAns[j];
            ans.push_back(val);
        }
    }
    return ans;
}

int main()
{
    vector<string> v = keypadCodes("24");
    for(auto x : v) {
        cout<<x<<", ";
    }
    return 0;
}