#include <iostream>
#include <forward_list>
#include <vector>
#include <stack>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

class Stack {
    
    forward_list<int> list;
    int top;
    int size;

public:
    Stack() {
        this->size = 0;
        this->top = -1;
    }
    void push(int data) {
        list.push_front(data);
        this->top = data;
        size++;
    }

    void pop() {
        if(size==0){
            cout<<"UNDERFLOW!\n";
            return;
        }
        list.pop_front();
        if(size==1){
            size=0;
            top = -1;
            return;
        }
        this->top = list.front();
        size--;
    }

    int peek() {
        return this->top;
    }

    int height() {
        return this->size;
    }

    bool empty() {
        return size==0; 
    }

    void display() {
        for(auto val : list) {
            cout<<val<<"\n---------------\n";
        }
        cout<<endl;
    }
};

void reverse_helper(Stack* st, Stack* h) {
    if(st->empty()){
        return;
    }
    int val = st->peek();
    st->pop();
    h->push(val);
    reverse_helper(st,h);
}

void reverse(Stack* st) {
    Stack* h = new Stack();
    reverse_helper(st,h);
    st = h;
    st->display();
}

void nextGreater(vector<int>& v){
    Stack * s = new Stack();
    s->push(v[0]);
    int i=1;
    while(i!=v.size()){
        if(v[i] < s->peek()){
            s->push(v[i]);
            i++;
        } else {
            while(!s->empty()&&s->peek()<v[i]){
                cout<<s->peek()<<"'s next greater is "<<v[i]<<endl;
                s->pop();
            }
            s->push(v[i]);
            i++;
        }
    }
    while(!s->empty()){
        cout<<s->peek()<<"'s next greater is "<<-1<<endl;
        s->pop();
    }
}

void previousGreater(vector<int> v) {
    stack<int> s;
    s.push(v[0]);
    cout<<v[0]<<"'s previous greater is "<<-1<<endl;
    int i = 1;
    while(i<v.size()) {
        if(v[i]<s.top()){
            cout<<v[i]<<"'s previous greater is "<<s.top()<<endl;
            s.push(v[i]);
        } else {
            while(!s.empty() && v[i]>s.top()){
                s.pop();
            }
            if(s.size()==0){
                cout<<v[i]<<"'s previous greater is "<<-1<<endl;
            } else {
                cout<<v[i]<<"'s previous greater is "<<s.top()<<endl;
            }
            s.push(v[i]);
        }
        i++;
    }
}

vector<int> previousSmaller(vector<int>& v) {
    vector<int> ans;
    int i=1;
    stack<int> s;
    s.push(0);
    ans.push_back(-1);
    while(i!=v.size()){
        if(v[i]>v[s.top()]){
            ans.push_back(s.top());
            s.push(i);
        } else {
            while(!s.empty() && v[i]<=v[s.top()]){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(-1);
            } else {
                ans.push_back(s.top());
            }
            s.push(i);
        }
        i++;
    }
    return ans;
}

vector<int> nextSmaller(vector<int>& v) {
    vector<int> ans;
    int i=v.size()-2;
    stack<int> s;
    s.push(v.size()-1);
    ans.push_back(v.size());
    while(i>=0){
        if(v[i]>v[s.top()]){
            ans.push_back(s.top());
            s.push(i);
        } else {
            while(!s.empty() && v[i]<=v[s.top()]){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(v.size());
            } else {
                ans.push_back(s.top());
            }
            s.push(i);
        }
        i--;
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"'s next smaller is "<<ans[i]<<endl;
    }
    return ans;
}

vector<int> nextGreaterIndex(vector<int> v){
    vector<int> ans;
    for(auto i : v){
        ans.push_back(-1);
    }
    Stack* s = new Stack();
    s->push(0);
    int i=1;
    while(i!=v.size()){
        if(v[i] < v[s->peek()]){
            s->push(i);
            i++;
        } else {
            while(!s->empty()&&v[s->peek()]<v[i]){
                ans[s->peek()] = v[i];
                s->pop();
            }
            s->push(i);
            i++;
        }
    }
    while(!s->empty()){
        ans[s->peek()] = -1;
        s->pop();
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"'s next greater is "<<ans[i]<<endl;
    }
    return ans;
}

#define MAX 1299709 //10^5 th prime number

void createSieve(vector<int> &primes)
{
    vector<bool> sieve(MAX, true);
    sieve[0] = sieve[1] = false;
    for (long long int i = 2; i < MAX; i++)
    {
        if (sieve[i])
        {
            primes.push_back(i);
            for (long long int j = i * i; j < MAX; j += i)
            {
                sieve[j] = false;
            }
        }
    }
}

