class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mi = 1;
        int ma = 1;
        int ans = nums[0];
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                ma = max(nums[i],nums[i]*ma);
                mi = min(nums[i],nums[i]*mi);
                ans = max(ans,ma);
            }
            else if(nums[i]<0)
            {
                swap(mi,ma);
                ma = max(nums[i],nums[i]*ma);
                mi = min(nums[i],nums[i]*mi);
                ans = max(ans,ma);
            }
            else
            {
                mi = ma = 1;
                ans = max(ans,0);
            }
        }
        return ans;
    }
};