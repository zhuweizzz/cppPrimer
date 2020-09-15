#include <iostream>
#include <windows.h>

using namespace std;

inline int max( int x ,int y)
{
    return x>y ? x : y ;
}

int main()
{
    int a,b;
    int ma , mi;
    int ans;
    cin >> a >> b;

    mi = a + b;
    ma = max( a , b);
    mi -= ma;
    
    if( mi == ma )
    {
        ans == mi;
    }
    else
    {
        if( ma % mi == 0)
            ans == ma;
        else
        {
            int t = ma % mi;
            if( mi % t == 0 )
                ans = ma * (mi / t);
            else
            {
                ans = ma * mi;
            }   
        }
    }
    
    cout << ans << endl;

    system("pause");

    return 0;
}

