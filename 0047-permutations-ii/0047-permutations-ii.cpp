class Solution {
public:
     bool isPresent(int val,vector<int>dict){
        for(auto ele:dict){
            if(ele==val)
            return true;
        }
        return false;
    }
    void solve(int index,vector<int> nums,vector<vector<int>>&ans){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        vector<int>dict;
        for(int i=index;i<nums.size();i++){
            if(index==i){
                solve(index+1,nums,ans);
                continue;
            }
            if(nums[index]!=nums[i]){
                if(isPresent(nums[i],dict))
                continue;
                swap(nums[index],nums[i]);
                solve(index+1,nums,ans);
                swap(nums[index],nums[i]);
                dict.push_back(nums[i]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0,nums,ans);
        return ans;
    }
};