#include<bits/stdc++.h>
using namespace std;

int partition (int *A, int lower, int upper, int order){
    int left = lower, right = upper;
    int pivot = left;
    while (left < right){

        if (pivot == left){
            if (order*A[left] > order*A[right]) right--;
            else {
                swap(A[left], A[right]);
                left++;
                pivot = right;
            }
        }
        else {
            if (order*A[left] > order*A[right]) left++;
            else {
                swap(A[left], A[right]);
                right--;
                pivot = left;
            }
        }
    }

    cout << "Pivot is " << pivot << " and pivot element is " << A[pivot] << "\nArray before this partition is\n";

    for(int i=0; i<9; i++) cout << A[i] << " ";
    cout << "\n\n";

    return pivot;

}

void quick_sort(int *A, int lower, int upper, int order){

    stack<int> s;
    s.push(lower);
    s.push(upper);

    while(!s.empty()){

        int right = s.top(); s.pop();
        int left = s.top(); s.pop();

        int pivot = partition(A, left, right, order);

        if(pivot + 1 < right){
            s.push(pivot+1);
            s.push(right);
        }

        if(pivot-1 > left){
            s.push(left);
            s.push(pivot-1);
        }
    }
}

int A[] = {6,4,9,3,5,2,1,7,8};

int main (){

    // order = 1 if descending , and -1 if ascendng;
    quick_sort(A, 0, 8, -1);

    cout << "Sorted array\n";
    for(int i=0; i<9; i++) cout << A[i] << " ";
    cout << endl;
}
