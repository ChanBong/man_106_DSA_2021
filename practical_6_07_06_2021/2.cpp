#include<bits/stdc++.h>
using namespace std;

#define MAX 100

class BST{
    int tree[MAX];
public :
    BST();
    void insert(int element);
    void traversal();
    void create(int *A, int n);
    int parent(int x);
    int left_child(int x);
    int right_child(int x);
    int search(int target);
    void tree_representation();
};

BST::BST(){
    for(int i=1; i<MAX; i++) tree[i] = -1;
    tree[0] = 0;
}

void BST::insert(int element){
    int root = 1;
    bool flag = false;
    for (int i=0; i<10; i++){
        if (tree[root] == -1) {
            tree[root] = element, flag = true;
            break;
        }
        if (tree[root] == element) break;
        else if (element < tree[root]){
            int left = 2*root;
            if (tree[left] != -1) root = left;
            else {
                tree[left] = element, flag = 1;
                break;
            }
        }
        else if (element > tree[root]){
            int right = 2*root + 1;
            if (tree[right] != -1) root = right;
            else {
                tree[right] = element, flag = 1;
                break;
            }
        }
    }

    if (flag) tree[0]++;

}

void BST::create(int *A, int n){
    for (int i=0; i<n; i++) insert(A[i]);
}

void BST::traversal(){
    int cnt=0;
    cout << "Size = " << tree[0] << "\n";
    for(int i=1; i<MAX; i++) {
        cout << tree[i] << " ";
        if (tree[i] != -1) cnt++;
        if (cnt == tree[0]) break;
    }
    cout << '\n';
}

void BST::tree_representation(){
    int cnt = 0, j=1;
    cout << setw(40);
    for (int i=1; i<MAX; i++){
        cout << tree[i] << " ";
        if (tree[i] != -1) cnt++;
        if (i == pow(2, j) - 1) cout << "\n" << setw(40 - pow(2, j)), j++;
        if (cnt == tree[0]) break;
    }
    cout << "\n";
}

int BST::parent(int x) { return tree[x/2]; }
int BST::left_child(int x) { return tree[2*x]; }
int BST::right_child(int x) { return tree[2*x+1]; }

int BST::search(int target){
    int root = 1;

    for (int i=0; i<10; i++){
        if (tree[root] == -1) {
            cout << "search unsuccesful ! key not present\n";
            return -1;
        }
        if (tree[root] == target) {
            cout << "search succesful\n";
            return root;
        }
        else if (target < tree[root]){
            int left = 2*root;
            if (tree[left] != -1) root = left;
            else {
                cout << "search unsuccesful ! key not present\n";
                return -1;
            }
        }
        else if (target > tree[root]){
            int right = 2*root + 1;
            if (tree[right] != -1) root = right;
            else {
                cout << "search unsuccesful ! key not present\n";
                return -1;
            }
        }
    }

    cout << "search unsuccesful ! key not present\n";
    return -1;
}

int main(){

    BST binary_tree;
    int A[] = {40, 30, 50, 20, 10, 60, 90, 80, 100, 70};
    binary_tree.create(A, 10);

    binary_tree.traversal();
    binary_tree.tree_representation();

    binary_tree.insert(15);
    binary_tree.tree_representation();

    int found = binary_tree.search(15);
    cout << "15 found at " << found << "\n";

    cout << binary_tree.parent(found) << " " << binary_tree.left_child(found) << " " << binary_tree.right_child(found) << "\n";

    return 0;
}
