// 62 不同路径
// 可以将问题分解为从起点走到(m-1,n)和到(n,m-1)可能的结果。
// 递归超时 QAQ 
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1||n==1)
            return 1;
        else
        {
            return uniquePaths(m-1,n)+uniquePaths(m,n-1);
        }
        return 1;
    }
}; 


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > a(m);
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
                a[i].push_back(0);
        }
        for(int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n;++j)
            {
                if (i==0||j==0)
                    a[i][j] = 1;
                else
                    a[i][j] = a[i-1][j] + a[i][j-1];
            }
        }
        return a[m-1][n-1];
    }
};
