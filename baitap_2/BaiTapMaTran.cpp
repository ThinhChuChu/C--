#include <iostream>
using namespace std;
class Matrix { 
    private: 
        int size;
        int** matrix = NULL;
    public:
        Matrix(){
            cout << "Nhap cap ma tran: ";
            cin >> size;
            matrix = new int*[size];
            for ( int i =0;i <size; i++){
                matrix[i] = new int[size];
            }
        }
        void input(){
            for ( int i =0; i < size; i++ ) {
                for ( int j =0; j < size; j++ ){
                    cout << "Nhap phan tu thu[" << i+1 << "][" << j+1 << "]: ";
                    cin >> matrix[i][j];
                }
            }
        }
        void output(){
            for ( int i =0; i < size; i++ ) {
                for ( int j =0; j < size; j++ ){
                    cout << matrix[i][j] << ' ';
                }
                cout << endl;
            }
        }
        void sum(){
            int sumMain = 0;
            int sumSub = 0;
             int j=size-1;
            for ( int i =0; i < size; i++ ) {
                sumSub += matrix[i][j];
                sumMain += matrix[i][i];
                j--;
            }
            cout << "\nTong duong cheo chinh = " << sumMain;
            cout << "\nTong duong cheo phu = " << sumSub;

        }
        ~Matrix(){
            for ( int i =0; i < size; i++ ){
                delete[] matrix[i];
            }
            delete[] matrix;
        }
};

int main() {
    Matrix m1;
    m1.input();
    Matrix m2;
    m2.input();
    m1.output();
    m2.output();
    m1.sum();
}
