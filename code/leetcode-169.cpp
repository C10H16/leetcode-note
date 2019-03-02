// 169 	求众数 
// 简单粗暴的统计 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i= 0;
        map<int, int> countNum;
        for (i = 0; i < nums.size(); ++i)
        {
            if (countNum.count(nums[i]))
                countNum[nums[i]] += 1;
            else
                countNum[nums[i]] = 1;
            if (countNum[nums[i]] > nums.size()/2)
                return nums[i];
                
        }
        return nums[0];
    }
};

// 参考其他人的代码
// 另一种方法
// 因为众数一定存在且超过 nums.size()/2, 
// 则众数的个数减去其他不同数字的个数一定大于 0 
// 以一个数为基准，遇到相同的数计数加 1，遇到不同的数计数减1
// 最终使得计数大于 0 的数一定为众数 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int same = nums[0], sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (sum == 0)
                same = nums[i];
            if (same == nums[i])
                ++sum;
            else
                --sum;
        }
        return same;
    }
}; 
