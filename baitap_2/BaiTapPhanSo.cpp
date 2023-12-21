#include<iostream>
#include<string>

using namespace std;

// common diviser
int getGCD(int a, int b){ 
        if (a <= b && (b % a == 0)) {
            return a;
        }
        else if (b < a) {
            return getGCD(b, a);
        }
        else {
            return getGCD(a, b % a);
        }
};
class PS1 {
    private:
        int numer;
        int denom;
    public:
	PS1(): numer(0), denom(1) {}
	PS1(int a, int b): numer(a), denom(b) {}
    
    // Hàm nhập
    void input(){
        // int a,b;
        cout << "Nhap tu so: "; cin >> numer;  
        do { 
            cout << "Nhap mau so: ";
            cin >> denom;
        } while (denom == 0);

        // if (a != 0){
        //     int gcd = getGCD(abs(a), abs(b));

        //     if (b < 0) { 
        //         numer = -(a / gcd);
        //         denom = -(b / gcd);
        //     }
        //     else {
        //         numer = a / gcd;
        //         denom = b / gcd;
        //     }
        // } else {
        //     numer = 0;
        //     denom = b;
        // }
    };
    //Hàm xuất
    void display(){
        if (numer == 0) cout << 0;
        else if ( numer % denom == 0) cout << numer/denom;
        else cout << numer << "/" << denom;
    }
	// Getters
	int getN() const { return numer; }
	int getD() const { return denom; }
    //Setters
    void setN(int a){
        numer = a;
    }
    void setD(int a){
        denom = a;
    }
    PS1 simplify(){
        if (numer == 0) return *this;
        int gcd = getGCD(abs(numer), abs(denom));

        if (denom < 0) { 
            numer = -(numer / gcd);
            denom = -(denom / gcd);
        }
        else {            
            numer = numer / gcd;
            denom = denom / gcd;
        }
        return *this;
    }
};

class PS2 : public PS1 {
    public:
        PS2(): PS1() {}
        PS2(int a, int b): PS1(a,b) {}
        // phép gán
        PS2& operator=(const PS2& other) {
            setN(other.getN());
            setD(other.getD());
            return *this;
        }
        //phép cộng
        PS2 operator+(const PS2& other) {
            if (getD() == other.getD()) {
                return PS2(getN() + other.getN(), getD());
                }
            else {
                return PS2((getN()*other.getD()) + (getD()*other.getN()), (getD()*other.getD()));
                }
        }
        PS2 operator+=(const PS2& other) {
            setN((getN() * other.getD()) + (other.getN() * getD()));
            setD(getD() * other.getD());
            return *this;
        }
        
        //phep so sánh
        bool operator>(const PS2& other) {
            // return ((getN() * other.getD()) > (other.getN() * getD()));
            return ((getN() * other.getD()) > (other.getN() * getD()));
        }

        bool operator<(const PS2& other) {
            return ((getN() * other.getD()) < (other.getN() * getD()));
        }
};
void printList(PS2* list,int size){
    for (int i = 0; i < size; ++i) {
        
        list[i].display();
        cout << " | ";
    }
}
void sortDesc(PS2* list, int size){
    for (int i = 0; i < size-1; ++i) {
        for (int j=i+1 ; j < size; ++j) {
            if (list[i]<list[j]) swap(list[i],list[j]);
        }
    }
}

void findMinMax(PS2* list,int size){
    PS2 min = list[0];
    PS2 max = list[0];

    for (int i = 0; i < size; ++i) {
        if ( list[i] > max ) max = list[i];
        if ( list[i] < min ) min = list[i];
    
    }
    cout << "\nPhan so lon nhat: "; max.display();
    cout << "\nPhan so nho nhat: "; min.display();
}
void sum1_2(PS2* list,int size){
    // PS2 cdt(1,2);
    PS2 sum;
    for (int i = 0; i < size; ++i) {
        if(list[i] < PS2(1,2) ) sum += list[i];
    }
    cout << "\nTong phan so < 1/2: ";
    sum.simplify().display();
}
void sum1_4(PS2* list,int size){
    // PS2 cdt(1,4);
    PS2 sum;
    for (int i = 0; i < size; ++i) {
        if(list[i] > PS2(1,4) ) sum += list[i];
    }
    cout << "\nTong phan so > 1/4: ";
    sum.simplify().display();
}
int main(){
    PS2* list=NULL;
    int size;
    cout << "Nhap so phan tu: ";
    cin >> size;
    list = new PS2[size];
    for (int i = 0; i < size; ++i) {
        cout << "Nhap phan so thu " << i+1 << '\n';
        list[i].input();
    }
    sortDesc(list, size);
    cout << "Danh sach phan so theo thu tu giam dan:\n";
    printList(list, size);
    findMinMax(list, size);
    sum1_2(list, size);
    sum1_4(list, size);
}
