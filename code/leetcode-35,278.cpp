//35 ��������λ�� 

//���ֲ�ͬ��ʽ�Ķ��ֲ��� 
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int lo = 0;
        int high = nums.size();  
        int mid = (high - lo)/2;
        while (lo != high)
        {
            if (target>nums[mid])
            {
                lo = mid + 1;
            }
            else
            {
                high = mid;
            }
            mid = lo + (high - lo)/2;
        }
        return lo;
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int lo = 0;
        int high = nums.size();
        int mid = (high - lo)/2;
        while (lo != high)
        {
            if (target>nums[mid])
            {
                lo = mid + 1;
            }
            else if(target<nums[mid])
            {
                high = mid;
            }
            else
            {
                return mid;
            }
            mid = lo + (high - lo)/2;
        }
        return lo;
    }
};

//278 ��һ������İ汾
 
//ע�⵱n�ر��ʱҪ��ֹ��� 
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1;
        int high = n ;
        int mid = (high - lo)/2;
        while (lo != high)
        {
            if (isBadVersion(mid))
            {
                if(mid>0 && isBadVersion(mid-1))
                {
                    high = mid;
                }
                else if(mid>0 && !isBadVersion(mid-1))
                {
                    return mid;
                }

            }
            else 
            {
                if(mid<n && !isBadVersion(mid+1))
                {
                    lo = mid + 1;
                }
                else if(mid<n && isBadVersion(mid+1))
                {
                    return mid+1;
                }

            }
            mid = lo + (high - lo)/2;
        }
        return lo;
    }
}; 
