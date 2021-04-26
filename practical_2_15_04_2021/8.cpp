/*

For the tower of hanoi problem we can use this recursive realtion that is :
    Move n-1 disks from the source tower to the auxilary tower
    Move the last disk to the destination
    Move the n-1 diska back from auxilary tower to destination tower

    Accordidng to this realtion :

        a(n) = 1 + 2*(a(n)-1)

*/

#include<bits/stdc++.h>
using namespace std;

#define MAX 50

class STACK{
    int top;
    int stac[MAX];
    string name;
public:
    STACK(string A);
    STACK();
    bool empty_stack();
    string push(int item);
    int pop();
};

STACK::STACK(){
    top = -1;
    name = "default";
}

STACK::STACK(string A){
    top = -1;
    name = A;
}

string STACK::push(int item){
    if (top==MAX) {
        cout << "Stack Overflow\nPop out some values first";
        return name;
    }
    else {
        stac[++top] = item;
        return name;
    }
}

int STACK::pop(){
    if (top==-1) {
        cout << "Stack Underflow\nPush in some values first";
        return -1;
    }
    else {
        return (stac[top--]);
    }
}

bool STACK::empty_stack(){
    if (top==-1) return true;
    else return false;
}

void TOH(int n, STACK& source, STACK& destination, STACK& auxilary){
    if (n==1){
        auto popped = source.pop();
        cout << "Disk " << popped << "transferred to " << destination.push(popped) << '\n';
        return ;
    }
    TOH(n-1, source, auxilary, destination);
    auto popped = source.pop();
    cout << "Disk " << popped << "transferred to " << destination.push(popped) << '\n';
    TOH(n-1, auxilary, source, destination);
}

int main(){
    STACK source("A"), destination("C"), auxilary("B");
    int n;
    cin >> n;
    for(int i=n; i>0; i--) source.push(i);

    TOH(n, source, destination, auxilary);

}
