class Solution {
public:
    int first(vector<int>& nums, int target){
        int s = 0;
        int e = nums.size()-1;
        int ans = -1;
        
        while(s<=e){
            int mid = s + (e-s)/2;   // Equal to (s+e)/2
            if(nums[mid]==target)
            {
                e = mid-1;
                ans = mid;
            }
            else if(nums[mid]>target)
              e = mid-1;
            else
              s = mid+1;
        }
        return ans;
    }
    int last(vector<int>& nums, int target){
        int s = 0;
        int e = nums.size()-1;
        int ans = -1;
        
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid]==target)
            {
                s = mid+1;
                ans = mid;
            }
            else if(nums[mid]>target)
              e = mid-1;
            else
              s = mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(first(nums,target));
        ans.push_back(last(nums,target));
        return ans;
    }
};