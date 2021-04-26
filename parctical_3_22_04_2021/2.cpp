#include<bits/stdc++.h>
using namespace std;

#define MAX 50

class char_QUEUE{
    int q_fornt;
    int q_rear;
    char char_queue[MAX];
    int size;
public:
    char_QUEUE();
    bool underflow();
    bool overflow();
    void add(char item);
    char remove();
    int count();
};

char_QUEUE::char_QUEUE(){
    //char_queue[MAX] = {'0'};
    q_fornt = 0;
    q_rear = 0;
    size = 0;
}

bool char_QUEUE::underflow(){
    if (size==0) return true;
    else return false;
}

bool char_QUEUE::overflow(){
    if (size==MAX) return true;
    else return false;
}

void char_QUEUE::add(char item){
    if (overflow()) {
        cout << "Queue is full\nRemove some values first";
        return;
    }
    else char_queue[++q_rear] = item, size++;
}

char char_QUEUE::remove(){
    if (underflow()) {
        cout << "Queue is empty\nAdd some values first";
        return '-1';
    }
    else {
        q_fornt++;
        size--;
        return (char_queue[q_fornt-1]);
    }
}

int main(){
    char_QUEUE q;
    //q.remove();
    for(int i=0; i<10; i++) q.add(char(i+65));

    //cout << q.remove() << endl;
    q.add('Z');
    for(int i=0; i<12; i++) cout << q.remove() << endl ;

}
