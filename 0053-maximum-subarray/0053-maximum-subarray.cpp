class Solution {
public:
    int maxSubArray(vector<int>& nums) {       // Kadane's Algorithm
        int c_sum = nums[0],sum = nums[0],n=nums.size();
        
        for(int i=1;i<n;i++)
        {
            if(c_sum>=0)
              c_sum += nums[i];
            else
              c_sum = nums[i];
            if(c_sum>sum)
              sum = c_sum;
        }
        return sum;
    }
};