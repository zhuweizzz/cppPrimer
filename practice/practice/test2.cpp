#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int main()
{
    vector<int> nums = {-1 , -100 , 3 , 99};
    int k = 2;

    if( k==0 || nums.size() <= 1 )
        return 0;

    k = k % nums.size();

    int curren=0;
    int next=0;
    int temp = 0;
    int count = 0;

    for(int start = 0; count < nums.size() ; ++start)
    {
        curren = start;
        do{
            temp = nums[curren];
            next = (curren + k) % nums.size();
            swap(temp , nums[next]);
            curren = next;
            count++;
        }while(curren != start);
        } 

    for(auto a : nums)
        cout << a << " "; 

    system("pause");

    return 0;
}