#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string s;
    
    long long count = 0;
    int sta = 0; //0为小写 1为大写
    cin >> s;

    for(auto &t : s)
    {
        auto s = isupper(t);
        if(sta != s )
        {
            sta = s;
            ++count;
        }
        ++count;
    } 
    
    cout << count << endl;

    system("pause");

    return 0;
}