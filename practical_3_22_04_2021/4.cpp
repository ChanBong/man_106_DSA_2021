#include<bits/stdc++.h>
using namespace std;

#define MAX 20

class QUEUE{
    int q_front;
    int q_rear;
    int queue[MAX];
    int size;
public:
    QUEUE();
    bool underflow();
    bool overflow();
    void add_front(int item);
    void add_back(int item);
    int remove_front();
    int remove_back();
    int count();
};

QUEUE::QUEUE(){
    queue[MAX] = {0};
    q_front = 0;
    q_rear = 1;
    size = 0;
}

bool QUEUE::underflow(){
    if (q_front==0 || q_rear==1) return true;
    else return false;
}

bool QUEUE::overflow(){
    if (q_front==q_rear) return true;
    else return false;
}

void QUEUE::add_front(int item){
    if (overflow()) {
        cout << "Queue is full\nRemove some values first\n";
        return;
    }
    else {
        q_front-= 1;
        if (q_front==-1) q_front = MAX-1;
        queue[(q_front)%MAX] = item, size++;
    }
}

void QUEUE::add_back(int item){
    if (overflow()) {
        cout << "Queue is full\nRemove some values first\n";
        return;
    }
    else {
        q_rear+=1;
        queue[(q_rear)%MAX] = item, size++;
    }
}

int QUEUE::remove_front(){
    if (underflow()) {
        cout << "Queue is empty\nAdd some values first\n";
        return -1;
    }
    else {
        size--;
        return (queue[(q_front++)%MAX]);
    }
}

int QUEUE::remove_back(){
    if (underflow()) {
        cout << "Queue is empty\nAdd some values first\n";
        return -1;
    }
    else {
        size--;
        return (queue[(q_rear--)%MAX]);
    }
}

int QUEUE::count(){
    return size;
}

int main(){
    QUEUE q;
    for(int i=0; i<5; i++) q.add_front(i+1);
    for(int i=10; i<15; i++) q.add_back(i);
    cout << "Removing from back:\n";
    for(int i=0; i<4; i++) cout << q.remove_back() << endl ;
    cout << "Removing from front:\n";
    for(int i=0; i<5; i++) cout << q.remove_front() << endl ;
}


