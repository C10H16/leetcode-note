// 169 	������ 
// �򵥴ֱ���ͳ�� 
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

// �ο������˵Ĵ���
// ��һ�ַ���
// ��Ϊ����һ�������ҳ��� nums.size()/2, 
// �������ĸ�����ȥ������ͬ���ֵĸ���һ������ 0 
// ��һ����Ϊ��׼��������ͬ���������� 1��������ͬ����������1
// ����ʹ�ü������� 0 ����һ��Ϊ���� 
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
