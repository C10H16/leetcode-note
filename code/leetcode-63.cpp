// 63 ²»Í¬Â·¾¶¢ò 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<long long> > dp(obstacleGrid.size());
        int i, j;
        bool flag;
        for( i = 0; i < obstacleGrid.size(); ++i)
        {
            for(j = 0; j < obstacleGrid[i].size(); ++j)
                dp[i].push_back(0);
        }
        for( i = 0; i < obstacleGrid.size(); ++i)
        {
            flag = true;
            for( j = 0; j < obstacleGrid[0].size(); ++j)
            {
                if ((i==0||j==0)&&obstacleGrid[i][j]!= 1&&flag)
                {
                    if(j==0&&i!=0&&(obstacleGrid[i-1][j]==1||dp[i-1][j]==0))
                        dp[i][j] = 0;
                    else
                        dp[i][j] = 1;
                }
                else if (obstacleGrid[i][j] != 1&&j>0&&i>0)
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
                else
                {
                    flag = false;
                    dp[i][j] = 0;
                }
            }
        }
        return dp[i-1][j-1];
    }
};
