#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class LinkedList {

    class Node {
    public:
        int data;
        Node *next;

        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
    };

    Node *head = NULL;
    Node *tail = NULL;

public:

    void addFirst(int val) {
        Node *n = new Node(val);
        if(head==NULL){
            head = n;
            tail = n;
        } else {
            n->next = head;
            head = n;
        }
    }

    void addLast(int val) {
        Node *n = new Node(val);
        if(head==NULL){
            head = n;
            tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
    }

    void addAtIdx(int val, int idx) {
        int i = 0;
        if(idx==0){
            addFirst(val);
            return;
        }
        Node * ptr = head;
        while(ptr->next!=NULL){
            if(i==idx-1){
                Node *temp = ptr->next;
                Node *n = new Node(val);
                ptr->next = n;
                n->next = temp;
                break;
            }
            ptr = ptr->next;
            i++;
        }
    }

    void deleteFirst() {
        head = head->next;
    }

    void deleteLast() {
        Node* ptr = head;
        while(ptr->next->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = NULL;
        tail = ptr;
    }

    void deleteAtIdx(int idx) {
        if(idx==0) {
            deleteFirst();
            return;
        }
        int i=0;
        Node* ptr = head;
        while(i!=idx-1){
            ptr = ptr->next;
            i++;
        }
        ptr->next = ptr->next->next;
    } 

    Node* getNodeAt(int idx) {
        int a = 0;
        Node* ptr = head;
        while(a<idx){
            ptr = ptr->next;
            a++;
        }
        return ptr;
    }

    bool search(int key) {
        Node* ptr = head;
        while(ptr!= NULL && ptr->data != key) {
            ptr = ptr->next;
        }
        if(ptr==NULL){
            return false;
        } else {
            return true;
        }
    }

    void reverseLLPointerIterative() {
        Node* prev = NULL;
        Node* curr = head;
        while(curr!=NULL) {
            Node* ahead = curr->next;
            curr->next = prev;
            //prev->next = NULL;
            prev = curr;
            curr = ahead;
        }
        tail = head;
        head = prev;
    }

    void reverseLLPointerRecursive() {
        Node* temp = rpr(NULL, head);
        tail = head;
        head = temp;
    }

    Node* rpr(Node* prev, Node* curr){
        if(curr==NULL){
            return prev;
        }
        Node* ahead = curr->next;
        curr->next = prev;
        return rpr(curr,ahead);
    }

    void reverseLLPointerRecursive2() {
        head = rpr2(head);
    }

    Node* rpr2(Node* curr) {
        if(curr==NULL){
            return NULL;
        }
        if(curr->next==NULL){
            return curr;
        }
        Node* remHead = rpr2(curr->next);
        Node* remTail = curr->next;
        remTail->next = curr;
        curr->next = NULL;
        return remHead;
    }

    void removeDuplicates() {
        Node* curr = head;
        while(curr->next!=NULL) {
            if(curr->data == curr->next->data){
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }
        print();
    }

    void removeDuplicates2() {
        // remove all nodes which occur more than once
        // {1 1 2 3 3}  ===>>> {2}
        Node* curr = head;
        Node* dummy = new Node(0);
        dummy->next = head;
        Node* prev = dummy;
        while(curr!=NULL) {
            if(curr->next!=NULL && curr->next->data == curr->data) {
                while(curr->next!=NULL && curr->next->data == curr->data) {
                    curr->next = curr->next->next;
                }
                prev->next = curr->next;
            } else {
                prev = prev->next;
            }
            curr = curr->next;
        }
        head = dummy->next;
        print();
    }

    void removeKthFromEnd(int k) {
        Node* dummy = new Node(0);
        dummy->next = head;
        Node* fast = dummy;
        Node* slow = dummy;
        int a=0;
        while(fast!=NULL){
            if(a>k){
                slow = slow->next;
            }
            fast = fast->next;
            a++;
        }
        slow->next = slow->next->next;
        head = dummy->next;
        print();
    }

    void pairWiseSwap() {
        if(head==NULL || head->next==NULL) return;
        Node* curr = head->next->next;
        head->next->next = head;
        Node*prev = head;
        head = head->next;
        while(curr!=NULL && curr->next!=NULL) {
            Node* ahead = curr->next->next;
            curr->next->next = curr;
            prev->next = curr->next;
            prev = curr;
            curr = ahead;
        }
        prev->next = curr;
        print();
    }

    int detectCycle() {
        Node* fast = head;
        Node* slow = head;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow) {
                break;
            }
        }
        if(fast==NULL||fast->next==NULL){
            return -1;
        }
        slow = head;
        while(slow!=fast){
            fast = fast->next;
            slow = slow->next;
        }
        return slow->data;
    }

    void kReverse(int k) {
        Node* ptr = head;
        int size = 0;
        while(ptr!=NULL){
            ptr = ptr->next;
            size++;
        }
        if(k>size){
            print();
            return;
        }
        Node* prevTail;
        Node* mainHead;
        for(int i=1;i<=size/k;i++){
            Node* newHead;
            Node* newTail;
            for(int j=1;j<=k&&head!=NULL;j++){
                Node* t = head;
                if(j==1){
                    newTail = t;
                }
                head = head->next;
                t->next = newHead;
                newHead = t;
            }
            if(i==1){
                mainHead = newHead;
                prevTail = newTail;
            } else {
                prevTail->next = newHead;
                prevTail = newTail;
            }
        }
        if(head!=NULL){
            prevTail->next = head;
        } else {
            prevTail->next = NULL;
        }
        head = mainHead;
        print();
    }

    void foldLL() {  // on leetcode, with name "reordering linked list"
        Node* curr = head;
        stack<Node*> st;
        while(curr!=NULL){
            st.push(curr);
            curr = curr->next;
        }
        curr = head;
        Node* freshH = curr;
        Node* freshT = curr;
        while(curr!=NULL && curr->next!=NULL){
            Node* nxt = curr->next;
            Node* mid = st.top();
            st.pop();
            st.top()->next = NULL;
            if(nxt==mid){
                freshT->next = mid;
                mid->next = NULL;
                break;
            }
            freshT->next = mid;
            mid->next = nxt;
            freshT = nxt;
            curr = curr->next->next;
        }
        head = freshH;
        print();
    }

    int mid() {
        return mid(head)->data;
    }

    Node* mid(Node* h) {
        Node* fast = h;
        Node* slow = h;
        if(h->next->next == NULL) return h;
        //cout<<"hhh";
        while(fast!=NULL && fast->next!=NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    Node* merge(Node* a, Node* b){
        if(a==NULL) return b;
        if(b==NULL) return a;
        
        Node* c;
        if(a->data < b->data) {
            c = a;
            c->next = merge(a->next, b);
        } else {
            c = b;
            c->next = merge(a, b->next);
        }
        return c;
    }

    Node* mergeSort(Node* head){
        if(head==NULL || head->next == NULL){
            return head;
        }
        Node* md = mid(head);
        Node* a = head;
        Node* b = md->next;
        md->next = NULL;
        b = mergeSort(b);
        a = mergeSort(a);
        return merge(a,b);
    }

    void mergeSort() {
        Node* h = head;
        head = mergeSort(h);
        print();
    }

    void print() {
        Node *ptr = head;
        while(ptr!=NULL){
            if(ptr->next == NULL) {
                cout<<ptr->data;
                break;
            }
            cout<<ptr->data<<" => ";
            ptr = ptr->next;
        }
        cout<<endl;
    }
};

int main() {
    LinkedList *ll = new LinkedList();
    ll->addLast(4);
    ll->addLast(1);
    ll->addLast(3);
    ll->addLast(6);
    ll->addLast(2);
    ll->addLast(7);
    ll->addLast(5);
    ll->addLast(4);
    ll->addLast(5);
    ll->print();
    //cout<<ll->getNodeAt(2)->data;
    //ll->getNodeAt(5)->next = ll->getNodeAt(1);
    //ll->print();
    //ll->deleteFirst();
    //ll->print();
    //ll->deleteLast();
    //ll->print();
    //ll->deleteAtIdx(1);
    //ll->print();
    //cout<<ll->search(50);
    // ll->reverseLLPointerIterative();
    // ll->print();
    // ll->reverseLLPointerRecursive();
    // ll->print();
    // ll->reverseLLPointerRecursive2();
    // ll->print();
    //ll->removeDuplicates2();
    //ll->removeKthFromEnd(3);
    //ll->pairWiseSwap();
    //cout<<ll->detectCycle();
    //ll->kReverse(4);
    //ll->foldLL();
    ll->mergeSort();
    return 0;
}