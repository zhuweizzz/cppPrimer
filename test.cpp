#include <iostream>
#include <string>
#include <windows.h>
#include <cctype>
#include <typeinfo>
#include <vector> 
#include <iterator>

using namespace std;


int main()
{
    vector<int> nums = {1,2,3,4,5,6,7};
    int k=3;
    int index = 0;
    int t;
    int temp = nums[index];
    if((!nums.empty()) && k!=0)
    {
        do
        {
            index += k;
            while(index > (nums.size()-1))
            {
                index = index - nums.size();
            }
            t = nums[index];
            nums[index]  = temp;
            temp = t;
        }while(index!=0);
    }
} 