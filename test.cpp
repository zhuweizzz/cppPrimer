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
#include <forward_list>
#include <algorithm>


using namespace std;


int main()
{
    vector<string> lc(12, "bca");
    vector<const char*> lc2(12, "bc");
    cout << equal(lc.cbegin(), lc.cend(), lc2.cbegin()) << endl;//#1 输出0

    vector<const char*> lc3(12, "bca");
    vector<const char*> lc4(12, "bca");
    cout << equal(lc3.cbegin(), lc3.cend(), lc4.cbegin()) << endl;//#2 输出1

    cout<< typeid(*lc3.begin()).name()<<endl;//#3 char const *

    cout<< (*lc3.begin()==*lc4.begin())<<endl;//# 4编译通过  输出1

    system("pause");

    return 0;
} 