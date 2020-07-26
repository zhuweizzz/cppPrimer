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


using namespace std;


int main()
{
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};

    list<int> vls(begin(ia),end(ia));
    vector<int> vvec(begin(ia),end(ia));

    auto beg = vls.begin();
    auto ite = vvec.begin();

    while(beg != vls.end())
    {
        if(*beg % 2)
        {
            beg = vls.erase(beg);
        }
        else
        {
            ++beg;
        }
    }

    while(ite !=vvec.end())
    {
        if(*ite % 2)
        {
            ite++;
        }
        else
        {
            ite = vvec.erase(ite);
        }
    }


    for(auto &t : vls)
        cout << t <<endl;

    for(auto &t : vvec)
        cout << t <<endl;

    system("pause");

    return 0;
} 