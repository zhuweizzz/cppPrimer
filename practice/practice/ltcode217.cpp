#include <iostream>
#include <vector>
#include <unordered_set>  // 由哈希函数组织的set
#include <windows.h>

using namespace std;

class Solution{
    public:
        bool containsDuplicate(vector<int>& nums)
        {
            unordered_set<int> Temp;
            for(auto iter1 = nums.begin(); iter1 != nums.end() ; iter1++)
            {
                auto count = Temp.size();
                Temp.insert(*iter1);
                if(count != Temp.size())
                {
                    return false;
                }
            }
            return true;
        }
};

int main()
{
    Solution S1;
    vector<int> nums{1,2,3,1};
    bool res = S1.containsDuplicate(nums);
    cout << res << endl;

    system("pause");
    
}
