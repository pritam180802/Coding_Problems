class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int pre[n];
        int post[n];
        pre[0]=nums[0];
        post[n-1]=nums[n-1];
        
        //Calculating pre:
        for(int i=1;i<n;i++)
          pre[i] = pre[i-1] * nums[i];
          
        // Calculating post:
        for(int j=n-2;j>=0;j--)
          post[j] = post[j+1] * nums[j];
        
        // Calculating the required array:
        for(int k=0;k<n;k++)
        {
            if(k==0)
              ans.push_back(post[1]);
            else if(k==n-1)
              ans.push_back(pre[n-2]);
            else
              ans.push_back(pre[k-1]*post[k+1]);
        }
        return ans;
    }
};