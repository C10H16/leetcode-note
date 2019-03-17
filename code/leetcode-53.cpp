// 53-最大子序和
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return NULL;
        int re = INT_MIN;
        int f_n = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            f_n = max(f_n+nums[i], nums[i]);
            re = max(f_n, re);
        }
        return re;
    }
}; 
