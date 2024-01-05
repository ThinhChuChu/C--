#include<iostream>
using namespace std;

class DaThuc {
    int bac;
    int* heso;

public:
    DaThuc(): bac(0), heso(NULL) {}
    DaThuc(int bac) {
        this->bac = bac;
        heso = new int[bac+1];
    }

    void nhap() {
        cout << "Nhap bac da thuc:";
        cin >> bac;
        heso = new int[bac+1];
        cout << "Nhập hệ số của đa thức từ bậc cao nhất đến bậc thấp nhất:\n";
        for(int i = bac; i >= 0; i--) {
            cin >> heso[i];
        }
    }

    void xuat() {
        cout << heso[bac] << "x^" << bac;
        for(int i = bac-1; i > 0; i--) {
            (heso[i] > 0)
                ? cout << " + " << heso[i] << "x^" << i 
                : cout << " - " << -heso[i] << "x^" << i ;
        }
        (heso[0] > 0) ? cout << "+" << heso[0]
                      : cout << heso[0];
    }

    DaThuc operator+(DaThuc const &obj) {
        int maxBac = max(this->bac, obj.bac);
        DaThuc tong(maxBac);

        for(int i = 0; i <= maxBac; i++) {
            tong.heso[i] = (i <= this->bac ? this->heso[i] : 0) + (i <= obj.bac ? obj.heso[i] : 0);
        }

        return tong;
    }

    DaThuc operator-(DaThuc const &obj) {
        int maxBac = max(this->bac, obj.bac);
        DaThuc hieu(maxBac);

        for(int i = 0; i <= maxBac; i++) {
            hieu.heso[i] = (i <= this->bac ? this->heso[i] : 0) - (i <= obj.bac ? obj.heso[i] : 0);
        }

        return hieu;
    }
    ~DaThuc(){
        delete[] heso;
    }
};
int main(){
    DaThuc a;
    a.nhap();
    a.xuat();
}
