#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

class Queue {

public:
    
    int cap = 0;
    int front = 0;
    int size = 0;
    int* arr;

    Queue(int cap) {
        this->cap = cap;
        arr = new int [cap];
    }

    void enqueue(int val) {
        if(size==cap){
            cout<<"OVERFLOW!\n";
            return;
        } else {
            arr[(size+front)%cap] = val;
            size++;
        }
    }

    void dequeue() {
        if(size==0) {
            cout<<"UNDERFLOW!\n";
            return;
        } else {
            arr[front] = 0;
            front++;
            size--;
            if(size==0) front = 0;
        }
    }

    int getFront() {
        if(size==0) {
            return -1;
        } else {
            return arr[front];
        }
    }

    int getRear() {
        if(size==0) {
            return -1;
        } else {
            return arr[((size+front)%cap)-1];
        }
    }

    void print() {
        for(int i=0;i<size;i++) {
            cout<<arr[(front+i)%cap]<<" <= ";
        }
        cout<<endl;
    }
};

void reverseQ(Queue* q){
    stack<int> s;
    while(!q->size == 0){
        s.push(q->getFront());
        q->dequeue();
    }
    while(!s.empty()){
        q->enqueue(s.top());
        s.pop();
    }
    q->print();
}

void generateNumbers(int n) {
    // generate first N numbers formed only with digits 5 and 6, in sorted order
    queue<string> q;
    q.push("5");
    q.push("6");
    for(int i=1;i<=n;i++){
        string str = q.front();
        cout<<str<<" ";
        q.pop();
        q.push(str + "5");
        q.push(str + "6");
    }
}

int main() {
    Queue *q = new Queue(5);
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    // cout<<q->getRear()<<endl;
    // q->dequeue();
    // q->print();
    q->enqueue(4);
    // q->print();
    // q->dequeue();
    // q->dequeue();
    // q->print();
    q->enqueue(5);
    // q->enqueue(7);
    // cout<<q->getFront()<<endl;
    // cout<<q->getRear()<<endl;
    // q->print();
    // reverseQ(q);
    generateNumbers(11);
    return 0;
}