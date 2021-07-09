#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left_child;
    node* right_child;

    node(int val, node* left_child = NULL, node* right_child = NULL): data(val), left_child(NULL), right_child(NULL){}
};

class BinartTree{
    node* ROOT;
public:
    void makeTree(int *A, int n);
    void print_tree();
    int depth(node *A);
    int find_depth();
};

void BinartTree::makeTree(int *A, int n){
    queue<node *> q;
    ROOT = new node(A[0]);
    q.push(ROOT);
    for(int i=0; i<n; ){
        auto prev = q.front();
        q.pop();
        prev->left_child = new node(A[++i]);
        prev->right_child = new node(A[++i]);
        q.push(prev->left_child);
        q.push(prev->right_child);
    }
}

void BinartTree::print_tree(){

    if (ROOT == NULL) return;

    stack<node *> s;
    s.push(ROOT);

    while (s.empty() == false){
        auto temp = s.top();
        s.pop();
        cout << temp->data << " ";
        if (temp->right_child) s.push(temp->right_child);
        if (temp->left_child) s.push(temp->left_child);
    }
    cout << "\n";
}

int BinartTree::depth(node *A){
    if (A == NULL) return 0;
    return max(depth(A->left_child)+1, depth(A->right_child)+1);
}

int BinartTree::find_depth(){
    return depth(ROOT);
}

int main(){
    BinartTree binary_tree;
    int A[] = {10, 20, 50, 30, 60, 80, 70, 90, 100, 40, 110};
    //int A[] = {1, -1, 3, -1, -1, 2, 4, -1, -1, -1, -1, -1, -1, -1, 5};
    binary_tree.makeTree(A, 10);

/*
                1
                    3
                  2    4
                          5
*/

/*
    Tree made :
                    10
            20             50
        30    60        80   70
    90   100  40  110

*/
    cout << "Pre-order traversal:\n";
    binary_tree.print_tree();

    cout << "\nDepth = " << binary_tree.find_depth();
}
