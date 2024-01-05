#include<iostream>
using namespace std;

class da_thuc {
    private:
        int bac;
        float *heso;

    public: 
        void nhap() {
            do {
                cout << "nhap he so cua da thuc: ";
                cin >> bac;
            } while (bac < 1);
            heso = new float[bac + 1];
            for (int i = 0; i <= bac; i++) {
                cout << "nhap he so da thuc " << i << ": ";
                cin >> heso[i];
            }
            cout << "__________________xong_______________"<<endl;
        }

        void xuat() {
            for (int i = 0; i <= bac; i++) {
                if (i == 0) { 
                    cout << heso[i];// in voi truong hop x^0 
                } else {
                    if (heso[i] >= 0)  cout << " + "; else cout << " ";   
                    cout  << heso[i] << ".x^" << i;  
                }
            }
            cout << endl;
        }

        friend da_thuc operator+(da_thuc a, da_thuc b);

        friend da_thuc operator-(da_thuc a, da_thuc b);
};
//xay dung ham tinh tong 
da_thuc operator+(da_thuc a,da_thuc b)  {
        da_thuc tong;
        tong.bac = max(b.bac, a.bac); // bac cua tong se la bac lon nhat  giua bac cua a va b
        tong.heso = new float[tong.bac + 1];
        for (int i = 0; i <= tong.bac; i++) {
           if(i <= a.bac && i <= b.bac){
            tong.heso[i] = a.heso[i] + b.heso[i];
           }
           else if(i <= b.bac){ 
                tong.heso[i] = b.heso[i];
           }
           else if(i <= a.bac){ 
                tong.heso[i] = a.heso[i];
           }
        }

        return tong;
    }
//xay dung ham tinh hieu
da_thuc operator-(da_thuc a, da_thuc b) {
        da_thuc hieu;
        hieu.bac = max(b.bac, a.bac); // bac cua tong se la bac lon nhat  giua bac cua a va b
        hieu.heso = new float[hieu.bac + 1];
        for (int i = 0; i <= hieu.bac; i++) {
            if(i <= a.bac || i <= b.bac){
            hieu.heso[i] = a.heso[i] - b.heso[i];
           }
           else if(i <= b.bac){ 
                hieu.heso[i] = b.heso[i];
           }
           else if(i <= a.bac){ 
                hieu.heso[i] = a.heso[i];
           }
        }

        return hieu;
    }
int main() {
    system("color F0"); // nen trang chu den 
    da_thuc a, b, tong, hieu;
    a.nhap();
    b.nhap();
    system("cls");
    tong = a + b;
    hieu = a - b;
    cout << "Đa thức A: ";
    a.xuat();
    cout << "Đa thức B: ";
    b.xuat();
    cout << "Tổng A va B : ";
    tong.xuat();
    cout << "Hiệu cua A va B: ";
    hieu.xuat();

    system("pause");
    return 0;
}
