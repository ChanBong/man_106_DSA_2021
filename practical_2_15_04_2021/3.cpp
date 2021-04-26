#include<bits/stdc++.h>
using namespace std;

#define MAX 10

class TwoStack{
    int top1;
    int top2;
    int stac[MAX];
public:
    TwoStack();
    void push1(int item);
    void push2(int item);
    int pop1();
    int pop2();
    bool is_collision();
};

TwoStack::TwoStack(){
    top1 = -1;
    top2 = MAX;
}

void TwoStack::push1(int item){
    if (is_collision()) cout << "Stack Overflow\nPop out some values first\n";
    else stac[++top1] = item;
}

void TwoStack::push2(int item){
    if (is_collision()) cout << "Stack Overflow\nPop out some values first\n";
    else stac[--top2] = item;
}

int TwoStack::pop1(){
    if (top1==-1) cout << "Stack Underflow\nPush some values first\n";
    else return(stac[top1--]);
}

int TwoStack::pop2(){
    if (top2==MAX){
        cout << "Stack Underflow\nPush some values first\n";
        //return -1;
    }
    else{
        return(stac[top2++]);
    }
}

bool TwoStack::is_collision(){
    if (top2-top1 < 1) return true;
    else return false;
}


int main(){
    TwoStack S;
    for(int i=1; i<6; i++) {
        S.push1(i); S.push2(10-i); }
    for(int i=0; i<5; i++){
        cout << S.pop1() << " :From Stack1, " << S.pop2() << " :From Stack2\n";
    }
}
