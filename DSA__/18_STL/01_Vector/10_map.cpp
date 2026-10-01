#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> m;

    m["tv"] = 10;
    m["laptop"] = 20;
    m["headphones"] = 50;

    m.insert({"Panda", 69});
    m.emplace("Mice", 69);

    m.erase("Mice");

    for (auto p : m)
    {
        cout << p.first << " " << p.second << endl;
    }

    cout << "count:" << m.count("tv") << endl;
    return 0;
}
// they are sorted in ascending order by default as here the key values are string its sorted lexicographically