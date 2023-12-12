#include<bits/stdc++.h>
#include "students.hpp"

using namespace std;

class GraduateStudent : public Student::Student {
private:
    bool fullTime;
public:

    GraduateStudent(string studentName, double tuitionFees, double Fine, bool isFullTime)
        : Student::Student(studentName, Fine, tuitionFees), fullTime(isFullTime) {}

        
    bool isFullTimeGraduate() const {
        return fullTime;
    }

};