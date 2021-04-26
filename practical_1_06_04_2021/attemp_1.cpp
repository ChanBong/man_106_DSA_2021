#include<bits/stdc++.h>
using namespace std;

#define MAX 3

/*
int main(){
    int A[MAX][MAX];
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            cin >> A[i][j];
        }
    }

    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            cout << A[j][i];
        }
    }
}
*/

/*

int main(){
    int A[MAX][MAX];
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            cin >> A[i][j];
        }
    }

    int base_addr = 1000;

    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            cout << "Address of a["<<i<<"]["<<j<<"]" << "is " << base_addr + i*12 + j*4 << "\t";
        }
        cout << '\n';
    }

    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            cout << "Address of a["<<j<<"]["<<i<<"]" << "is " << base_addr + j*12 + i*4 << " ";
        }
        cout << '\n';
    }

}
*/

void coulmn_major(int *mat, int m, int n){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++) cout << &mat[i+m*j] << " ";
    }
    cout << '\n';
}

void row_major(int *mat, int m, int n){
    for(int i=0; i<m*n; i++) cout << &mat[i] << " ";
    cout << '\n';
}

// P7
int main(){
    int mat[MAX][MAX] ;

    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            cin >> mat[i][j];
        }
    }

    cout << "Row Major\n" ; row_major(mat[0], MAX, MAX);
    cout << "Coulmn Major\n" ; coulmn_major(mat[0], MAX, MAX);
}


// void coulmn_reading(int *mat, int m, int n){
//     for(int i=0; i<m; i++){
//         for(int j=0; j<n; j++) cout << mat[i+m*j] << " ";
//         cout << '\n';
//     }
//     cout << '\n';
// }

// void row_reading(int *mat, int m, int n){
//     for(int i=0; i<m; i++){
//         for(int j=0; j<n; j++) cout << mat[i*m+j] << " ";
//         cout << '\n';
//     }
//     cout << '\n';
// }

// int main(){
//     int mat[MAX][MAX] ;

//     for(int i=0; i<MAX; i++){
//         for(int j=0; j<MAX; j++){
//             cin >> mat[i][j];
//         }
//     }

//     cout << "Row wise reading\n" ; row_reading(mat[0], MAX, MAX);
//     cout << "Coulmn wise reading\n" ; coulmn_reading(mat[0], MAX, MAX);
// }
