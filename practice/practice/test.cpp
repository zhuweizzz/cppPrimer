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
    vector<int> v1;


    class Hasptr{
        public:

            ~Hasptr(){
                delete(ps);
            }

            Hasptr(const std::string &s = std::string()):
                ps(new std::string(s)) , i(0){}

            Hasptr(Hasptr &orig):
                ps(new std::string(*orig.ps)) , i(orig.i){}
            //拷贝构造函数
        private:
            std::string *ps;
            int i; 
    };

    int i;

    int &&i=42;

    
    system("pause");

    return 0;
} 