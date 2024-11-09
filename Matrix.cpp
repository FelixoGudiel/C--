#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip> 
#include <cmath> 

const int SIZE = 16;

using namespace std;

vector<int> myFunction(int value) {
    vector<int> v(4);
    for (int i = 0; i < 4; ++i) {
        v[i] = (value >> i) & 1;
    }
    return v;
}


int main() {
    vector<int> permutation =  {8,3,10,6,12,5,9,0,7,14,4,13,1,2,15,11};
    int matriz[16][16];
    int matriz2[16][16];
    int filas = (sizeof(matriz) / sizeof(matriz[0]));
    int columnas = (sizeof(matriz[0]) / sizeof(matriz[0][0]));

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            vector<int> v1 = myFunction(i);
            vector<int> v2 = myFunction(permutation[j]);
            matriz[i][j] = pow(-1, inner_product(v1.begin(), v1.end(), v2.begin(), 0));
            matriz2[j][i] = pow(-1, inner_product(v1.begin(), v1.end(), v2.begin(), 0));
        }
    }
    int mult[16][16] = {};

    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            for (int k = 0; k < 16; ++k) {
                mult[i][j] += matriz[i][k] * matriz2[k][j];
            }
        }
    }

    for (int a = 0; a < filas; a++) {
        for (int b = 0; b < columnas; b++) {
            cout << setw(3) << matriz[a][b] << " "; 
        }
        cout << endl;
    }
    cout << endl;
    for (int a = 0; a < filas; a++) {
        for (int b = 0; b < columnas; b++) {
            cout << setw(3) << matriz2[a][b] << " "; 
        }
        cout << endl;
    }
    cout << endl;
    for (int a = 0; a < filas; a++) {
        for (int b = 0; b < columnas; b++) {
            cout << setw(3) << mult[a][b] << " "; 
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
