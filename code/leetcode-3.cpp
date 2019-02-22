class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        int lo = 0, hi = 1,max = hi - lo;
        bool flag = false;
        while(hi < s.size())
        {
            for(int i = lo; i < hi; ++i)
            {
                if (s[i]==s[hi])
                {
                    lo = i+1;
                    if (lo>=hi)
                        hi = lo + 1;
                    i = hi - 1;
                    flag = false;
                }
                else
                    flag = true;
            }
            if (flag)
            {
                ++hi;
                if (hi-lo>max)
                    max = hi - lo;
            }
            
        }
        return max;
    }
};
// 从头开始寻找第一个没有重复字符的子串，其位置为[lo,hi-1]
// 当下一个字符与字串中位置为j的字符重复时，令lo=j+1，即重复字符的下一个字符，此时[lo,hi-1]中的子串是没有重复字符的
// 重复上述步骤，直到找到最长的子串 
