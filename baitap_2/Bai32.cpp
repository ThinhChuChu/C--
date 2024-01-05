#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

void tieude(){ 
	cout<<left << setw(4) << "STT"<<setw(15)<<"Dia chi nha"<<setw(25)<<"Ho ten"<<setw(20)<<"Tuoi"<<setw(18)<<"Nam sinh"<<setw(15)<<"Nghe nghiep"<<endl;
}
class People {
	protected:
        string name;	
        int age;
        int birth;
	    string job;
	public:
        void nhap(){
            cout<<"Nhap hoten: "; getline(cin >> ws,name);
            cout<<"Nhap tuoi: "; cin>>age;
            cout<<"Nam sinh: "; cin>>birth;
            cout<<"Nghe nghiep: "; getline(cin >> ws, job);
        }	
        //phuong thuc xuat
        void xuat(){
            cout<<left<<setw(25)<<name<<setw(20)<<age<<setw(18)<<birth<<setw(15)<<job<<endl;
        }
};

class House {
    protected: 
        People* member;
        int size;
        string address;
    public:
        House(): member(NULL), size(0), address("") {} 
        House(int size){
            this->size = size;
            member = new People[size];
        }
        void HouseIn(){
            cout << "Nhap so thanh vien trong nha: ";
            cin >> size;
            member = new People[size];
            cout << "Nhap dia chi nha: ";
            getline(cin >> ws, address);
            for (int i = 0; i < size; i++)
            {
                cout << "Nhap thong tin thanh vien thu " << i+1 << endl;
                member[i].nhap();
            }
        }
        void HousePr(){
            
            for (int i = 0; i < size; i++)
            {
                cout << left << setw(4) << i+1 << setw(15) << address;
                member[i].xuat();
            }
        }
        
};

class District{
    protected:
        House* nha;
        int house_count;
    public:
        District(): nha(NULL), house_count(0) {}
        District(int size){
            house_count = size;
            nha = new House[size];
        }
        void DistrictIn(){
            cout << "Nhap so ho dan:";
            cin >> house_count;
            nha = new House[house_count];
            for (int i = 0; i < house_count; i++)
            {
                cout << "Nhap thong tin ho dan thu " << i+1 << endl;
                nha[i].HouseIn();
            }
        }
        void DistrictPr(){
            system("cls");
            cout << "Khu pho co " << house_count << " ho dan\n";
            for (int i = 0; i < house_count; i++)
            {
                cout << "Thong tin ho dan thu " << i+1 << ":\n";
                tieude();
                nha[i].HousePr();
            }
            
        }
};


int main(){
	District a;
    a.DistrictIn();
    a.DistrictPr();	
}
