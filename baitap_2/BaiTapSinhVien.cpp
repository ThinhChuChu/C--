#include <iostream>
#include <vector>
// #include <limits> 
// #include <algorithm> 

class Person {
private:
    std::string name;
    std::string birth;

public:
    Person() : name(""), birth("") {}
    Person(const std::string& n, const std::string& b) : name(n), birth(b) {}

    std::string getName() const {
        return name;
    }

    std::string getBirth() const {
        return birth;
    }

    void setName(const std::string& n) {
        name = n;
    }

    void setBirth(const std::string& b) {
        birth = b;
    }

    void displayInfo() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Birthdate: " << birth << std::endl;
    }
};

class Student : public Person {
private:
    int studentID;
    double gpa;

public:
    Student() : studentID(0), gpa(0) {}
    Student(const std::string& n, const std::string& b, int id, double g)
        : Person(n, b), studentID(id), gpa(g) {}

    // Student(const std::string& n, const std::string& b, int id, double g, const std::string& studentName, const std::string& studentBirth)
    //     : Person(studentName, studentBirth), studentID(id), gpa(g) {}

    int getStudentID() const {
        return studentID;
    }

    double getGPA() const {
        return gpa;
    }

    void inputStudentInfo() {
        std::cout << "Enter student ID: ";
        std::cin >> studentID;

        std::cout << "Enter GPA: ";
        std::cin >> gpa;

        std::cin.ignore();

        std::string studentName;
        std::cout << "Enter student name: ";
        std::getline(std::cin, studentName);
        setName(studentName);

        std::string studentBirth;
        std::cout << "Enter birthdate: ";
        std::getline(std::cin, studentBirth);
        setBirth(studentBirth);
    }

    void displayStudentInfo() const {
        displayInfo();
        std::cout << "Student ID: " << studentID << std::endl;
        std::cout << "GPA: " << gpa << std::endl;
    }
};

class StudentList {
private:
    Student* students;
    int n;
public:
    StudentList(){
        std::cout << "Nhap so sinh vien ";
        std::cin >> n;
        students = new Student[n];
        for (int i = 0; i < n; ++i) {
            std::cout << "Enter information for Student " << i + 1 << ":" << std::endl;
            students[i].inputStudentInfo();
        }
    }

    
    void printStudentList() const {
        std::cout << "Student List:" << std::endl;
        for (int i = 0; i < n; ++i) {
            students[i].displayStudentInfo();
            std::cout << "------------------------" << std::endl;
        }
    }

    Student findByName(std::string name){
        bool Found = false;
        std::cout << "Student found:\n";
        for (int i = 0; i < n; ++i) {
            if (students[i].getName() == name) {
                Found = true;
                students[i].displayStudentInfo();
            }
        }
        if (!Found) std::cout << "No student name: \"" << name << "\"\n";
    }
        
    
    // Student findStudentByName(const std::string& name) const {
    //     auto it = std::find_if(students, students + n, [&name](const Student& student) {
    //         return student.getName() == name;
    //     });

    //     return (it != students + n) ? *it : Student("", "", 0, 0.0); // Not found
    // }

    // Student findStudentByID(int id) const {
    //     auto it = std::find_if(students, students + n, [id](const Student& student) {
    //         return student.getStudentID() == id;
    //     });

    //     return (it != students + n) ? *it : Student("", "", 0, 0.0); // Not found
    // }
    Student findByID(int id){
        bool Found = false;
        std::cout << "Student found:\n";
        for (int i = 0; i < n; ++i) {
            if (students[i].getStudentID() == id) {
                Found = true;
                students[i].displayStudentInfo();
            }
        }
        if (!Found) std::cout << "No student id: \"" << id << "\"\n";
    }
};

int main() {
    StudentList studentList;

    
    studentList.printStudentList();

    std::string searchName;
    std::cin.clear();
    std::cout << "Enter the name of the student to find: ";
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, searchName);
    studentList.findByName(searchName);

    int searchID;
    std::cout << "Enter the ID of the student to find: ";
    std::cin >> searchID;
    studentList.findByID(searchID);



    return 0;
}
