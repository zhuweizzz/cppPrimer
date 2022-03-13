#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
    public:
        vector<int> containsDuplicate(vector<int>& nums,int target)
        {
            vector<int> res;
            unordered_map<int,int> temp;
            int index=0;
            for(const auto num : nums)
            {
                if(temp.find(target-num) == temp.end())
                {
                    temp.insert(make_pair(num,index));  // {key, value}
                }
                else
                {
                    res.push_back(temp.find(target-num)->second);
                    res.push_back(index);
                }
                index++;
            }
            return res;
        }
};

int main()
{
    Solution S1;
    vector<int> nums{2,7,11,15};
    int target=  9;
    vector<int> res = S1.containsDuplicate(nums,target);
    cout <<'['<< res[0] <<','<< res[1] <<']'<< endl;

    system("pause");
    
}