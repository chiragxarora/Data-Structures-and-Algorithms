#include <iostream>
#include<string>

using namespace std;

class Car {
private: 
    float price;  // 4 bytes
public:
    int model_no; // 4 bytes
    string name;  // 24 bytes

    Car() {
        cout<<"Inside default constructor!\n";
    }
    Car(float p, int m, string n) {
        cout<<"Inside parameterised constructor!\n";
        price = p;
        model_no = m;
        name = n;
    }

    Car(Car& c){
        cout<<"Inside copy constructor\n";
        price = c.price;
        model_no = c.model_no;
        name = c.name;
    }

    float applyDiscount(float x) {
        price = (1-x)*price;
        return price;
    }

    void setPrice(float p){
        float msp = 100;
        if(p > msp){
            msp = p;
        }
        price = msp;
    }

    void print() {
        cout<<"Name : "<<name<<endl;
        cout<<"Model : "<<model_no<<endl;
        cout<<"Price : "<<price<<endl;
    }
};

int main() {
    Car c;
    //cout<<sizeof(c)<<endl;
    //cout<<sizeof(Car)<<endl;   // not using actual bytes in memory
    c.setPrice(250);
    c.model_no = 2;
    c.name = "BMW";
    //cout<<c.name<<" model "<<c.model_no<<" priced at "<<c.price;
    //c.applyDiscount(0.3);
    c.print();
    Car d(1700,3,"Audi");
    Car e(d);  // copy condtructor, copies data of d into e!!
    Car f = e; // copy constructor
    e.setPrice(569);
    d.print();
    e.print();
    return 0;
}