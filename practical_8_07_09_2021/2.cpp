#include<iostream>
using namespace std;

class directed_graph{
private:
    int vertex;
    int edges;
    int** adl;

public:
    directed_graph(int);
    bool isEdge(int,int);
    void addEdge(int,int);
    int inDegree(int);
    int outDegree(int);
    void delEdge(int,int);
    int nEdges();
    void print();

};

directed_graph::directed_graph(int v){
    vertex = v;
    edges = 0;
    adl = new int* [vertex];
    for (int i=0; i<vertex; i++) adl[i] = new int[vertex];
    for (int i=0; i<vertex; i++){
        for (int j=0; j<vertex; j++) adl[i][j] = 0;
    }
}

void directed_graph::print(){
    cout << "\nAdjegency Matrix\n";
    for (int i=0; i<vertex; i++){
        for (int j=0; j<vertex; j++) cout << adl[i][j] << " ";
            cout << '\n';
    }

    cout << "Edges\n";
    for(int i=0; i<vertex; i++){
        for (int j=0; j< vertex; j++) if(adl[i][j]==1) cout << "(" << i+1 << " ," << j+1 << ")\n";
    }
    cout << "\n";
}

void directed_graph::addEdge(int a, int b){
    if (a-1 < vertex && b-1 < vertex) adl[a-1][b-1] = 1, edges++;
}

int directed_graph::inDegree(int node){
    int indeg=0;
    if (node > vertex) return -1;
    for(int i=0; i<vertex; i++) indeg+= adl[i][node-1];
    return indeg;
}

int directed_graph::outDegree(int node){
    int outdeg=0;
    if (node > vertex) return -1;
    for(int i=0; i<vertex; i++) outdeg+= adl[node-1][i];
    return outdeg;
}

bool directed_graph::isEdge(int a, int b){
    if (a < vertex && b < vertex && adl[a-1][b-1]==1) return true;
    else return false;
}

void directed_graph::delEdge(int a, int b){
    if (a < vertex && b < vertex) adl[a-1][b-1] = 0, edges--;
}

int directed_graph::nEdges(){
    return edges;
}

int main(){
    directed_graph D(4);

    D.addEdge(1,2);
    D.addEdge(2,3);
    D.addEdge(3,2);
    D.addEdge(4,1);
    D.addEdge(4,3);

    D.print();

    cout <<"inDegree of 1: " << D.inDegree(1) << " , outDegree of 1: " << D.outDegree(1) << endl;
    cout <<"inDegree of 2: " << D.inDegree(2) << " , outDegree of 2: " << D.outDegree(2) << endl;
    cout <<"inDegree of 3: " << D.inDegree(3) << " , outDegree of 3: " << D.outDegree(3) << endl;
    cout <<"inDegree of 4: " << D.inDegree(4) << " , outDegree of 4: " << D.outDegree(4) << endl;

    cout << "\n\nDeleting edge  (2,3)\n";
    D.delEdge(2,3);

    D.print();
}
