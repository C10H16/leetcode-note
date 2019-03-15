// 121 买卖股票的最佳时机
第i天的最大利润=max(前i-1天的最大利润，当天价格减去前i-1天最小价格) 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()<2)
            return 0;
        vector<int> re;
        int i,min = prices[0];
        re.push_back(0);
        for(i = 1; i < prices.size(); ++i)
        {
            if (prices[i-1]<min)
                min = prices[i-1];
            re.push_back(max(prices[i]-min,re[i-1]));
        }
        return re.back();
    }
};
