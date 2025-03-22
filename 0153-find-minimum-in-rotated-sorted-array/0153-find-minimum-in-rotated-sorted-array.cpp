class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        if(nums.size()==1)     // Handling single element!!!
        return nums[0];
        while((e-s) != 1){
            int mid = s + (e-s)/2;
            if(nums[mid] > nums[s])
              s = mid;
            else
              e = mid;
        }
        if(e==nums.size()-1 && nums[e]>nums[s]) // When no rotation performed & arr is sorted completely!!!
        return nums[0];
        return nums[e];
    }
};