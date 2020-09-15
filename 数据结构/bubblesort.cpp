#include <iostream>

using namespace std;

int main()
{
    
    return 0;
}

void bublesort( int A[] , int n) //对n个数的数组排序 冒泡排序
{
    bool sorted = false;
    while( !sorted )
    {
        sorted = true;
        for( int i = 1; i < n ; i++)
        {
            if( A[i-1] > A[i] )
            {
                swap( A[i-1] , A[i]);
                sorted = false;
            }
        }
        --n;
    }
}