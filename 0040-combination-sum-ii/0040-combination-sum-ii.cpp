class Solution {
public:
    void solve(int index,vector<int>&temp,int target,vector<int>&dict,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(index==dict.size()){
            return;
        }
        for(int i=index;i<dict.size();i++){

            if(i>index && dict[i]==dict[i-1])
            continue;

            if(dict[i]>target)
            break;
            
            temp.push_back(dict[i]);
            solve(i+1,temp,target-dict[i],dict,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        solve(0,temp,target,candidates,ans);
        return ans;
    }
};