// version 1 
// 有时候感觉自己的脑回路很神奇…… 
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

// 参考别人的代码修改的更简洁的版本 基本思路是一样的 
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
