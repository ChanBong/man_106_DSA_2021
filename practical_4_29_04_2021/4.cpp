#include<bits/stdc++.h>
using namespace std;

struct node{
    float element;
    node *next;
};

class STACK{
    node *top;
public:
    STACK();
   ~STACK();
    bool underflow();
    void push(float item);
    float pop();
};

STACK::STACK(){
    top = NULL;
}

STACK::~STACK(){
    while (!underflow()) pop();
    delete top;
}

bool STACK::underflow(){
    if (top==NULL) return true;
    else return false;
}

void STACK::push(float item){
    node *next_element;
    next_element = new node;
    next_element->element = item;
    next_element->next = top;
    top = next_element;
}

float STACK::pop(){
    if (underflow()){
        cout << "Stack underflow. Push some values first\n";
        return -1;
    }
    else{
        node *temp;
        temp = top;
        float item = temp->element;
        top = temp->next;
        delete temp;
        return item;
    }
}

int main(){
    STACK s, t;
    for (int i=0; i<10; i++) s.push(float(i+1)+0.12);
    cout << "Initial stack:\n";
    for (int i=0; i<10; i++) {
        float last_element = s.pop();
        cout << last_element << '\n';
        t.push(last_element);
    }
    cout << "Inverted stack:\n";
    for (int i=0; i<10; i++) cout << t.pop() << '\n';
}
