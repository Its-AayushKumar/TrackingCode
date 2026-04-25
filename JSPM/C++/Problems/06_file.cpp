#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string text;
    ofstream outfile("demo.txt");
    cout << "Enter Text : ";
    getline(cin, text);
    outfile << text;

    outfile.close();

    string content;
    ifstream infile("demo.txt");
    getline(infile, content);
    cout << "Content of file : " << content;

    infile.close();

    return 0;
}