#include<bits/stdc++.h>
using namespace std;


class Student {
private:
    double libraryFines;
public:
    string name;
    double tuitionFees;


    Student() : name(""), libraryFines(0.0), tuitionFees(0.0) {}
    Student(string studentName) : name(studentName), libraryFines(0.0), tuitionFees(0.0) {}
    Student(string studentName, double fines, double fees)
        : name(studentName), libraryFines(fines), tuitionFees(fees) {}

    double getTotalMoneyOwed()  {
        return libraryFines + tuitionFees;
    }
    void setLibraryFines(double fines) {
        if (fines >= 0.0) {
            libraryFines = fines;
        } 
    }

    double getLibraryFines() {
        return libraryFines;
    }
};

int main() {
    // Create Student objects using different constructors
    Student student1; // Default constructor
    Student student2("Alice"); // constructor with a name
    Student student3("Bob", 10.0, 1000.0); // constructor with a name, library fines, and tuition fees

    // Access and modify object properties
    student1.name = "Charlie";
    student1.setLibraryFines(5.0);
    student1.tuitionFees = 1500.0;

    // Display student information
cout << "Student 1: " << student1.name << " owes " << student1.getTotalMoneyOwed() <<endl;
cout << "Student 2: " << student2.name << " owes " << student2.getTotalMoneyOwed() <<endl;
cout << "Student 3: " << student3.name << " owes " << student3.getTotalMoneyOwed() <<endl;

    return 0;
}
