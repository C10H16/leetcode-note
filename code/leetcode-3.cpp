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
// ��ͷ��ʼѰ�ҵ�һ��û���ظ��ַ����Ӵ�����λ��Ϊ[lo,hi-1]
// ����һ���ַ����ִ���λ��Ϊj���ַ��ظ�ʱ����lo=j+1�����ظ��ַ�����һ���ַ�����ʱ[lo,hi-1]�е��Ӵ���û���ظ��ַ���
// �ظ��������裬ֱ���ҵ�����Ӵ� 
