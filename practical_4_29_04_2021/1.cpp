#include<bits/stdc++.h>
using namespace std;

struct node{
    int element;
    node *next;
};

class QUEUE{
    node *q_front;
    node *q_rear;
    int size;
public:
    QUEUE();
   ~QUEUE();
    bool underflow();
    void add(int item);
    int remove();
    int count();
};

QUEUE::QUEUE(){
    q_front = NULL;
    q_rear = NULL;
    size = 0;
}

QUEUE::~QUEUE(){
    while (!underflow()) remove();
    delete q_front, q_rear;
}

bool QUEUE::underflow(){
    if (q_front==NULL) return true;
    else return false;
}

void QUEUE::add(int item){
    node *next_element;
    next_element = new node;
    next_element->element = item;
    next_element->next = NULL;
    if (q_rear == NULL) q_front = next_element;
    else q_rear->next = next_element;
    size++;
    q_rear = next_element;
}

int QUEUE::remove(){
    if (underflow()){
        cout << "Queue is empty. Add some values first\n";
        return -1;
    }
    else{
        node *temp;
        temp = q_front;
        int item = temp->element;
        q_front = temp->next;
        size--;
        delete temp;
        return item;
    }
}

int QUEUE::count(){
    return size;
}

int main(){
    QUEUE q;
    for (int i=0; i<10; i++) q.add(i+1);
    cout << "There are " << q.count() << " elements in the queue\n";
    for (int i=0; i<11; i++){
        cout << q.remove() << '\n';
        cout << "There are " << q.count() << " elements in the queue\n";
    }
}
