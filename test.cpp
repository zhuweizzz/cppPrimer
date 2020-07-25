#include <iostream>
#include <string>
#include <windows.h>
#include <cctype>
#include <typeinfo>
#include <vector> 
#include <iterator>
#include <fstream>
#include <sstream>
#include <deque>
#include <list>
#include <array>


using namespace std;


int main()
{
    vector<string> v1;
    string s;

    list<char *> ls{"testchar"};

    v1.assign(ls.begin(),ls.end());

    for(auto const &t : v1)
        cout << t << endl;

    system("pause");

    return 0;
} 