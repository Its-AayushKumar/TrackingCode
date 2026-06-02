#include<iostream>
using namespace std;

class Student{
public:
string name;

Student(){
    cout<<"non-parameterized\n";
}

Student(string name){
    this->name = name;
    cout<<"parameterized\n";
}


};

int main()
{
    // Student s1;
    // s1.name = "Panda"
    
    Student s1("Panda");

    
    return 0;
}