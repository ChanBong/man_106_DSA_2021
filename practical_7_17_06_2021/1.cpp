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

    if (lower >= upper) return ;

    int pivot = partition(A, lower, upper, order);

    quick_sort(A, lower, pivot-1, order);
    quick_sort(A, pivot+1, upper, order);
}


int main (){

    // order = 1 if descending , and -1 if ascendng;
    int A[] = {23, 72, 16, 30, 19,76, 42, 65, 25, 10, 80};
    quick_sort(A, 0, 8, 1);

    cout << "Sorted array\n";
    for(int i=0; i<9; i++) cout << A[i] << " ";
    cout << endl;
}
