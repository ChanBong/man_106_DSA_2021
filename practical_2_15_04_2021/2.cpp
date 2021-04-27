#include<bits/stdc++.h>
using namespace std;

#define MAX 50

class STACK{
    int top;
    float stac[MAX];
public:
    STACK();
    bool underflow();
    bool overflow();
    void push(float item);
    float pop();
};

STACK::STACK(){
    top = MAX;
}

bool STACK::underflow(){
    if (top==-1) return true;
    else return false;
}

bool STACK::overflow(){
    if (top==MAX) return true;
    else return false;
}

void STACK::push(float item){
    if (overflow()) {
        cout << "Stack Overflow\nPop out some values first";
        return;
    }
    else stac[++top] = item;
}

float STACK::pop(){
    if (top==-1) {
        cout << "Stack Underflow\nPush in some values first";
        return -1.0;
    }
    else {
        return (stac[top--]);
    }
}


