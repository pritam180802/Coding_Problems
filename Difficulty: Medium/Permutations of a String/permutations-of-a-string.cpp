//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    void solve(int index,set<string> &ans,string s){
        if(index == s.size()-1){
            ans.insert(s);
            return;
        }
        for(int i=index;i<s.size();i++){
            swap(s[index],s[i]);
            solve(index+1,ans,s);
            swap(s[index],s[i]);
        }
    }
    vector<string> findPermutation(string &s){
        set<string> ans;
        solve(0,ans,s);
        vector<string> a(ans.begin(),ans.end());
        return a;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends