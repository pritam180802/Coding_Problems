//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    void solve(int index,vector<int> &arr, int target,vector<int>&temp,vector<vector<int>>&ans){
        
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        
        if(index == arr.size())
        return;
        
        for(int i=index ; i<arr.size();i++){
            
            if(arr[i]>target)
            break;
            
            if(i>index && arr[i]==arr[i-1])
            continue;
            
            temp.push_back(arr[i]);
            solve(i+1,arr,target-arr[i],temp,ans);
            temp.pop_back();
            
        }
        
        
    }
    vector<vector<int>> uniqueCombinations(vector<int> &arr, int target) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,arr,target,temp,ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        vector<vector<int>> ans = ob.uniqueCombinations(arr, sum);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            for (int i = 0; i < ans.size(); i++) {
                sort(ans[i].begin(), ans[i].end());
            }
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends