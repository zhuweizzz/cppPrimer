#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

int main()
{
    int t;
    vector<int> v1;

    while(cin >> t)
    {
        v1.push_back(t);
    }

    auto beg = v1.begin();

    auto end = v1.end();

    --end;

    while( beg <= end )
    {
        cout<< *beg + *end <<endl;
        ++beg;
        --end;
    }
    
    system("pause");

    return 0;
}