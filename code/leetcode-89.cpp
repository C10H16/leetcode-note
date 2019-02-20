// 自己的代码
/*
例如n=2时，格雷码为
00
01
10
11
n=3时，格雷码为
000
001
010
011
------ 
111
110
101
100 
即在n=2的基础上，将n=2的四个格雷码逆序排列，并与2的n次方相加，生成新的4个格雷码
n=4时，继续重复上面的操作生成新的格雷码…… 
*/
class Solution {
public:
    vector<int> grayCode(int n) {
        int size = (int)pow(2,n);
        vector<int> re(size);
        if (n==0)
            return re;
        int i = 0,j = 0,k = 0;
        for (int i = 0; i < n; i++)
        {
            for(j = (int)pow(2,i)-1, k = j+1; j >= 0 ; j--,k++)
            {
                    re[k] = re[j] + (int)pow(2,i);
            }
        }
        return re;
    }
};

// 一种更简单的方法 
// G(i) = i^(i/2) 
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for(int i=0; i<pow(2,n); ++i)
        {
            res.push_back((i>>1)^i);
        }
        return res;
        
    }
};
