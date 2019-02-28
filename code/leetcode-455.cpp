// version 1 
// ��ʱ��о��Լ����Ի�·�����桭�� 
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int j = 0,re = 0;
        for(int i = 0; i < g.size(); ++i)
        {
            if(j>=s.size())
                return re;
            while(s[j]<g[i])
            {
                ++j;
                if(j>=s.size())
                    return re;
            }
            ++re;
            ++j;
            
        }
       return re;
    }
};

// �ο����˵Ĵ����޸ĵĸ����İ汾 ����˼·��һ���� 
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i = 0, j = 0, re = 0;
        while(i<g.size()&&j<s.size())
        {
            if(g[i]<=s[j])
            {
                ++i;
                ++j;
                ++re;
            }
            else
            {
                ++j;
            }
        }
        return re;
    }
};
