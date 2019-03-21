// 75-��ɫ����
// ��·���ţ������ݷ�ΪС�ڡ����ںʹ��� key ��������
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
