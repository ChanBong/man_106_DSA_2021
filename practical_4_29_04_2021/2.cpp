#include<bits/stdc++.h>
using namespace std;

struct node{
    char element;
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
    void add(char item);
    char remove();
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

void QUEUE::add(char item){
    node *next_element;
    next_element = new node;
    next_element->element = item;
    next_element->next = NULL;
    if (q_rear == NULL) q_front = next_element;
    else q_rear->next = next_element;
    size++;
    q_rear = next_element;
}

char QUEUE::remove(){
    if (underflow()){
        cout << "Queue is empty. Add some values first\n";
        return '-';
    }
    else{
        node *temp;
        temp = q_front;
        char item = temp->element;
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
    for (int i=65; i<75; i++) q.add(char(i));
    cout << "There are " << q.count() << " elements in the queue\n";
    for (int i=0; i<11; i++){
        cout << q.remove() << '\n';
        cout << "There are " << q.count() << " elements in the queue\n";
    }
}
