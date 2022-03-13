#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        int containsDuplicate(vector<int>& nums)
        {
            int pre_sum = 0, now_sum = 0, max_sum = nums[0];
            for(auto num : nums)
            {
                now_sum = pre_sum + num;
                if(now_sum > 0)
                {
                    pre_sum = now_sum;
                }
                else
                {
                    pre_sum = 0;
                }
                if(now_sum > max_sum)
                    max_sum = now_sum;
            }
            return max_sum;
        }
};

int main()
{
    Solution S1;
    vector<int> nums{-2,-1};
    int res = S1.containsDuplicate(nums);
    cout << res << endl;

    system("pause");
    
}