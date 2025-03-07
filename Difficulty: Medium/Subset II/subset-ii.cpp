//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {

  public:
  
    void solve(int index,set<vector<int>>&dict,vector<int>& nums,vector<int>&temp,vector<vector<int>>&ans){
        
        if(index == nums.size()){
            if(dict.find(temp) == dict.end()){
                ans.push_back(temp);
                dict.insert(temp);
                return;
            }
            return;
        }
        
        solve(index+1,dict,nums,temp,ans);
        temp.push_back(nums[index]);
        solve(index+1,dict,nums,temp,ans);
        temp.pop_back();
    }
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        set<vector<int>>dict;
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,dict,nums,temp,ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends