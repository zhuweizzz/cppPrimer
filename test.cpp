#include <iostream>
#include <string>
#include <windows.h>
#include <cctype>
#include <typeinfo>

using namespace std;


int main()
{
    string s;
    char a='a';

    cout << typeid(a).name() << endl;

    system("pause");

    return 0;
}