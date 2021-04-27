#include<bits/stdc++.h>
using namespace std;

#define MAX 50

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
    q_fornt = 0;
    q_rear = -1;
    size = 0;
}

bool QUEUE::underflow(){
    if (size==0) return true;
    else return false;
}

bool QUEUE::overflow(){
    if (q_rear==MAX) return true;
    else return false;
}

void QUEUE::add(int item){
    if (overflow()) {
        cout << "Queue is full\nRemove some values first\n";
        return;
    }
    else queue[++q_rear] = item, size++;
}

int QUEUE::remove(){
    if (underflow()) {
        cout << "Queue is empty\nAdd some values first\n";
        return -1;
    }
    else {
        q_fornt++;
        size--;
        return (queue[q_fornt-1]);
    }
}

int main(){
    QUEUE q;
    for(int i=0; i<10; i++) q.add(i+1);

    cout << q.remove() << endl;
    q.add(11);
    for(int i=0; i<10; i++) cout << q.remove() << endl ;

}


