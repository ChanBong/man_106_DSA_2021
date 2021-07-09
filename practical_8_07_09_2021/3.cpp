#include<bits/stdc++.h>
using namespace std;

struct node{
    int vertex;
    node* next;
};


class directed_graph{
private:
    int vertex;
    int edges;
    node** adl;
public:
    directed_graph(int);
    bool isEdge(int , int);
    void addEdge(int,int);
    int inDegree(int);
    int outDegree(int);
    void delEdge(int,int);
    void print();
};

directed_graph::directed_graph(int v){
    vertex = v;
    edges = 0;
    adl = new node*[vertex];
    for(int i=0; i<vertex; i++) adl[i] = new node, adl[i]->vertex = i+1, adl[i]->next=NULL;
    cout << "Contructed\n";
}

bool directed_graph::isEdge(int a, int b){
    auto temp = adl[a-1];
    for(; temp!=NULL; temp=temp->next) if (temp->vertex==b) return true;
    return false;
}

void directed_graph::addEdge(int a, int b){
    auto temp = adl[a-1];
    node* member;
    member = new node;
    member->vertex = b;
    member->next = NULL;

    while (temp->next!=NULL) temp=temp->next;
    temp->next = member;
}

void directed_graph::print(){
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

int directed_graph::inDegree(int n){
    int indeg=0;
    for(int i=0; i<vertex; i++){
        if (i+1==n) continue;
        auto temp = adl[i];
        temp = temp->next;
        for (; temp!=NULL; temp=temp->next) if(temp->vertex==n) indeg++;
    }
    return indeg;
}

int directed_graph::outDegree(int n){
    int outdeg = 0;
    auto temp = adl[n-1];
    temp = temp->next;
    for (; temp!=NULL; temp=temp->next) outdeg++;
    return outdeg;
}

void directed_graph::delEdge(int a, int b){
    auto temp = adl[a-1];
    for (; temp->next!=NULL; temp=temp->next) {
        if(temp->next->vertex==b){
            cout << "Edge found\n";
            auto curr = temp->next;
            temp->next = curr->next;
            delete curr;
            cout << "Edge deleted\n";
            return ;
        }
    }
    cout << "Edge not found\n";
    return ;
}

int main(){

    directed_graph D(4);

    D.addEdge(1,2);
    D.addEdge(1,3);
    D.addEdge(1,4);
    D.addEdge(2,3);
    D.addEdge(3,1);
    D.addEdge(4,1);

    D.print();

    cout << "\n" << (D.isEdge(3,2) ? "YES\n" : "NO\n");

    cout <<"inDegree of 1: " << D.inDegree(1) << " , outDegree of 1: " << D.outDegree(1) << endl;
    cout <<"inDegree of 2: " << D.inDegree(2) << " , outDegree of 2: " << D.outDegree(2) << endl;
    cout <<"inDegree of 3: " << D.inDegree(3) << " , outDegree of 3: " << D.outDegree(3) << endl;
    cout <<"inDegree of 4: " << D.inDegree(4) << " , outDegree of 4: " << D.outDegree(4) << endl;

    cout << "\n\nDeleting edge (3,1)\n";
    D.delEdge(3,1);

    D.print();

    return 0;
}
