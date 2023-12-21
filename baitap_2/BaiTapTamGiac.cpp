#include <iostream>
#include <cmath>

using namespace std;
#define EPSILON  0.00001
class point{
private:
    float x, y;
public:
    void inPoint(){
        cout << "x: ";
        cin >> x;
        cout << "y: ";
        cin >> y;
    }
    void outPoint(){
        cout << "(" << x << ", " << y << ")";
    }
    double calcuDistance(point other){
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }
};
class triangle : public point {
private:
    point P1, P2, P3;
    float side1, side2, side3;
public:
    void inTri(){
        cout << "P1: " << endl;
        P1.inPoint();
        cout << "P2: " << endl;
        P2.inPoint();
        cout << "P3: " << endl;
        P3.inPoint();

    side1 = P1.calcuDistance(P2);
    side2 = P2.calcuDistance(P3);
    side3 = P3.calcuDistance(P1);
  
    }
    void outTri(){
        cout << "Point: ";
        P1.outPoint();
        cout << " ";
        P2.outPoint();
        cout << " ";
        P3.outPoint();
        cout << " ";
        cout << endl << "Side: ";
        cout << side1 << ", " << side2 << ", " << side3 << endl;
    }
    friend void check(triangle &T);
};
void check(triangle &T){
    float a = T.side1;
    float b = T.side2;
    float c = T.side3;
    if(a + b <= c || a + c <= b || b + c <= a) {
            cout << "3 điểm không tạo thành tam giác.\n";
        } else if(fabs(a -b) <= EPSILON && fabs(b - c) <= EPSILON) {
            cout << "deu.\n";
        } else if(a == b || b == c  || c == a) {
            if(fabs(a*a + b*b - c*c) < EPSILON || fabs(a*a + c*c - b*b) < EPSILON || fabs(b*b + c*c - a*a) < EPSILON){
            cout << "vuong Can";
        } else{
            cout << "can\n";
        }
        } else if(fabs(a*a + b*b - c*c) < EPSILON || fabs(a*a + c*c - b*b) < EPSILON || fabs(b*b + c*c - a*a) < EPSILON){
            cout << "vuong ";
        } else {
            cout << "thuong.\n";
        }
}
int main(){
    triangle T;
    T.inTri();
    T.outTri();
    check(T);
}
