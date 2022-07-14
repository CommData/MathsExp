#include <iostream>
using namespace std;

class matrix{
    public:
    int rows{},cols{};
    int **mat = new int* [7]();
    public: 
    matrix(int rows, int cols){
        this->rows = rows;
        this->cols = cols;
        for(int i = 0 ; i < rows ; i++)this->mat[i] = new int[7]();
    }
    void fillArray(){
        cout << "please enter the elements of matrix separated by space\n";
        for(int i = 0 ; i < this->rows ; i++){
            for(int j = 0 ; j < this->cols ; j++){
                cin >> this->mat[i][j];
            }
        }
    }
    void printArray(){
        cout << "\n";
        for(int i = 0 ; i < this->rows ; i++){
            for(int j = 0 ; j < this->cols; j++){
                cout << this->mat[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    matrix operator * (matrix const &matB){
        if(this->cols != matB.rows){
            cout << "Matrix Multiplication can't be done on this set of matrices!\n";
            exit(0);
        }
        matrix result(this->rows,matB.cols);
        for(int i = 0 ; i < this->rows ; i++){
            for(int j = 0 ; j < matB.cols ; j++){
                for(int k = 0 ; k < this->cols; k++){
                    result.mat[i][j] += this->mat[i][k]*matB.mat[k][j]; 
                }
            }
        }
        return result;
    }
    matrix operator + (matrix const &matB){
        if(this->rows != matB.rows && this->cols != matB.cols){
            cout << "Matrix Addition can't be done on this set of matrices!\n";
            exit(0);
        }
        matrix result(this->rows,this->cols);
        for(int i = 0 ; i < this->rows; i++){
            for(int j = 0 ; j < this->cols; j++){
                result.mat[i][j] = this->mat[i][j]+matB.mat[i][j];
            }
        }
        return result;
    }
};
int main(){
    // cout << "SHIVAM SINGH\n07313302720\nCSE-4A\n";
    cout << "Enter the no of rows and cols in mattrix 1: ";
    int rowsOne{},colsOne{}; cin >> rowsOne >> colsOne;
    cout << "Enter the no cols in matrix 2: ";
    int colsTwo{}; cin >> colsTwo;
    matrix a(rowsOne,colsOne);
    matrix b(colsOne,colsTwo);
    a.fillArray();
    b.fillArray();
    a.printArray();
    b.printArray();
    matrix resultMultiplicaton = a*b;
    matrix resultAddition = a+b;
    cout << "The result of matrix multiplication is given below\n";
    resultMultiplicaton.printArray();
    cout << "The result of matrix Addition is given below\n";
    resultAddition.printArray();
    cout << "The reuslt of matrix Transpose is given below\n";
    matrix tposeA(a.rows,a.cols);
    for(int i = 0 ; i < a.rows ; i++){
        for(int j = 0 ; j < a.cols ; j++){
            tposeA.mat[j][i] = a.mat[i][j];
        }
    }
    tposeA.printArray();
    matrix tposeB(b.rows, b.cols);
    for(int i = 0 ; i < b.rows ; i++){
        for(int j = 0 ; j < b.cols ; j++){
            tposeB.mat[j][i] = b.mat[i][j];
        }
    }
    tposeB.printArray();
    return 0;
}
