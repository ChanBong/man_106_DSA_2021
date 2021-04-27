#include<bits/stdc++.h>
using namespace std;

#define MAX 20

class stack_type{
    int top;
    char stac[MAX];
public:
    stack_type();
    bool empty_stack();
    void push(char item);
    char pop();
};

stack_type::stack_type(){
    top = -1;
}

void stack_type::push(char item){
    if (top==MAX) {
        cout << "Stack Overflow\nPop out some values first";
        return;
    }
    else stac[++top] = item;
}

char stack_type::pop(){
    if (top==-1) {
        cout << "Stack Underflow\nPush in some values first";
        return -1;
    }
    else {
        return (stac[top--]);
    }
}

bool stack_type::empty_stack(){
    if (top==-1) return true;
    else return false;
}


int main(){
    stack_type S;
    char st[MAX], rev_st[MAX];
    cin >> st;
    bool flag = true;
    int i=0;
    for(; st[i]!='\0'; i++) S.push(st[i]);
    int k=i;
    for(; i>0; i--) {
        rev_st[k-i] =  S.pop();
        cout << rev_st[k-i] << " ";
    }

    cout << "\n";

    for(int i=0; i<k; i++) if (rev_st[i] != st[i]) flag = false;

    if (flag) cout << "The string is a palindrome\n";
    else cout << "Not a palindrome\n";

}
