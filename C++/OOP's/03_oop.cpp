#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string name;
    int age;

    Person(string name, int age){
        this->name = name ;
        this->age = age;
    }

  
};

class Student : public Person
{
public:
    int rollno;

    Student(string name,int age,int rollno):Person(name,age){
        this->rollno = rollno;
    }

    void getInfo()
    {
        cout << "Name:" << name << endl;
        cout << "Age:" << age << endl;
        cout << "RollNo:" << rollno << endl;
    }
};

int main()
{
    // Student s1;
    // s1.name = "Aayush";
    // s1.age = 20;
    // s1.rollno = 45;

    Student s1("Aayu",23,45);
    s1.getInfo();
}