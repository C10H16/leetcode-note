// 75-颜色分类
// 三路快排，将数据分为小于、等于和大于 key 的三部分
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int key = 1, lt = 0, gt = nums.size()-1;
        int i = 0;
        while (i <= gt)
        {
            if (nums[i]<key)
            {
                swap(nums[i],nums[lt]);
                ++i;
                ++lt;
            }
            else if (nums[i]>key)
            {
                swap(nums[i],nums[gt]);
                --gt;
            }
            else
                ++i;
        }
    }
}; 
