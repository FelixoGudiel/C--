#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

// De int a binario en un vector de tamaño n
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
    vector<int> permutation(size);
    cout << "Introduzca la permutación de tamaño " << size << " (separado por espacios): ";
    for (int i = 0; i < size; ++i) {
        cin >> permutation[i];
    }



    // Comprobación : Verificar que los valores sean únicos y estén en el rango correcto
    vector<int> expected(size);
    iota(expected.begin(), expected.end(), 0); 
    vector<int> sorted_permutation = permutation; 
    sort(sorted_permutation.begin(), sorted_permutation.end());

    if (sorted_permutation != expected) {
        cout << "Error: La permutación debe contener todos los valores únicos desde 0 hasta " << size - 1 << ".\n";
        return 1;
    }
    
    // Definir matrices
    vector<vector<int>> matriz(size, vector<int>(size));
    vector<vector<int>> matriz2(size, vector<int>(size));
    vector<vector<int>> mult(size, vector<int>(size, 0));

    // Rellenar matrices
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            vector<int> v1 = toBinary(i, n);
            vector<int> v2 = toBinary(permutation[j], n); 
            matriz[i][j] = pow(-1, inner_product(v1.begin(), v1.end(), v2.begin(), 0));
            matriz2[j][i] = matriz[i][j]; //Traspuesta
        }
    }

    // Multiplicar matrices
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                mult[i][j] += matriz[i][k] * matriz2[k][j];
            }
        }
    }

    // Print Matriz
    cout << "Matriz:\n";
    for (const auto& row : matriz) {
        for (int val : row) {
            cout << setw(3) << val << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Print Matriz2 (Traspuesta)
    cout << "Matriz2 (Traspuesta):\n";
    for (const auto& row : matriz2) {
        for (int val : row) {
            cout << setw(3) << val << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Print mult (matriz x matriz2)
    cout << "Matriz x Matriz2:\n";
    for (const auto& row : mult) {
        for (int val : row) {
            cout << setw(3) << val << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
