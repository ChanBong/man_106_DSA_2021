#include<iostream>
#include<string>

using namespace std;

#define MAX 50

class QUEUE{
    int q_fornt;
    int q_rear;
    string queue[MAX];
    int size;
public:
    QUEUE();
    bool underflow();
    bool overflow();
    void add(string item);
    string remove();
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
    if (q_rear==-1) return true;
    else return false;
}

void QUEUE::add(string item){
    if (overflow()) {
        cout << "Queue is full\nRemove some values first\n";
        return;
    }
    else queue[q_rear--] = item, size++;
}

string QUEUE::remove(){
    if (underflow()) {
        cout << "Queue is empty\nAdd some values first\n";
        return "NA";
    }
    else {
        size--;
        return (queue[q_fornt--]);
    }
}

int QUEUE::count(){
    return size;
}

int main(){
    QUEUE q;
    string s = "Hello World";
    for(int i=49; i<58; i++){
        s.push_back(char(i));
        q.add(s);
    }
    cout << q.remove() << endl;

    for(int i=0; i<9; i++) cout << q.remove() << endl ;
    q.remove();

}


