#include <iostream>
#include <string>
#include <iomanip>

class Subject {
private:
    std::string subject;
    float CC; 
    float KT; 
    float DT;  

public:
    //  ructor
    Subject(): subject(""), CC(0), KT(0), DT(0) {}
    Subject(std::string subj, float cc, float kt, float dt)
        : subject(subj), CC(cc), KT(kt), DT(dt) {}

    // Getter functions
    std::string getSubject()  {
        return subject;
    }

    float getCC()   {
        return CC;
    }

    float getKT()   {
        return KT;
    }

    float getDT()   {
        return DT;
    }

    // Setter functions
    void setSubject(  std::string& subj) {
        subject = subj;
    }

    void setCC(float cc) {
        CC = cc;
    }

    void setKT(float kt) {
        KT = kt;
    }

    void setDT(float dt) {
        DT = dt;
    }

    void inputStudentInfo() {
        
        std::getline(std::cin, subject);
        
        std::cout << "Nhap diem chuyen can: "; std::cin >> CC;
        std::cout << "Nhap diem kiem tra: "; std::cin >> KT;
        std::cout << "Nhap diem thi: "; std::cin >> DT;
    }
    // // Display function
    // void displaySubjectInfo()   {
    //     std::cout << "Subject: " << subject << std::endl;
    //     std::cout << "Continuous Assessment: " << CC << std::endl;
    //     std::cout << "Knowledge Test: " << KT << std::endl;
    //     std::cout << "Final Exam: " << DT << std::endl;
    // }
    void displaySubjectInfo()   {
    std::cout << std::setw(10) << std::left << subject
              << std::setw(11) << std::left << CC
              << std::setw(11) << std::left << KT
              << std::setw(10) << std::left << DT << std::endl;
}
};

class Student : public Subject {
private:
    std::string name;
    std::string className;
    std::string id;

public:
    //  ructor
    Student(): Subject("", 0, 0, 0), name(""), className(""), id("") {}
    Student(std::string subj, float cc, float kt, float dt, std::string n, std::string cls, std::string i)
        : Subject(subj, cc, kt, dt), name(n), className(cls), id(i) {}

    // Getter functions
    std::string getName()   {
        return name;
    }

    std::string getClassName()   {
        return className;
    }

    std::string getId()   {
        return id;
    }

    // Setter functions
    void setName(  std::string& n) {
        name = n;
    }

    void setClassName(  std::string& cls) {
        className = cls;
    }

    void setId(  std::string& i) {
        id = i;
    }
    void inputStudentInfo() {
        
        std::cout << "Nhap ten sinh vien: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Nhap ten lop: ";
        std::getline(std::cin, className);
        std::cout << "Nhap ma sinh vien: ";
        std::getline(std::cin, id);
        std::cout << "Nhap ten mon hoc: ";
        Subject::inputStudentInfo();
    }
    
    void displayStudentInfo()   {
        std::cout<< std::setw(20) << std::left << name
                << std::setw(10) << std::left << className
                << std::setw(15) << std::left << id;
        displaySubjectInfo();
    }
    
};

class StudentList {
private:
    Student* students;
    int n;
public:
    StudentList(){
        std::cout << "Nhap so sinh vien: ";
        std::cin >> n;
        students = new Student[n];
        for (int i = 0; i < n; ++i) {
            std::cout << "Sinh vien " << i + 1 << std::endl;
            students[i].inputStudentInfo();
        }
        system("cls");
    }
    void displayStudentList()   {
        for (int i = 0; i < n; ++i) {
            students[i].displayStudentInfo();
        }
    }
    void displayTable(){
        std::cout << "------------Danh Sach Sinh Vien--------------\n";
        std::cout<< std::setw(20) << std::left << "Ten"
                << std::setw(10) << std::left << "Lop"
                << std::setw(15) << std::left << "MaSV"
                << std::setw(10) << std::left << "Mon hoc"
                << std::setw(11) << std::left << "Chuyen can"
                << std::setw(11) << std::left << "Diem ktra"
                << std::setw(10) << std::left << "Diem thi" << std::endl;
    }
    void displayBanned(){
        bool Banned = false;
        std::cout << "Danh sach sinh vien bi cam thi:\n";
        displayTable();
        for (int i = 0; i < n; ++i){
            if (students[i].getCC() < 5 || students[i].getDT() == 0){
            Banned = true;
            students[i].displayStudentInfo();
            }
        }
        if (!Banned) std::cout << "Khong co sinh vien nao bi cam thi\n";
    }
};
int main() {
    // Example usage of the Student class
    StudentList stdlist;

    // Display student information
    stdlist.displayTable();
    stdlist.displayStudentList();
    stdlist.displayBanned();

    return 0;
}
