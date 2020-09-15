#include <iostream>
#include <windows.h>

using namespace std;

int main()
{

    string s = "00110011";

    int prevcont = 0;
    int count =0;
    int ans=0;
    char pre = '2';
    for(auto &t : s)
    {
        if( t != pre)
        {
            ans+= min( prevcont , count);
            prevcont = count;
            count = 1;
            pre = t;
        } 
        else
        {
            ++count;
        } 
    }

    ans += min(prevcont , count);

    cout << ans << endl;

    system("pause");

    return 0;
}

inline int min(int a , int b)
{
    return a<b ? a : b ;
}