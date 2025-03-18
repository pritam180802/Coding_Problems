class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mintillnow = INT_MAX;
        int maxprofit = INT_MIN;
        for(int i=0;i<prices.size();i++)
        {
            mintillnow = min(mintillnow , prices[i]);
            int profit = prices[i]-mintillnow ;
            maxprofit = max(maxprofit , profit);
        }
        return maxprofit;
    }
};