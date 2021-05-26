#include<bits/stdc++.h>
using namespace std;

struct node
{
    node *next;
    int degree;
    int coefficient;
};

class polynomials{
public:
    int deg;
    node *first_element;
    polynomials();
    bool isempty();
    void insert(pair<int, int> item);
    pair<int, int> remove(int item);
    void raise_power(pair<int, int> item);
    void traverse();
    void add_polynomial(polynomials A, polynomials B);
};

polynomials::polynomials(){
    deg = 0;
    first_element = new node;
    first_element->degree = 0;
    first_element->coefficient = 0;
    first_element->next = NULL;
}

bool polynomials::isempty(){
    if (first_element->next==NULL) return true;
    else return false;
}

void polynomials::traverse(){
    node *temp = first_element;
    while (temp->next!=NULL) cout << temp->coefficient << "x^(" << temp->degree << ") + " , temp = temp->next;
}

void polynomials::insert(pair<int, int> item){
    node *next_element;
    next_element = new node;
    next_element->degree = item.first;
    next_element->coefficient = item.second;
    node *temp = first_element;

    while (temp->next!=NULL && temp->next->degree < item.first) temp = temp->next;

    if (temp->next==NULL){
        temp->next = next_element;
        next_element->next = NULL;
        deg = next_element->degree;
    }
    else if (temp->next->degree == item.first) temp->next->coefficient += item.second;
    else next_element->next = temp->next, temp->next = next_element;
}

pair<int, int> polynomials::remove(int p){
    if (p > deg) {
        cout << "No such term exists\n";
        return make_pair(-1, -1);
    }

    auto temp = first_element;

    if (p==deg) {
        while (temp->next->next!=NULL) temp = temp->next;
        deg=temp->degree;
        cout << "temp->degree : " << deg <<"\n";
        pair<int, int> to_return = make_pair(temp->next->coefficient, temp->next->degree);
        temp->next = NULL;
        return to_return;
    }

    while (temp->next!=NULL && temp->next->degree != p) temp = temp->next;

    if (temp->next==NULL){
        cout << "No such term exists\n";
        return  make_pair(-1, -1);
    }
    else {
        pair<int, int> to_return = make_pair(temp->next->coefficient, temp->next->degree);
        auto prev = temp;
        prev->next = temp->next->next;
        return to_return;
    }
}

void polynomials::raise_power(pair<int, int> item){
    auto temp = first_element;
    while (temp->next!=NULL) temp->degree += item.first, temp->coefficient *= item.second;
}

void add_polynomial(polynomials A, polynomials B){
    auto temp_A = A.first_element;
    auto temp_B = B.first_element;

    polynomials C;

    while (temp_B!=NULL && temp_A!=NULL){
        if (temp_A->degree < temp_B->degree) C.insert(make_pair(temp_A->degree, temp_A->coefficient)), temp_A = temp_A -> next;
        else if (temp_B->degree < temp_A->degree) C.insert(make_pair(temp_B->degree, temp_B->coefficient)), temp_B = temp_B -> next;
        else if (temp_B->degree == temp_A->degree) C.insert(make_pair(temp_B->degree, temp_B->coefficient+temp_A->coefficient)), temp_B = temp_B->next, temp_A = temp_A->next;
    }

    if (temp_B==NULL) while (temp_A->next!=NULL) C.insert(make_pair(temp_A->degree, temp_A->coefficient)), temp_A = temp_A -> next;
    else if (temp_A==NULL) while (temp_B->next!=NULL) C.insert(make_pair(temp_B->degree, temp_B->coefficient)), temp_B = temp_B -> next;

    C.deg = max(A.deg, B.deg);
    C.traverse();
}

int main(){
    polynomials A, B;

    for(int i=0; i<5; i++) A.insert(make_pair(i, i+1));
    A.traverse();
    cout << A.deg << "\n";
    auto removed = A.remove(3);
    cout << "\n" <<  removed.first << " " << removed.second << "\n";
    A.traverse();
    cout << A.deg;

    return 0;
}
