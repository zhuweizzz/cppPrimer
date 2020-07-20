#include <iostream>
#include <string>
#include <windows.h>
#include <cctype>
#include <typeinfo>
#include <vector> 
#include <iterator>

using namespace std;


int main()
{
    string s("hello world");

    for (auto &c : s)
        c = toupper(c);

    cout << s << endl;



    system("pause");
    return 0;
}