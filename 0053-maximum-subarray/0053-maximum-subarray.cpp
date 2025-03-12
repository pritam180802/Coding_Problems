class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int c_sum = 0,sum = INT_MIN,n=nums.size();
        if(n==1)
          return nums[0];
        for(int i=0;i<n;i++)
        {
            c_sum += nums[i];
            sum = max(sum, c_sum);
            if (c_sum < 0) c_sum = 0;
        }
        return sum;
    }
};