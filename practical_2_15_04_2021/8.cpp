/*

For the tower of hanoi problem we can use this recursive realtion :
    Move n-1 disks from the source tower to the auxilary tower
    Move the last disk to the destination
    Move the n-1 diska back from auxilary tower to destination tower

    Accordidng to this realtion :

        a(n) = 1 + 2*(a(n-1))

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
    pair<int, string> pop();
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

pair<int, string> STACK::pop(){
    if (top==-1) {
        cout << "Stack Underflow\nPush in some values first";
        return (make_pair(-1, "-1"));
    }
    else {
        return (make_pair(stac[top--], name));
    }
}

bool STACK::empty_stack(){
    if (top==-1) return true;
    else return false;
}

void TOH(int n, STACK& source, STACK& destination, STACK& auxilary){
    if (n==1){
        auto popped = source.pop();
        cout << "Disk " << popped.first << " from " << popped.second << " transferred to " << destination.push(popped.first) << '\n';
        return ;
    }
    TOH(n-1, source, auxilary, destination);
    auto popped = source.pop();
    cout << "Disk " << popped.first << " from " << popped.second << " transferred to " << destination.push(popped.first) << '\n';
    TOH(n-1, auxilary, destination, source);
}

int main(){
    STACK source("A"), destination("C"), auxilary("B");
    int n=4;
    for(int i=n; i>0; i--) source.push(i);
    TOH(n, source, destination, auxilary);

}
