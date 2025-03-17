class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        // The problem starts from n=3
        if(n<3)
          return 0;
          
        // When n>=3
        int sum = 0;
        int pre[n];
        int post[n];
        pre[0]=height[0];
        post[n-1]=height[n-1];
        
        // Calculating pre:
        for(int i=1;i<n;i++)
          pre[i] = max(pre[i-1],height[i]);
          
        // Calculating post:
        for(int j=n-2;j>=0;j--)
          post[j] = max(post[j+1],height[j]);
          
        // Water calculation:
        for(int k=1;k<=n-2;k++)
          sum += min(pre[k],post[k]) - height[k];
        return sum;
    }
};