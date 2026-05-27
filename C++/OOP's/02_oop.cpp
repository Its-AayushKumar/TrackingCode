#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    string name;
    double *cgpaptr;

    Student(string name, double cgpa)
    {
        this->name = name;
        cgpaptr = new double;
        *cgpaptr = cgpa;
    }

    Student(Student &obj)
    {
        this->name = obj.name;
        this->cgpaptr = obj.cgpaptr;
    }

    void getInfo()
    {
        cout << "Name:" << name << endl;
        cout << "CGPA:" << *cgpaptr << endl;
    }
};
int main()
{
    Student s1("Aayush", 9.4);
    // s1.getInfo();
    Student s2(s1);//              
    s2.getInfo();
    return 0;
}