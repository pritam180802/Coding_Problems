class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int breakpoint = -1;
        // Finding Breakpoint
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1]){
                breakpoint = i;
                break;
            }
               
        }
        // Checking whether there is any breakpoint or not!!!
        if(breakpoint == -1)
        {
            reverse(nums.begin(),nums.end()); // If there is no breakpoint
            return;
        }
        //If the breakpoint found !!!
        int j;
        for(j=n-1;j>breakpoint;j--)
        {
            if(nums[j]>nums[breakpoint])
              break;
        }
        swap(nums[j],nums[breakpoint]);
        reverse(nums.begin()+breakpoint+1,nums.end());
        return;
    }
};