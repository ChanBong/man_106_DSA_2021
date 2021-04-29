#include<bits/stdc++.h>
using namespace std;

#define MAX 10

class QUEUE{
    int q_fornt;
    int q_rear;
    int queue[MAX];
    int size;
public:
    QUEUE();
    bool underflow();
    bool overflow();
    void add(int item);
    int remove();
    int count();
};

QUEUE::QUEUE(){
    queue[MAX] = {0};
    q_fornt = MAX-1;
    q_rear = MAX-1;
    size = 0;
}

bool QUEUE::underflow(){
    if (size==0) return true;
    else return false;
}

bool QUEUE::overflow(){
    if (size==MAX) return true;
    else return false;
}

void QUEUE::add(int item){
    if (overflow()) {
        cout << "Queue is full\nRemove some values first\n";
        return;
    }
    else queue[(q_rear--)%MAX] = item, size++;
}

int QUEUE::remove(){
    if (underflow()) {
        cout << "Queue is empty\nAdd some values first\n";
        return -1;
    }
    else {
        size--;
        return (queue[(q_fornt--)%MAX]);
    }
}

int QUEUE::count(){
    return size;
}

int main(){
    QUEUE q;
    for(int i=0; i<11; i++) q.add(i+1);

    cout << q.remove() << endl; // As sopn as your remove a space is ceated
    q.add(42); // Added due to circular queue
    for(int i=0; i<10; i++) cout << q.remove() << endl ;

}


