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
#include <map>
#include <set>
#include <utility>


using namespace std;


int main()
{
    vector<string> v1={"a","b","c","d","e"};
    vector<int> v2={1,2,3,4,5};

    vector<pair<string,int>> v3;
    
    pair<string,int> p;

    for(decltype(v1.size()) i=0 ; i != v1.size() ; ++i)
    {
        p.first = v1[i];
        p.second = v2[i];
        v3.push_back(p);
    }

    for(const auto &t : v3 )
    {
        cout << t.first << " " << t.second << endl;
    }

    system("pause");

    return 0;
} 