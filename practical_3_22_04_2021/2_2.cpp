#include<bits/stdc++.h>
using namespace std;

#define MAX 50

class string_QUEUE{
    int q_fornt;
    int q_rear;
    string string_queue[MAX];
    int size;
public:
    string_QUEUE();
    bool underflow();
    bool overflow();
    void add(string item);
    string remove();
    int count();
};

string_QUEUE::string_QUEUE(){
    //string_queue[MAX] = {'0'};
    q_fornt = 0;
    q_rear = 0;
    size = 0;
}

bool string_QUEUE::underflow(){
    if (size==0) return true;
    else return false;
}

bool string_QUEUE::overflow(){
    if (size==MAX) return true;
    else return false;
}

void string_QUEUE::add(string item){
    if (overflow()) {
        cout << "Queue is full\nRemove some values first";
        return;
    }
    else string_queue[++q_rear] = item, size++;
}

string string_QUEUE::remove(){
    if (underflow()) {
        cout << "Queue is empty\nAdd some values first";
        return "-1";
    }
    else {
        q_fornt++;
        size--;
        return (string_queue[q_fornt-1]);
    }
}

int main(){
    string_QUEUE q;
    //q.remove();
    string s;
    for(int i=0; i<10; i++) {
        s = "Hello World ";
        s+=(i+65);
        q.add(s);
    }

    //cout << q.remove() << endl;
    for(int i=0; i<12; i++) cout << q.remove() << endl ;

}
