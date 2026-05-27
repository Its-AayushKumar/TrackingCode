#include <iostream>
#include <string>
using namespace std;

class Teacher
{
private:
    double salary;

public:
    // Non Parameterized constructor
    Teacher()
    {
        cout << "Hi I am constructor!!" << endl;
        dept = "CS";
    }
    // Properties /attributes
    string name;
    string dept;
    string subjects;

    // Parameterized
    Teacher(string name, string d, string s, double sal)
    {
        this->name = name; // Here this->name is the property of object
        dept = d;
        subjects = s;
        salary = sal;
    }

    // copy constructor
    Teacher(Teacher &orgobj)
    {
        cout << "I am custom copy costructor" << endl;
        this->name = orgobj.name;
        this->dept = orgobj.dept;
    }
    // Methods / member functions
    void changeDept(string newDept)
    {
        dept = newDept;
    }

    // Setter
    void setSalary(double s)
    {
        salary = s;
    }

    // Getter
    double getSalary()
    {
        return salary;
    }

    void getInfo()
    {
        cout << "Name:" << name << endl;
        cout << "Dept:" << dept << endl;
    }
};

class Student
{
public:
    string name;
    int rollNo;
    int age;
};

class Account
{

private:
    double balance;
    string password;

public:
    string accounts;
    string username;
};
int main()
{
    // Teacher t1;
    // Teacher t2;

    // t1.name = "Aayush";
    // t1.dept = "CSBS";
    // t1.setSalary(25000);

    // cout << "Salary-" << t1.getSalary() << endl;
    // cout << t1.name << endl;
    // cout << t2.dept;

    Teacher t1("Aayush", "CS", "C++", 2500);
    // t1.getInfo();

    Teacher t2(t1); // custom copy constructor
    t2.getInfo();
    return 0;
}