void cardsGame(vector<int> initial, int q) {  // https://hack.codingblocks.com/app/practice/2/556/problem
    vector<int> primes;
    createSieve(primes);
    stack<int> curr,next;

    for(auto i : initial){
        curr.push(i);
    }
    int i = 1;
    while(i<=q){
        Stack* divs = new Stack();
        while(!curr.empty()){
            int val = curr.top();
            curr.pop();
            if(val%primes[i-1]==0){
                divs->push(val);
            } else {
                next.push(val);
            }
        }
        while(!divs->empty()){
            cout<<divs->peek()<<endl;
            divs->pop();
        }
        delete divs;
        curr = next;
        while(!next.empty()){
            next.pop();
        }
        i++;
    }
    while(!curr.empty()){
        cout<<curr.top()<<endl;
        curr.pop();
    }
}

bool balancedParanthesis(string str) {
    int i=0;
    stack<char> s;
    while(i<str.length()) {
        if(str[i]=='(' || str[i]=='[' || str[i]=='{'){
            s.push(str[i]);
        }
        else if(str[i] == ')'){
            if(s.empty()) return false;
            if(s.top()=='('){
                s.pop();
            }else {
                return false;
            }
        }
        else if(str[i] == ']'){
            if(s.empty()) return false;
            if(s.top()=='['){
                s.pop();
            }else {
                return false;
            }
        }
        else if(str[i] == '}'){
            if(s.empty()) return false;
            if(s.top()=='{'){
                s.pop();
            }else {
                return false;
            }
        }
        i++;
    }
    if(!s.empty()) return false;
    return true;
}

void stockSpan(vector<int>& v){
    // find prev greater
    vector<int> ans;
    for(auto i : v){
        ans.push_back(-1);
    }
    stack<int> s;
    s.push(v.size()-1);
    int i = v.size()-2;
    while(i>=0){
        if(v[i]<v[s.top()]){
            s.push(i);
        }else {
            while(!s.empty()&&v[s.top()]<v[i]){
                ans[s.top()] = s.top()-i;
                s.pop();
            }
            s.push(i);
        }
        i--;
    }
    while(!s.empty()){
        ans[s.top()] = s.top()+1;
        s.pop();
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"'s previous greater is "<<ans[i]<<endl;
    }
}

void removeKdigits(string str, int k) {
    stack<char> s;
    string ans;
    int i=1;
    s.push(str[0]);
    while(k!=0 && i!=str.length()) {
        if((int)str[i]>(int)s.top()){
            s.push(str[i]);
        } else {
            while(!s.empty() && (int)str[i]<(int)s.top() && k!=0){
                s.pop();
                k--;
            }
            s.push(str[i]);
            if(k==0){
                break;
            }
        }
        i++;
    }
    while(!s.empty()&&k!=0){
        s.pop();
        k--;
    }
    while(!s.empty()){
        ans.insert(ans.begin(),s.top());
        s.pop();
    }
    if(i!=str.length()){
        ans += str.substr(i+1);
    }
    while(ans[0]=='0'){
        ans.erase(ans.begin());
    }
    cout<<ans;
}

int maxAreaHistogram(vector<int> v) {
    vector<int> ps = previousSmaller(v);
    vector<int> ns = nextSmaller(v);
    int max = -1;
    for(int i=0;i<v.size();i++){
        int area = v[i] * (i-ps[i]-1 + ns[i]-i);
        if(area>max){
            max = area;
        }
    }
    return max;
}

int eval(int a, int b, char ch){
    if(ch=='+'){
        return a+b;
    }
    if(ch=='-'){
        return a-b;
    }
    if(ch=='*'){
        cout<<"c: "<<a*b<<endl;
        return a*b;
    }
    if(ch=='/'){
        return a/b;
    }
    if(ch=='^'){
        return (int)pow(a,b);
    }
    return 0;
}

int evalPostfix(string str) {
    stack<string> s;
    int i=0;
    while(i<str.length()){
        if(str[i]>='0' && str[i]<='9'){
            string st = "" + str[i];
            s.push(st);
        } else {
            if(s.size()>=2){
                cout<<"z: "<<s.top();
                int op1 = stoi(s.top());
                cout<<op1<<"p";
                s.pop();
                int op2 = stoi(s.top());
                s.pop();
                s.push(to_string(eval(op1,op2,str[i])));
            }
        }
        i++;
    }
    return stoi(s.top());
}

int main() {
    // Stack *s = new Stack();
    // s->push(5);
    // s->push(10);
    // s->push(15);
    // s->push(20);
    // s->push(25);
    //s->display();
    // reverse(s);
    // vector<int> v {1,4,2,6,3,7,1};
    // nextSmaller(v);
    // nextGreater(v);
    // previousGreater(v);
    // nextGreaterIndex(v);
    // vector<int> v {3,4,7,6,5,1,4,3,14,17,16,15,11,14};
    // cardsGame(v,11);
    // cout<<balancedParanthesis("{()([][]){}}");
    //1,5,3,2,9,2,4,0,7
    // vector<int> v {1,5,3,2,9,6,4,0,7};
    // stockSpan(v);
    //removeKdigits("149811",3);
    // vector<int> v {2,1,5,6,2,3};
    // cout<<maxAreaHistogram(v);
    cout<<evalPostfix("52*");
    return 0;
}
