// 198 ¥Úº“ΩŸ…· 
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        else if(nums.size()==1)
            return nums[0];
        else if(nums.size()==2)
            return max(nums[0], nums[1]);
        vector<int> steal = {nums[0], max(nums[0],nums[1])};
        for(int i = 2; i < nums.size(); ++i)
        {
            steal.push_back(max(nums[i]+steal[i-2], steal[i-1]));
        }
        return steal[nums.size()-1];
    }
};
