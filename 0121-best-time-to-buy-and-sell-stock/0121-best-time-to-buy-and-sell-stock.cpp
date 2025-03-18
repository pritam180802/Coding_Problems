class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mintillnow = INT_MAX;
        int maxprofit = INT_MIN;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<mintillnow)
              mintillnow = prices[i];
            if(prices[i]-mintillnow > maxprofit)
              maxprofit = prices[i]-mintillnow;
        }
        return maxprofit;
    }
};