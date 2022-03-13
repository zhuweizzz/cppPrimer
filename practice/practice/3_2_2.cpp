#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <Windows.h>

using namespace std;

int main()
{
    vector<vector<int> > ivec;
    vector<int>::size_type;
    vector<int>::iterator it; // vector<int>的迭代器类型

    string str("some string");
    for (auto &c : str)
        c = toupper(c);
    cout << str << endl;

    system("pause");
}