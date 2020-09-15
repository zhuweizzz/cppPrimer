#include <iostream>

using namespace std;

int main()
{

    return 0;
}

int sum(int A[] , int n)  //用递归求和
{
    if( n < 1 )
        return 0;
    else
        return sum( A , n-1) + A[n-1];
}



void reverse (int *A, int lo , int hi) //用递归实现数组倒置
{
    if( lo < hi )
    {
        swap(A[lo], A[hi]);
        reverse( A, lo + 1, hi - 1);
    }
}

// void reverse( int *A, n)
// {
//     reverse( A, 0 , n-1);
// }

//使用递归实现快速幂运算
//              power2(nk-1)^2 * 2;  bk == 1;
// power2(nk) = power2(nk-1)^2;      bk == 0;
inline __int64 sqr(__int64 a){ return a * a;}
__int64 power2( int n){
    if( n ==  0) 
        return 1;
    else
        return ( n & 1) ? sqr( power2( n >> 1 )) << 2 : sqr( power2( n >> 1 ));
}

//fibonacci数列 

__int64 fib( int n ){
    __int64 f = 1 , g = 0;
    while ( n-- > 0 )
    {
        g += f;
        f = g - f;
    }
    return g;
}