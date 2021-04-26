#include<bits/stdc++.h>
using namespace std;

#define MAX 50

class circular_QUEUE{
    int q_fornt;
    int q_rear;
    char circular_queue[MAX];
    int size;
public:
    circular_QUEUE();
    bool underflow();
    bool overflow();
    void add(char item);
    char remove();
    int count();
};

circular_QUEUE::circular_QUEUE(){
    //circular_queue[MAX] = {'0'};
    q_fornt = 0;
    q_rear = 0;
    size = 0;
}

bool circular_QUEUE::underflow(){
    if (size==0) return true;
    else return false;
}

bool circular_QUEUE::overflow(){
    if (size==MAX) return true;
    else return false;
}

void circular_QUEUE::add(char item){
    if (overflow()) {
        cout << "Queue is full\nRemove some values first";
        return;
    }
    else circular_queue[++q_rear] = item, size++;
}

char circular_QUEUE::remove(){
    if (underflow()) {
        cout << "Queue is empty\nAdd some values first";
        return '-1';
    }
    else {
        q_fornt++;
        size--;
        return (circular_queue[q_fornt-1]);
    }
}

int main(){
    circular_QUEUE q;
    //q.remove();
    for(int i=0; i<10; i++) q.add(char(i+65));

    //cout << q.remove() << endl;
    q.add('Z');
    for(int i=0; i<12; i++) cout << q.remove() << endl ;

}
