#include <iostream>
#include <vector>
using namespace std;
#define endl '\n';

vector<vector<int>> takeInput(int rows, int col) {
    vector<vector<int>> matrix(rows, vector<int> (col,0));
    for(int i = 0 ; i < (int)matrix.size() ; i++){
        for(int j = 0 ; j < (int)matrix[i].size() ; j++){
            cout << "Enter the: [" << i << "] and [" << j << "] element of the matrix: ";  
            cin >> matrix[i][j];
        }
    }
    return matrix;
}
void printMatrix(vector<vector<int>> matrix) {
    cout << "The Matrix is: \n";
    for(int i = 0 ; i < (int)matrix.size() ; i++){
        for(int j = 0 ; j < (int)matrix[i].size() ; j++){
            cout << matrix[i][j] << '\t';
        }
        cout << '\n';
    }
}
vector<vector<int>> MatAddition(vector<vector<int>> matrix1, vector<vector<int>> matrix2) {
    vector<vector<int>> resAdd(matrix1.size(), vector<int> (matrix1[0].size(),0));
    for(int i = 0 ; i < (int)matrix1.size() ; i++){
        for(int j = 0 ; j < (int)matrix1[i].size() ; j++){
            resAdd[i][j] = matrix1[i][j]+matrix2[i][j];
        }
    }
    return resAdd;
}

vector<vector<int>> MatMultiplication(vector<vector<int>> matrix1, vector<vector<int>> matrix2) {
    vector<vector<int>> resMut(matrix1.size(), vector<int> (matrix2[0].size(),0));
    for(int i = 0 ; i < (int)matrix1.size() ; i++){
        for(int j = 0 ; j < (int)matrix1[i].size() ; j++){
            for(int k = 0 ; k < (int)matrix1[0].size() ; k++){
                resMut[i][j] += matrix1[i][k]*matrix2[k][j];
            }
        }
    }
    return resMut;
}
vector<vector<int>> MatTranspose(vector<vector<int>> matrix1) {
    vector<vector<int>> resTrans(matrix1[0].size(), vector<int> (matrix1.size(),0));
    for(int i = 0 ; i < (int)matrix1.size() ; i++){
        for(int j = 0 ; j < (int)matrix1[i].size() ; j++){
                resTrans[j][i] = matrix1[i][j];
        }
    }
    return resTrans;
}
int main() {
    cout << "Enter the the rows and columns of the matrix: ";
    int rows{},col{}; cin >> rows >> col;
    vector<vector<int>> matrix1;
    vector<vector<int>> matrix2;
    vector<vector<int>> resAdd;
    vector<vector<int>> resMut;
    vector<vector<int>> resTranspose1;
    vector<vector<int>> resTranspose2;
    matrix1 = takeInput(rows,col);
    printMatrix(matrix1);
    matrix2 = takeInput(rows,col);
    printMatrix(matrix2);
    resAdd = MatAddition(matrix1,matrix2);
    cout << "Result of matrix addition is:\n";
    printMatrix(resAdd);
    cout << "Result of matrix multiplication is:\n";
    resMut = MatMultiplication(matrix1,matrix2);
    printMatrix(resMut);
    cout << "Result of matrix Transpose of matrix 1 is:\n";
    resTranspose1 = MatTranspose(matrix1);
    printMatrix(resTranspose1);
    cout << "Result of matrix Transpose of matrix 2 is:\n";
    resTranspose2 = MatTranspose(matrix2);
    printMatrix(resTranspose2);
    return 0;
}