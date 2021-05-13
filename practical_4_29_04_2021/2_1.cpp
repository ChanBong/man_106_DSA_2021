#include<bits/stdc++.h>
using namespace std;

struct node{
    string element;
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
    void add(string item);
    string remove();
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

void QUEUE::add(string item){
    node *next_element;
    next_element = new node;
    next_element->element = item;
    next_element->next = NULL;
    if (q_rear == NULL) q_front = next_element;
    else q_rear->next = next_element;
    size++;
    q_rear = next_element;
}

string QUEUE::remove(){
    if (underflow()){
        cout << "Queue is empty. Add some values first\n";
        return "NA";
    }
    else{
        node *temp;
        temp = q_front;
        string item = temp->element;
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
    string s = "Hello World";
    for (int i=65; i<70; i++){
        s.push_back(i);
        q.add(s);
    }
    cout << "There are " << q.count() << " elements in the queue\n";
    for (int i=0; i<6; i++){
        cout << q.remove() << '\n';
        cout << "There are " << q.count() << " elements in the queue\n";
    }
}
