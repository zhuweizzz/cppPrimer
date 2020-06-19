#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    int currVal=0, val=0;

    const int &r1=currVal;
   

    if(cin>>currVal){
        int cnt =1;
        while(cin>>val)
        {
            if(val == currVal)
                cnt++;
            else
            {
                cout << currVal << endl;
            }
            
        }
    }

    system("pause");

    return 0;
}