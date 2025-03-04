class Solution {
public:
    void solve(int index,int target,vector<int>temp,vector<int>dict,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(index==dict.size()){
            return;
        }
        if(dict[index]<=target){
            temp.push_back(dict[index]);
            solve(index,target - dict[index],temp,dict,ans);
            temp.pop_back();
        }
        solve(index+1,target,temp,dict,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates,int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, target, temp, candidates, ans);
        return ans;
    }
};