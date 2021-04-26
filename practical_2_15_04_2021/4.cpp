#include<bits/stdc++.h>
using namespace std;

#define MAX 50

class STACK{
    int top;
    int stac[MAX];
public:
    STACK();
    int peep(int index);
    void push(int item);
    int pop();
};

STACK::STACK(){
    top=-1;
}

int STACK::peep(int index){
    if (index > top) cout << "Can't peek. Index out of bounds";
    else return stac[top-index+1];
    return -1;
 }

void STACK::push(int item){
    if (top==MAX) {
        cout << "Stack Overflow\nPop out some values first";
        return;
    }
    else stac[++top] = item;
}

int STACK::pop(){
    if (top==-1) {
        cout << "Stack Underflow\nPush in some values first";
    }
    else {
        return (stac[top--]);
    }
    return -1;
}

int main(){
    STACK s;
    for(int i=0; i<10; i++) s.push(i);

    cout << s.pop() << endl;
    cout << s.peep(3) << endl;
    cout << s.peep(30) << endl;
    cout << s.pop() << endl;
}
