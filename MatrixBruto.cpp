#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

// Converts an integer to a binary vector of size `n`
vector<int> toBinary(int value, int n) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = (value >> i) & 1;
    }
    return v;
}

int main() {
    int n;
    cout << "Introduzca n (Tamaño de la matriz: 2^n): ";
    cin >> n;
    int size = static_cast<int>(pow(2, n));
    vector<int> permutation = {};
    for (int i=0; i < size; i++) {
        permutation.insert(permutation.end(), i);
    }

    do {

    // Define dynamic 2D matrices
    vector<vector<int>> matriz(size, vector<int>(size));
    vector<vector<int>> matriz2(size, vector<int>(size));
    vector<vector<int>> mult(size, vector<int>(size, 0));

    // Fill matriz and matriz2 based on toBinary function and permutation
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            vector<int> v1 = toBinary(i, n);
            vector<int> v2 = toBinary(permutation[j % permutation.size()], n); // Use modulo to avoid out-of-bounds
            matriz[i][j] = pow(-1, inner_product(v1.begin(), v1.end(), v2.begin(), 0));
            matriz2[j][i] = matriz[i][j];  // Transpose
        }
    }

    // Multiply matriz and matriz2 and store result in mult
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                mult[i][j] += matriz[i][k] * matriz2[k][j];
            }
        }
    }

    if (mult[0][0] != size){
        cout << "mal!";
    }
    
    } while (next_permutation(permutation.begin(), permutation.end()));
    system("pause");
    return 0;
}
