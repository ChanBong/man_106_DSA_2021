#include<iostream>
using namespace std;

class weighted_graph{
private:
    int vertex;
    int edges; // Edges
    int** adl;

public:
    weighted_graph(int);
    bool isEdge(int,int);
    void addEdge(int,int, int);
    int degree(int);
    void delEdge(int,int);
    int nEdges();
    void print();

};

weighted_graph::weighted_graph(int v){
    vertex = v;
    edges = 0;
    adl = new int* [vertex];
    for (int i=0; i<vertex; i++) adl[i] = new int[vertex];
    for (int i=0; i<vertex; i++){
        for (int j=0; j<vertex; j++) adl[i][j] = 0;
    }
}

void weighted_graph::print(){
    cout << "\nAdjegency Matrix\n";
    for (int i=0; i<vertex; i++){
        for (int j=0; j<vertex; j++) cout << adl[i][j] << " ";
            cout << '\n';
    }

    cout << "Edges\n";
    for(int i=0; i<vertex; i++){
        for (int j=0; j< vertex; j++) if(adl[i][j]!=0) cout << "(" << i+1 << " ," << j+1 << " ," << adl[i][j] << ")";
        cout << "\n";
    }
    cout << "\n";
}

void weighted_graph::addEdge(int a, int b, int w){
    if (a-1 < vertex && b-1 < vertex) adl[a-1][b-1] = adl[b-1][a-1] = w, edges++;
}

int weighted_graph::degree(int node){
    int indeg=0;
    if (node > vertex) return -1;
    for(int i=0; i<vertex; i++) if (adl[i][node-1] != 0) indeg++;
    return indeg;
}

bool weighted_graph::isEdge(int a, int b){
    if (a < vertex && b < vertex && adl[a-1][b-1]==1) return true;
    else return false;
}

void weighted_graph::delEdge(int a, int b){
    if (a < vertex && b < vertex) adl[a-1][b-1] = adl[b-1][a-1] = 0, edges--;
}

int weighted_graph::nEdges(){
    return edges;
}

int main(){
    weighted_graph D(4);

    D.addEdge(1,2,6);
    D.addEdge(2,3,5);
    D.addEdge(4,1,2);
    D.addEdge(4,3,1);

    D.print();

    cout <<"Degree of 1: " << D.degree(1) << endl;
    cout <<"Degree of 2: " << D.degree(2) << endl;
    cout <<"Degree of 3: " << D.degree(3) << endl;
    cout <<"Degree of 4: " << D.degree(4) << endl;

    cout << "\n\nDeleting edge  (2,3)\n";
    D.delEdge(2,3);

    D.print();
}
