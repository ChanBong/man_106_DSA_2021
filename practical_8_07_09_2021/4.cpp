#include<bits/stdc++.h>
using namespace std;

struct node{
    int vertex;
    node* next;
};


class undirected_graph{
private:
    int vertex;
    int edges;
    node** adl;
public:
    undirected_graph(int);
    bool isEdge(int , int);
    void addEdge(int,int);
    int degree(int);
    void delEdge(int,int);
    void print();
};

undirected_graph::undirected_graph(int v){
    vertex = v;
    edges = 0;
    adl = new node*[vertex];
    for(int i=0; i<vertex; i++) adl[i] = new node, adl[i]->vertex = i+1, adl[i]->next=NULL;
    cout << "Contructed\n";
}

bool undirected_graph::isEdge(int a, int b){
    auto temp = adl[a-1];
    for(; temp!=NULL; temp=temp->next) if (temp->vertex==b) return true;
    return false;
}

void undirected_graph::addEdge(int a, int b){
    auto temp = adl[a-1];
    node* member_1;
    member_1 = new node;
    member_1->vertex = b;
    member_1->next = NULL;

    while (temp->next!=NULL) temp=temp->next;
    temp->next = member_1;

    temp = adl[b-1];
    node* member_2;
    member_2 = new node;
    member_2->vertex = a;
    member_2->next = NULL;

    while (temp->next!=NULL) temp=temp->next;
    temp->next = member_2;
}

void undirected_graph::print(){
    for(int i=0; i<vertex; i++){
        auto temp = adl[i];
        temp = temp->next;
        while (temp!=NULL) {
            cout << "(" << i+1 << " ," << temp->vertex << ")";
            temp=temp->next;
        }
        cout << "\n";
    }
}


int undirected_graph::degree(int n){
    int deg = 0;
    auto temp = adl[n-1];
    temp = temp->next;
    for (; temp!=NULL; temp=temp->next) deg++;
    return deg;
}

void undirected_graph::delEdge(int a, int b){
    auto temp = adl[a-1];
    for (; temp->next!=NULL; temp=temp->next) {
        if(temp->next->vertex==b){
            auto curr = temp->next;
            temp->next = curr->next;
            delete curr;
        }
    }
    temp = adl[b-1];
    for (; temp->next!=NULL; temp=temp->next) {
        if(temp->next->vertex==a){
            auto curr = temp->next;
            temp->next = curr->next;
            delete curr;
        }
    }
}

int main(){

    undirected_graph D(4);

    D.addEdge(1,2);
    D.addEdge(1,3);
    D.addEdge(4,1);
    D.addEdge(2,3);


    D.print();

    cout << "\n" << (D.isEdge(3,2) ? "YES\n" : "NO\n");

    cout <<"Degree of 1: " << D.degree(1) << endl;
    cout <<"Degree of 2: " << D.degree(2) << endl;
    cout <<"Degree of 3: " << D.degree(3) << endl;
    cout <<"Degree of 4: " << D.degree(4) << endl;

    cout << "\n\nDeleting edge (3,1)\n";
    D.delEdge(3,1);

    D.print();

    return 0;
}
