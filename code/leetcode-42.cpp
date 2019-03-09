// 42 Ω””ÍÀÆ 
class Solution {
public:
    int trap(vector<int>& height) {
        int re = 0,temp = 0;
        int level = 0;
        vector<int> leftMax(height.size());
        vector<int> rightMax(height.size());
        for(int i = 1; i < height.size();++i)
        {
            leftMax[i] = max(leftMax[i-1],height[i-1]);
        }
        for (int i = height.size()-2;i>=0;--i)
        {
            rightMax[i] = max(rightMax[i+1],height[i+1]);
        }
        for(int i = 0; i < height.size();++i)
        {
            level = min(leftMax[i],rightMax[i]);   
            re += max(0,level-height[i]);   
        }
        return re;
    }
};
