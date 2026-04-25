#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream source("first.txt");
    if (!source.is_open())
    {
        cout << "File not exist";
        return 0;
    }
    ofstream dest("sample.txt");
    string line;
    while (getline(source, line))
    {
        dest << line << endl;
    }
    source.close();
    dest.close();
    cout << "File copied success";

    return 0;
}