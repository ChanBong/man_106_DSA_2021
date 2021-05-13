#include<bits/stdc++.h>
using namespace std;

struct node{
    int element;
    node *next;
};

class C_QUEUE{
    node *q_front;
    node *q_rear;
    int size;
public:
    C_QUEUE();
   ~C_QUEUE();
    bool underflow();
    void add(int item);
    int remove();
    int count();
};

C_QUEUE::C_QUEUE(){
    q_front = NULL;
    q_rear = NULL;
    size = 0;
}

C_QUEUE::~C_QUEUE(){
    while (!underflow()) remove();
}

bool C_QUEUE::underflow(){
    if (q_front==NULL) return true;
    else return false;
}

void C_QUEUE::add(int item){
    node *next_element;
    next_element = new node;
    next_element->element = item;
    next_element->next = q_front;
    if (q_rear == NULL) q_front = next_element;
    else q_rear->next = next_element;
    size++;
    q_rear = next_element;
}

int C_QUEUE::remove(){
    if (underflow()){
        cout << "Queue is empty. Add some values first\n";
        return -1;
    }
    else if (q_front==q_rear){
       int item = q_front->element;
       delete(q_rear);
       q_front=NULL;
       size--;
       return item;
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

int C_QUEUE::count(){
    return size;
}

int main(){
    C_QUEUE q;
    for (int i=0; i<10; i++) q.add(i+1);
    cout << "There are " << q.count() << " elements in the queue\n";
    for (int i=0; i<11; i++){
        cout << q.remove() << '\n';
        cout << "There are " << q.count() << " elements in the queue\n";
    }
}
