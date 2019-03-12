// 70 爬楼梯
// 递归 会超时╮(╯-╰)╭ 

class Solution {
public:
    int climbStairs(int n) {
        if (n==1)
            return 1;
        else if (n==2)
            return 2;
        else
            return climbStairs(n-1)+climbStairs(n-2);
    }
};

// 迭代
class Solution {
public:
    int climbStairs(int n) {
        vector<int> re;
        re.push_back(0);
        re.push_back(1);
        re.push_back(2);
        for(int i = 3; i <= n; ++i)
            re.push_back(re[i-1]+re[i-2]);
        return re[n];
    }
};

// 看了评论发现，是斐波那契数列啊Σ(っ °Д °;)っ 
